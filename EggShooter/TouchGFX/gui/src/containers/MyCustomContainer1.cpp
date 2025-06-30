#include <gui/containers/MyCustomContainer1.hpp>

MyCustomContainer1::MyCustomContainer1()
{

}

void MyCustomContainer1::initialize()
{
    MyCustomContainer1Base::initialize();
}
void MyCustomContainer1::continueGame()
{
    if (onContinue && onContinue->isValid())
    {
        onContinue->execute();
    }
}
void MyCustomContainer1::reloadStage()
{
    if (onReload && onReload->isValid())
    {
    	onReload->execute();
    }
}
void MyCustomContainer1::switchHome(){
	if (onHomeSwitch && onHomeSwitch->isValid())
	{
		onHomeSwitch->execute();
	}
}
