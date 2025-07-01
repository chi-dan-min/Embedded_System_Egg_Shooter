#include <gui/menu_screen/MenuView.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>

MenuPresenter::MenuPresenter(MenuView& v)
    : view(v)
{

}

void MenuPresenter::activate()
{

}

void MenuPresenter::deactivate()
{

}
void MenuPresenter::setStage(int newStage){
	model->setStage(newStage);
}
int MenuPresenter::getHighScore(){
	return model->getHighScore();
}
