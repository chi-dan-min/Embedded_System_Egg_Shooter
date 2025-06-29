#include <gui/ingame_screen/IngameView.hpp>
#include <gui/ingame_screen/IngamePresenter.hpp>

IngamePresenter::IngamePresenter(IngameView& v)
    : view(v)
{

}

void IngamePresenter::activate()
{

}

void IngamePresenter::deactivate()
{

}
int IngamePresenter::getRowCount() const
{
    return model->getCurrentRowCount();
}

int IngamePresenter::getColCount() const
{
    return Model::MAX_COLS;
}

const Model::EggData& IngamePresenter::getEggAt(int row, int col) const
{
    return model->getEgg(row, col);
}
void IngamePresenter::startTimer(){
	model->startTimer();
}
void IngamePresenter::onEggGridChanged()
{
    view.updateEggGrid();
}
void IngamePresenter::onClearGrid()
{
	view.clearEggGrid();
}
void IngamePresenter::onRotateGunAndShot(float alfaGun, int8_t shoot)
{
	view.rotateGunAndShot(alfaGun, shoot);
}
BitmapId IngamePresenter::getRandBitmapId(){
	return model->getRandBitmapId();
}
void IngamePresenter::handleIngameTickEvent(){
	view.handleTickEvent();
}
