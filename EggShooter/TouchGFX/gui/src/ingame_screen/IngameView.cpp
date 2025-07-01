#include <gui/ingame_screen/IngameView.hpp>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
#include <math.h>
#include <touchgfx/Callback.hpp>

IngameView::IngameView()
{
    for (int row = 0; row < MAX_ROWS; ++row)
    {
        for (int col = 0; col < MAX_COLS; ++col)
        {
            eggImages[row][col].setBitmap(Bitmap());
            eggImages[row][col].setXY(0, 0);
            eggImages[row][col].setVisible(false);
            add(eggImages[row][col]);// quan trọng
        }
    }
    myCustomContainer11.setXY(0, 0);
    myCustomContainer11.setVisible(false);
    add(myCustomContainer11);
    myCustomContainer31.setXY(0, 0);
	myCustomContainer31.setVisible(false);
	add(myCustomContainer31);
}

void IngameView::setupScreen()
{
    IngameViewBase::setupScreen();
    presenter->startTimer(); // Bắt đầu tick timer
    updateEggGrid();         // Vẽ trứng ngay khi screen hiện
    next = getRandBitmapId();
    updateEggToShoot();
}

void IngameView::tearDownScreen()
{
    IngameViewBase::tearDownScreen();
}

void IngameView::openMenuIngame(){
	presenter->setPaused(true);
	continueCallback = touchgfx::Callback<IngameView>(this, &IngameView::onContinueGame);
	reloadCallback = touchgfx::Callback<IngameView>(this, &IngameView::reloadStage);
	myCustomContainer11.onContinue = &continueCallback;
	myCustomContainer11.onReload = &reloadCallback;
	myCustomContainer11.setVisible(true);
	myCustomContainer11.invalidate();
}
void IngameView::onContinueGame()
{
    myCustomContainer11.setVisible(false);
    presenter->setPaused(false);
    myCustomContainer11.invalidate();
}
void IngameView::reloadStage(){
	myCustomContainer11.setVisible(false);
	presenter->setPaused(false);
	myCustomContainer11.invalidate();
	presenter->startTimer();
}
void IngameView::openGameOver(){
	presenter->setPaused(true);
	myCustomContainer31.setVisible(true);
	myCustomContainer31.invalidate();
}
void IngameView::showHighScore(int newScore){
	currentScore.setWildcard(scoreBuffer);
	 Unicode::snprintf(scoreBuffer, SCOREBUFFER_SIZE, "%d", newScore);
	 currentScore.invalidate();
}

void IngameView::updateEggGrid()
{
	for (int row = 0; row < MAX_ROWS; ++row)
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
	for (int row = 0; row < MAX_ROWS; ++row)
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
	    shooted = current;
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

        // Va chạm với lưới
		touchgfx::Rect bulletRect((int)eggX, (int)eggY, eggToShootImage.getWidth(), eggToShootImage.getHeight());

		for (int row = 0; row < MAX_ROWS; ++row)
		{
		   for (int col = 0; col < MAX_COLS; ++col)
		   {
			   if (!eggImages[row][col].isVisible())
				   continue;

			   touchgfx::Rect eggRect = eggImages[row][col].getAbsoluteRect();

			   if (bulletRect.intersect(eggRect))
			   {
				   isShooting = false;
				   eggToShootImage.setVisible(false);

				   presenter->attachEggToGrid((int)eggX, (int)eggY, shooted);
				   updateEggGrid();
				   return;
			   }
		   }
		}

        if (eggY < 50) {
            isShooting = false;
            presenter->attachEggToGrid((int)eggX, (int)eggY, shooted);
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


