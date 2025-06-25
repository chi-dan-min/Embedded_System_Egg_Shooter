#ifndef SELECTSTAGESCREENVIEW_HPP
#define SELECTSTAGESCREENVIEW_HPP

#include <gui_generated/selectstagescreen_screen/SelectStageScreenViewBase.hpp>
#include <gui/selectstagescreen_screen/SelectStageScreenPresenter.hpp>

class SelectStageScreenView : public SelectStageScreenViewBase
{
public:
    SelectStageScreenView();
    virtual ~SelectStageScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SELECTSTAGESCREENVIEW_HPP
