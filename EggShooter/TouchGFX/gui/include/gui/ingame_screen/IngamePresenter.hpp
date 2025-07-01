#ifndef INGAMEPRESENTER_HPP
#define INGAMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class IngameView;

class IngamePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    IngamePresenter(IngameView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~IngamePresenter() {}
    virtual void setPaused(bool state);
    virtual void onEggGridChanged();
    virtual void onClearGrid();
    virtual void onRotateGunAndShot(float alfaGun, int8_t shoot);
    virtual void handleIngameTickEvent();
    virtual BitmapId getRandBitmapId();
    virtual void attachEggToGrid(int x, int y, BitmapId id);

    const Model::EggData& getEggAt(int row, int col) const;
    virtual void startTimer();
    virtual void onGameOver();
    virtual void onUpdateScore(int score);
private:
    IngamePresenter();

    IngameView& view;
};

#endif // INGAMEPRESENTER_HPP
