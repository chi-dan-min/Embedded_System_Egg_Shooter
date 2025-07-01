#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}
    virtual void onEggGridChanged() {}
    virtual void onClearGrid() {}
    virtual void onRotateGunAndShot(float alfaGun, int8_t shoot){}
    virtual void handleIngameTickEvent(){}
    virtual void onGameOver(){};
    virtual void onUpdateScore(int score){};
    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
