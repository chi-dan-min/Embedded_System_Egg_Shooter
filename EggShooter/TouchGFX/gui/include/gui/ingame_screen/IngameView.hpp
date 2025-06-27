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
protected:
	static const int MAX_ROWS = 7;
	static const int MAX_COLS = 8;
	touchgfx::Image eggImages[MAX_ROWS][MAX_COLS];
};

#endif // INGAMEVIEW_HPP
