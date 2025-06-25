#ifndef SELECTSTAGESCREENPRESENTER_HPP
#define SELECTSTAGESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SelectStageScreenView;

class SelectStageScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SelectStageScreenPresenter(SelectStageScreenView& v);

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

    virtual ~SelectStageScreenPresenter() {}

private:
    SelectStageScreenPresenter();

    SelectStageScreenView& view;
};

#endif // SELECTSTAGESCREENPRESENTER_HPP
