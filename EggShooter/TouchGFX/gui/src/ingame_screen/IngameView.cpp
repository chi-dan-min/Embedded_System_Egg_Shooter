#include <gui/ingame_screen/IngameView.hpp>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
IngameView::IngameView()
{
	for (int row = 0; row < MAX_ROWS; ++row)
	{
		for (int col = 0; col < MAX_COLS; ++col)
		{
			eggImages[row][col].setBitmap(Bitmap(BITMAP_GREEN_ID)); // hoặc Bitmap() nếu chưa có rỗng
			int x = startX + col * (eggSize + spacing);
			int y = startY + row * (eggSize + spacing);
			eggImages[row][col].setXY(x, y);
			add(eggImages[row][col]);
		}
	}
}

void IngameView::setupScreen()
{
    IngameViewBase::setupScreen();
}

void IngameView::tearDownScreen()
{
    IngameViewBase::tearDownScreen();
}
BitmapId IngameView::getEggBitmapByType(int type)
{
    switch (type)
    {
    case 0:
        return BITMAP_GREEN_ID;
    case 1:
        return BITMAP_RED_ID;
    case 2:
        return BITMAP_YELLOW_ID;
    default:
        return BITMAP_BROWN_ID;
    }
}
