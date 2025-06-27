#ifndef MODEL_HPP
#define MODEL_HPP
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
using namespace touchgfx;

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    static const int MAX_ROWS = 7;
    static const int MAX_COLS = 8;
	struct EggData {
		BitmapId id;
		bool active;
		int x;
		int y;
	};
	const EggData& getEgg(int row, int col) const { return eggMap[row][col]; }

	void spawnRow();
	int getCurrentRowCount() const { return currentRowCount; }
	void startTimer();
protected:
    ModelListener* modelListener;
    EggData eggMap[MAX_ROWS][MAX_COLS];
	int currentRowCount = 0;
	int counter = 0;
	const int eggSize = 30;
	const int startX = 0;
	const int startY = 57;
	const int spacing = 0;

	void shiftRowsDown();
};

#endif // MODEL_HPP
