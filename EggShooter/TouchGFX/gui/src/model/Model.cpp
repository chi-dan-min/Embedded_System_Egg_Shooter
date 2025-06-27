#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h>

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

Model::Model() : modelListener(0), counter(0), currentRowCount(0)
{
    // Khởi tạo lưới trứng rỗng
    for (int r = 0; r < MAX_ROWS; ++r)
    {
        for (int c = 0; c < MAX_COLS; ++c)
        {
            eggMap[r][c] = { 0, false, 0, 0 };
        }
    }

    // Khởi tạo một vài hàng ban đầu
    for (int i = 0; i < 3; ++i)
    {
        spawnRow();
    }
}

void Model::tick()
{
    counter++;

    if (counter >= 500)
    {
        counter = 0;
        if (modelListener)
            modelListener->onClearGrid();
        spawnRow(); // Tạo hàng mới

        if (modelListener)
            modelListener->onEggGridChanged(); // Thông báo cho View cập nhật
    }
}

void Model::spawnRow()
{
//    if (currentRowCount >= MAX_ROWS)
//        return;

    shiftRowsDown();

    int row = 0; // dòng đầu tiên là hàng mới
    int rowOffset = (currentRowCount % 2 == 1) ? eggSize / 2 : 0;
    int actualCols = (currentRowCount % 2 == 0) ? MAX_COLS : MAX_COLS - 1;
    for (int col = 0; col < actualCols; ++col)
    {
        int randomIdx = rand() % 3;

        eggMap[row][col].id = eggIds[randomIdx];
        eggMap[row][col].active = true;
        eggMap[row][col].x = startX + rowOffset + col * (eggSize + spacing);
        eggMap[row][col].y = startY + row * (eggSize + spacing);
    }

    currentRowCount++;
}

void Model::shiftRowsDown()
{
    // Dời từ dưới lên để tránh ghi đè
    for (int r = MAX_ROWS - 1; r > 0; --r)
    {
        for (int c = 0; c < MAX_COLS; ++c)
        {
            eggMap[r][c] = eggMap[r - 1][c];
            eggMap[r][c].y += eggSize + spacing;
        }
    }

    // Xóa hàng đầu trước khi sinh mới (đề phòng)
    for (int c = 0; c < MAX_COLS; ++c)
    {
        eggMap[0][c] = { 0, false };
    }
}

void Model::startTimer()
{
    counter = 0;
}
