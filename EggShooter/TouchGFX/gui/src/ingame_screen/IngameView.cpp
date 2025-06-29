#include <gui/ingame_screen/IngameView.hpp>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
#include <math.h>
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
//    current = getRandBitmapId();
//    currentEgg.setBitmap(Bitmap(current));
//    currentEgg.setPosition(110, 290, 20, 20);
//    currentEgg.invalidate();
//    next = getRandBitmapId();
//    nextEgg.setBitmap(Bitmap(next));
//    nextEgg.invalidate();
}

void IngameView::setupScreen()
{
    IngameViewBase::setupScreen();
    updateEggGrid();         // Vẽ trứng ngay khi screen hiện
    next = getRandBitmapId();
    updateEggToShoot();
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

            eggImages[row][col].invalidate();
        }
    }
}

void IngameView::clearEggGrid(){
	for (int row = 0; row < presenter->getRowCount(); ++row)
	{
		for (int col = 0; col < MAX_COLS; ++col)
		{
			eggImages[row][col].setVisible(false);
			eggImages[row][col].invalidate();
		}
	}
}
void IngameView::rotateGunAndShot(float alfaGun, int8_t shoot)
{
	if(alfaGun > 0){
		gun.setAngles(0.0f, 0.0f, alfaGun);
		arrow.setAngles(0.0f, 0.0f, alfaGun);
	}
	else{
		gun.setAngles(0.0f, 0.0f, 4.71 + 1.57 + alfaGun);
		arrow.setAngles(0.0f, 0.0f, 4.71 + 1.57 + alfaGun);
	}
	gun.invalidate();
	arrow.invalidate();


	if (shoot == 1 && !isShooting) {
	    isShooting = 1;
	    eggX = gun.getX() + gun.getWidth() * 0.5 - 15;
	    eggY = gun.getY() + gun.getHeight() * 0.5;
	    velocityX = speed * sin(alfaGun);
	    velocityY = -speed * cos(alfaGun);

	    eggToShootImage.setBitmap(Bitmap(currentEgg.getBitmap()));
	    eggToShootImage.setXY((int)eggX, (int)eggY);
	    eggToShootImage.setVisible(true);
	    updateEggToShoot();
	}
}
void IngameView::handleTickEvent() {
    if (isShooting) {
    	eggToShootImage.setVisible(false);
        eggToShootImage.invalidate();
        eggX += velocityX;
        eggY += velocityY;
        eggToShootImage.setVisible(true);
        if (eggX <= 0 || eggX + eggToShootImage.getWidth() >= 240) {
            velocityX = -velocityX;
            eggX += velocityX; // tránh stuck ở tường
        }

        eggToShootImage.setXY((int)eggX, (int)eggY);
        eggToShootImage.invalidate();

        if (eggY < 50) {
            isShooting = false;
            eggToShootImage.setVisible(false);
        }
    }
}
void IngameView::updateEggToShoot()
{
	current = next;
	next = getRandBitmapId();

    currentEgg.setBitmap(Bitmap(current));
    currentEgg.setPosition(110, 290, 20, 20);
    currentEgg.invalidate();

    nextEgg.setBitmap(Bitmap(next));
    nextEgg.invalidate();
}

BitmapId IngameView::getRandBitmapId()
{
    return presenter->getRandBitmapId();
}


