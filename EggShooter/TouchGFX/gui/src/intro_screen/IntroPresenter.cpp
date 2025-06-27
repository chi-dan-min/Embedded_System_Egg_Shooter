#include <gui/intro_screen/IntroView.hpp>
#include <gui/intro_screen/IntroPresenter.hpp>

IntroPresenter::IntroPresenter(IntroView& v)
    : view(v)
{

}

void IntroPresenter::activate()
{

}

void IntroPresenter::deactivate()
{

}
int IntroPresenter::getRowCount() const
{
    return model->getCurrentRowCount();
}

int IntroPresenter::getColCount() const
{
    return Model::MAX_COLS;
}

const Model::EggData& IntroPresenter::getEggAt(int row, int col) const
{
    return model->getEgg(row, col);
}
