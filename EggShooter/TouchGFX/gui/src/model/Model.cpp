#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h>
#include <main.h>
#include <stdio.h>
#include <cstring>

extern int8_t direction;
extern int8_t shoot;
extern UART_HandleTypeDef huart1;
const BitmapId eggIds[] = {
    BITMAP_GREEN_ID,
    BITMAP_RED_ID,
    BITMAP_YELLOW_ID,
    BITMAP_BROWN_ID,
    BITMAP_MIDNIGHT_ID,
    BITMAP_PURPLE_ID,
    BITMAP_BLACK_ID
};

const int eggCount = sizeof(eggIds) / sizeof(BitmapId);
int eggCurrentCount = 2;
int vr[6] = {-1, -1,  0, 0, 1, 1};
int vcEven[6] = {-1, 0, -1, 1, -1, 0};
int vcOdd[6]  = {0, 1, -1, 1, 0, 1};


Model::Model() : modelListener(0), counter(0), alfaGun(0), spawnedRowCount(0), paused(false), stage(0), highScore(0), currentScore(0)
{

    for (int r = 0; r < MAX_ROWS; ++r)
    {
        for (int c = 0; c < MAX_COLS; ++c)
        {
            eggMap[r][c] = { 0, false, 0, 0, false, 0};
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        spawnRow();
    }
}

void Model::tick()
{
if(paused)
return;
if (getNumRow() >= MAX_ROWS || (stage != 6 && getNumRow() == 0)){
if (modelListener)
  modelListener->onGameOver();
if(currentScore > highScore)
  highScore = currentScore;
}
if (modelListener)
      modelListener->onUpdateScore(currentScore);
   counter++;
   if(modelListener){
if(direction == 1){
  if(alfaGun <= 1.1)
   alfaGun += 0.05;
 }
else if(direction == -1){
  if(alfaGun >= -1.1)
   alfaGun -= 0.05;
 }

   if (modelListener)
     modelListener->handleIngameTickEvent();
   if(stage == 6){
     if (counter % 300 == 0)
 {
      if(counter == 1500 ){
       counter = 0;
       eggCurrentCount++;
      }

  if (modelListener)
   modelListener->onClearGrid();
  spawnRow(); // Tạo hàng mới
  if (modelListener)
   modelListener->onEggGridChanged(); // Thông báo cho View cập nhật
  char s[20];
  sprintf(s, "%3d", stage);
  HAL_UART_Transmit(&huart1, (uint8_t*)s, strlen(s), 10);
 }
   }
if (modelListener)
  modelListener->onRotateGunAndShot(alfaGun, shoot);
   }
}

void Model::startTimer()
{
    counter = 0;
    alfaGun = 0;
    currentScore = 0;
	for (int r = 0; r < MAX_ROWS; ++r)
	{
	   for (int c = 0; c < MAX_COLS; ++c)
	   {
		   eggMap[r][c] = { 0, false, 0, 0, false };
	   }
	}


	if(stage == 1)
		eggCurrentCount = 2;
	else if(stage == 2)
		eggCurrentCount = 3;
	else if(stage == 3)
		eggCurrentCount = 4;
	else if(stage == 4)
		eggCurrentCount = 5;
	else if(stage == 5)
		eggCurrentCount = 6;
	else
		eggCurrentCount = 2;
	for (int i = 0; i < 3; ++i)
	{
	   spawnRow();
	}
    if (modelListener)
        modelListener->onEggGridChanged();
	paused = false;
}

void Model::spawnRow()
{
    if (getNumRow() >= MAX_ROWS){
    	return;
    }

    shiftRowsDown();

    int row = 0;
    int rowOffset = (spawnedRowCount % 2 == 1) ? eggSize / 2 : 0;
    int actualCols = (spawnedRowCount % 2 == 0) ? MAX_COLS : MAX_COLS - 1;
    for (int col = 0; col < actualCols; ++col)
    {
        int randomIdx = rand() % eggCurrentCount;

        eggMap[row][col].id = eggIds[randomIdx];
        eggMap[row][col].active = true;
        eggMap[row][col].x = startX + rowOffset + col * (eggSize + spacing);
        eggMap[row][col].y = startY + row * (eggSize + spacing);
        eggMap[row][col].even = (spawnedRowCount % 2 == 0);
        eggMap[row][col].score = (randomIdx + 1) * 5;
    }

    spawnedRowCount++;
}

void Model::shiftRowsDown()
{
    for (int r = MAX_ROWS - 1; r > 0; --r)
    {
        for (int c = 0; c < MAX_COLS; ++c)
        {
            eggMap[r][c] = eggMap[r - 1][c];
            eggMap[r][c].y += eggSize + spacing;
        }
    }

    for (int c = 0; c < MAX_COLS; ++c)
    {
        eggMap[0][c] = { 0, false };
    }
}

BitmapId Model::getRandBitmapId(){
	return eggIds[rand() % eggCurrentCount];
}

int Model::getNumRow(){
	int res = 0;
	for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            if(eggMap[row][col].active){
            	++res;
            	break;
            }
        }
    }
	return res;
}

