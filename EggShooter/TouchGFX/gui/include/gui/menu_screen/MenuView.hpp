#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <gui_generated/menu_screen/MenuViewBase.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>

class MenuView : public MenuViewBase
{
public:
    MenuView();
    virtual ~MenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void openHighScore();
    virtual void setStageSurvival();
protected:
    Unicode::UnicodeChar scoreBuffer[SCOREBUFFER_SIZE];
};

#endif // MENUVIEW_HPP
