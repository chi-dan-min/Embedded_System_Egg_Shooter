#include <gui/ingame_screen/IngameView.hpp>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>

IngameView::IngameView()
{
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            eggImages[row][col].setBitmap(Bitmap()); // Ban đầu trống
            eggImages[row][col].setXY(0, 0);
            eggImages[row][col].setVisible(false);   // Ẩn đến khi cần hiện
            add(eggImages[row][col]);                // Quan trọng!
        }
    }
}

void IngameView::setupScreen()
{
    IngameViewBase::setupScreen();
    updateEggGrid();         // Vẽ trứng ngay khi screen hiện
    presenter->startTimer(); // Bắt đầu tick timer
}

void IngameView::tearDownScreen()
{
    IngameViewBase::tearDownScreen();
}

void IngameView::updateEggGrid()
{
    for (int row = 0; row < presenter->getRowCount(); ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            const auto& egg = presenter->getEggAt(row, col);

            if (egg.active)
            {
                eggImages[row][col].setXY(egg.x, egg.y);
                eggImages[row][col].setBitmap(Bitmap(egg.id));
                eggImages[row][col].setVisible(true);
            }
            else
            {
                eggImages[row][col].setVisible(false);
            }

            eggImages[row][col].invalidate(); // Cập nhật lại
        }
    }
}

void IngameView::clearEggGrid(){
	for (int row = 0; row < presenter->getRowCount(); ++row)
	{
		for (int col = 0; col < MAX_COLS; ++col)
		{
			const auto& egg = presenter->getEggAt(row, col);
			eggImages[row][col].setVisible(false);
			eggImages[row][col].invalidate(); // Cập nhật lại
		}
	}
}
