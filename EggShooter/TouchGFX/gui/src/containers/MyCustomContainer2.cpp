#include <gui/containers/MyCustomContainer2.hpp>

MyCustomContainer2::MyCustomContainer2()
{

}

void MyCustomContainer2::initialize()
{
    MyCustomContainer2Base::initialize();
    score.setWildcard(scoreBuffer);
}
void MyCustomContainer2::updateScore(int scoreValue){
	 Unicode::snprintf(scoreBuffer, SCOREBUFFER_SIZE, "%d", scoreValue);
	 score.invalidate();
}
