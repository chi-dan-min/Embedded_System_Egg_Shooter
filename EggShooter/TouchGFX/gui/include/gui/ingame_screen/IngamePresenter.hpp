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


    int getRowCount() const;
    int getColCount() const;

    const Model::EggData& getEggAt(int row, int col) const;
private:
    IngamePresenter();

    IngameView& view;
};

#endif // INGAMEPRESENTER_HPP
