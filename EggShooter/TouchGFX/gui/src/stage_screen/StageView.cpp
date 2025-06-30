#include <gui/stage_screen/StageView.hpp>

StageView::StageView()
{

}

void StageView::setupScreen()
{
    StageViewBase::setupScreen();
}

void StageView::tearDownScreen()
{
    StageViewBase::tearDownScreen();
}
void StageView::setStage1(){
	presenter->setStage(1);
}
void StageView::setStage2(){
	presenter->setStage(2);
}
void StageView::setStage3(){
	presenter->setStage(3);
}
void StageView::setStage4(){
	presenter->setStage(4);
}
void StageView::setStage5(){
	presenter->setStage(5);
}

