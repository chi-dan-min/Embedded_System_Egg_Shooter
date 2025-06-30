#ifndef MYCUSTOMCONTAINER2_HPP
#define MYCUSTOMCONTAINER2_HPP

#include <gui_generated/containers/MyCustomContainer2Base.hpp>

class MyCustomContainer2 : public MyCustomContainer2Base
{
public:
    MyCustomContainer2();
    virtual ~MyCustomContainer2() {}

    virtual void initialize();
protected:
};

#endif // MYCUSTOMCONTAINER2_HPP
