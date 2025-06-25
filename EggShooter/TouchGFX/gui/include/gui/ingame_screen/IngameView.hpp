#ifndef INGAMEVIEW_HPP
#define INGAMEVIEW_HPP

#include <gui_generated/ingame_screen/IngameViewBase.hpp>
#include <gui/ingame_screen/IngamePresenter.hpp>

class IngameView : public IngameViewBase
{
public:
    IngameView();
    virtual ~IngameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INGAMEVIEW_HPP
