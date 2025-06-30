#ifndef MYCUSTOMCONTAINER1_HPP
#define MYCUSTOMCONTAINER1_HPP

#include <gui_generated/containers/MyCustomContainer1Base.hpp>

class MyCustomContainer1 : public MyCustomContainer1Base
{
public:
    MyCustomContainer1();
    virtual ~MyCustomContainer1() {}
    virtual void continueGame();
    virtual void reloadStage();
    virtual void switchHome();
    virtual void initialize();
    touchgfx::GenericCallback<>* onContinue = nullptr;
    touchgfx::GenericCallback<>* onReload = nullptr;
    touchgfx::GenericCallback<>* onHomeSwitch = nullptr;
protected:
};

#endif // MYCUSTOMCONTAINER1_HPP
