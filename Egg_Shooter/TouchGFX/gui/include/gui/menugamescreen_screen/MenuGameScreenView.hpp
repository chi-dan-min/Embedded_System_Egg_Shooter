#ifndef MENUGAMESCREENVIEW_HPP
#define MENUGAMESCREENVIEW_HPP

#include <gui_generated/menugamescreen_screen/MenuGameScreenViewBase.hpp>
#include <gui/menugamescreen_screen/MenuGameScreenPresenter.hpp>

class MenuGameScreenView : public MenuGameScreenViewBase
{
public:
    MenuGameScreenView();
    virtual ~MenuGameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MENUGAMESCREENVIEW_HPP
