#ifndef INGAMEVIEW_HPP
#define INGAMEVIEW_HPP

#include <gui_generated/ingame_screen/IngameViewBase.hpp>
#include <gui/ingame_screen/IngamePresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <gui/containers/MyCustomContainer1.hpp>
#include <gui/containers/MyCustomContainer3.hpp>
class IngameView : public IngameViewBase
{
public:
    IngameView();
    virtual ~IngameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void openMenuIngame();
    touchgfx::Callback<IngameView> continueCallback;
    touchgfx::Callback<IngameView> reloadCallback;
    void onContinueGame();
    void reloadStage();
    void openGameOver();
    void updateEggGrid();
    void clearEggGrid();
    void rotateGunAndShot(float alfaGun, int8_t shoot);
    void updateEggToShoot();
    void handleTickEvent();
    BitmapId getRandBitmapId();
	static const int MAX_ROWS = 7;
	static const int MAX_COLS = 8;
	touchgfx::Image eggImages[MAX_ROWS][MAX_COLS];
	int isShooting = 0;
	BitmapId current, next, shooted;
	float eggX, eggY;
	float velocityX, velocityY;
	float speed = 3.0f;
	MyCustomContainer1 myCustomContainer11;//setting
	MyCustomContainer3 myCustomContainer31;//game over
};

#endif // INGAMEVIEW_HPP