void Model::attachEggToGrid(int x, int y, BitmapId id)
{
    int row = (y - startY + (eggSize + spacing) / 2) / (eggSize + spacing);

    bool isOffsetRow = false;

    int currentCol = getNumRow();
    if (currentCol > 0 && row > 0) {
        // Xác định từ hàng phía trên
        for (int c = 0; c < MAX_COLS; ++c) {
            if (eggMap[row - 1][c].active) {
                isOffsetRow = eggMap[row - 1][c].even;
                break;
            }
        }
    } else {
        // Nếu là hàng đầu tiên thì lấy theo số hàng spawn ra
    	if(spawnedRowCount % 2 == 1)
    		isOffsetRow = false;
    	else
    		isOffsetRow = true;
    }

    int xOffset = isOffsetRow ? eggSize / 2 : 0;
    int col = (x - startX - xOffset + (eggSize + spacing) / 2) / (eggSize + spacing);

    if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS)
    {
        if (!eggMap[row][col].active)
        {
            eggMap[row][col].id = id;
            eggMap[row][col].active = true;
            eggMap[row][col].x = startX + xOffset + col * (eggSize + spacing);
            eggMap[row][col].y = startY + row * (eggSize + spacing);
            eggMap[row][col].even = !isOffsetRow;
            for(int i = 0; i < eggCount; i++){
            	if(id == eggIds[i])
            		 eggMap[row][col].score = (i + 1) * 5;
            }
            if (modelListener)
                modelListener->onEggGridChanged();
            clearSameColor(row, col);
            if (modelListener)
                modelListener->onEggGridChanged();
            removeFloatingEggs();
			if (modelListener)
				modelListener->onEggGridChanged();
        }
    }
}

void Model::clearSameColor(int r, int c) {
    if (!eggMap[r][c].active)
        return;

    BitmapId color = eggMap[r][c].id;

    memset(visited, 0, sizeof(visited));
    countEggSample = 0;

    markSameColor(r, c, color);
	for (int row = 0; row < MAX_ROWS; ++row)
	{
		for (int col = 0; col < MAX_COLS; ++col)
		{
			if(!eggMap[row][col].active ){
				eggMap[row][col].score = 0;
			}
		}
	}
    if(countEggSample >= 3){
		for (int row = 0; row < MAX_ROWS; ++row)
		{
			for (int col = 0; col < MAX_COLS; ++col)
			{
				if(visited[row][col]){
					eggMap[row][col].active = false;
					currentScore += eggMap[row][col].score;
					eggMap[row][col].score = 0;
				}
			}
		}
    }
}

void Model::markSameColor(int r, int c, BitmapId color) {
    if (r < 0 || r >= MAX_ROWS || c < 0 || c >= MAX_COLS)
        return;
    if (visited[r][c] || !eggMap[r][c].active || eggMap[r][c].id != color)
        return;
    visited[r][c] = true;
    ++countEggSample;
    int* vc = eggMap[r][c].even ? vcEven : vcOdd;

    // Duyệt 6 hướng lân cận
    for (int i = 0; i < 6; ++i) {
        int nr = r + vr[i];
        int nc = c + vc[i];
        markSameColor(nr, nc, color);
    }
}

void Model::removeFloatingEggs(){
	memset(visited, 0, sizeof(visited));
	for (int col = 0; col < MAX_COLS; ++col)
		markConnected(0,col);
	for (int row = 0; row < MAX_ROWS; ++row)
	{
		for (int col = 0; col < MAX_COLS; ++col)
		{
			if(!visited[row][col]){
				eggMap[row][col].active = false;
				currentScore += eggMap[row][col].score;
			}
		}
	}
}

void Model::markConnected(int r, int c){
	if (r < 0 || r >= MAX_ROWS || c < 0 || c >= MAX_COLS)
		return;
	if (visited[r][c] || !eggMap[r][c].active)
	        return;
	visited[r][c] = true;
	int* vc = eggMap[r][c].even ? vcEven : vcOdd;
	for (int i = 0; i < 6; ++i) {
		int nr = r + vr[i];
		int nc = c + vc[i];
		markConnected(nr, nc);
	}
}

