#ifndef STAGEVIEW_HPP
#define STAGEVIEW_HPP

#include <gui_generated/stage_screen/StageViewBase.hpp>
#include <gui/stage_screen/StagePresenter.hpp>

class StageView : public StageViewBase
{
public:
    StageView();
    virtual ~StageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void setStage1();
    virtual void setStage2();
    virtual void setStage3();
    virtual void setStage4();
    virtual void setStage5();
protected:
};

#endif // STAGEVIEW_HPP
