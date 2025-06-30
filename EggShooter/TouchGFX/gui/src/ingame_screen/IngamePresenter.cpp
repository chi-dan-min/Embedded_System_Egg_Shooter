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
void IngamePresenter::attachEggToGrid(int x, int y, BitmapId id){
	 model->attachEggToGrid(x, y, id);
}
