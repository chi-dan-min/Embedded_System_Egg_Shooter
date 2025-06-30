#ifndef INGAMEVIEW_HPP
#define INGAMEVIEW_HPP

#include <gui_generated/ingame_screen/IngameViewBase.hpp>
#include <gui/ingame_screen/IngamePresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
class IngameView : public IngameViewBase
{
public:
    IngameView();
    virtual ~IngameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

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
};

#endif // INGAMEVIEW_HPP
