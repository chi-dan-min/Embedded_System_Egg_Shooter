#include <gui/menu_screen/MenuView.hpp>

MenuView::MenuView()
{
}

void MenuView::setupScreen()
{
    MenuViewBase::setupScreen();
}

void MenuView::tearDownScreen()
{
    MenuViewBase::tearDownScreen();
}

void MenuView::openHighScore()
{
    myCustomContainer21.setVisible(true);
    myCustomContainer21.invalidate();
    myCustomContainer21.updateScore(presenter->getHighScore());
}



void MenuView::setStageSurvival()
{
    presenter->setStage(6);
}
