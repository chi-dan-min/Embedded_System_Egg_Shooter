#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
using namespace touchgfx;

const BitmapId eggBitmaps[] = {
		BITMAP_GREEN_ID,
		BITMAP_RED_ID,
		BITMAP_YELLOW_ID,
		BITMAP_BROWN_ID,
		BITMAP_MIDNIGHT_ID,
		BITMAP_PURPLE_ID,
		BITMAP_BLACK_ID
};


const int eggCount = sizeof(eggBitmaps) / sizeof(BitmapId);

Model::Model() : modelListener(0)
{
	for (int r = 0; r < MAX_ROWS; ++r)
		for (int c = 0; c < MAX_COLS; ++c)
			eggMap[r][c] = { 0, false };
}

void Model::tick()
{
	static int counter = 0;
	counter++;

	if (counter >= 300)
	{
		counter = 0;
		spawnRow();
	}
}

void Model::spawnRow()
{
    if (currentRowCount >= MAX_ROWS)
    {
        return;
    }

    shiftRowsDown();

    for (int c = 0; c < MAX_COLS; ++c)
    {
        eggMap[0][c].type = rand() % eggCount;
        eggMap[0][c].active = true;
    }

    currentRowCount++;
}

void Model::shiftRowsDown()
{
    for (int r = MAX_ROWS - 1; r > 0; --r)
    {
        for (int c = 0; c < MAX_COLS; ++c)
        {
            eggMap[r][c] = eggMap[r - 1][c];
        }
    }

}
