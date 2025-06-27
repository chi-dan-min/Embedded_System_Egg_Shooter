#include <gui/ingame_screen/IngameView.hpp>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
IngameView::IngameView()
{

}

void IngameView::setupScreen()
{
    IngameViewBase::setupScreen();
    for (int row = 0; row < presenter->getRowCount(); ++row)
	{
		for (int col = 0; col < presenter->getColCount(); ++col)
		{
			const auto& egg = presenter->getEggAt(row, col);
			if (egg.active)
			{
				showEggAt(row, col, egg.type);
			}
			else
			{
				// Nếu không active, có thể ẩn trứng (set bitmap trắng)
				eggImages[row][col].setBitmap(Bitmap(BITMAP_GREEN_ID));
				eggImages[row][col].invalidate();
			}
		}
	}
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
void IngameView::showEggAt(int row, int col, int type)
{
    if (row >= MAX_ROWS || col >= MAX_COLS)
        return;

    BitmapId bmpId = getEggBitmapByType(type);
    eggImages[row][col].setBitmap(Bitmap(bmpId));
    eggImages[row][col].invalidate();
}
