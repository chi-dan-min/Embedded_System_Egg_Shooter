#ifndef MYCUSTOMCONTAINER3_HPP
#define MYCUSTOMCONTAINER3_HPP

#include <gui_generated/containers/MyCustomContainer3Base.hpp>
#include <touchgfx/Unicode.hpp>
#define SCOREBUFFER_SIZE 5
class MyCustomContainer3 : public MyCustomContainer3Base
{
public:
    MyCustomContainer3();
    virtual ~MyCustomContainer3() {}
    void updateScore(int scoreValue);
    virtual void initialize();
protected:
    Unicode::UnicodeChar scoreBuffer[SCOREBUFFER_SIZE];
};

#endif // MYCUSTOMCONTAINER3_HPP
