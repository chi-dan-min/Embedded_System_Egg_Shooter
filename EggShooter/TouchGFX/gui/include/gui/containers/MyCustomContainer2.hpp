#ifndef MYCUSTOMCONTAINER2_HPP
#define MYCUSTOMCONTAINER2_HPP

#include <gui_generated/containers/MyCustomContainer2Base.hpp>
#include <touchgfx/Unicode.hpp>
#define SCOREBUFFER_SIZE 5
class MyCustomContainer2 : public MyCustomContainer2Base
{
public:
    MyCustomContainer2();
    virtual ~MyCustomContainer2() {}
    void updateScore(int scoreValue);
    virtual void initialize();
protected:
    Unicode::UnicodeChar scoreBuffer[SCOREBUFFER_SIZE];
};

#endif // MYCUSTOMCONTAINER2_HPP
