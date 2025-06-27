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

    void showEggAt(int row, int col, int type);
protected:
	static const int MAX_ROWS = 7;
	static const int MAX_COLS = 7;

	touchgfx::Image eggImages[MAX_ROWS][MAX_COLS];
	const int eggSize = 30;
	const int startX = 0;
	const int startY = 57;
	const int spacing = 1;

   BitmapId getEggBitmapByType(int type);
};

#endif // INGAMEVIEW_HPP
