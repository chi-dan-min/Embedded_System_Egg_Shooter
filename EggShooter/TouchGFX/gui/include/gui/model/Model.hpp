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
		bool even;
	};
	//init
	const EggData& getEgg(int row, int col) const { return eggMap[row][col]; }
	void spawnRow();
	int getNumRow();
	void shiftRowsDown();
	//gun and shooting egg
	void prepareNextEgg();
	void startTimer();
	BitmapId getRandBitmapId();

	//grid egg process
	void attachEggToGrid(int x, int y, BitmapId id);
	void clearSameColor(int r, int c);
	void markSameColor(int r, int c, BitmapId color);
	void removeFloatingEggs();
	void markConnected(int r, int c);

protected:
	ModelListener* modelListener;

	//data egg
	const int eggSize = 30;
	const int startX = 0;
	const int startY = 57;
	const int spacing = 0;
	//gun setup
	int counter = 0;
	float alfaGun = 0;
	BitmapId currentEggId;
	BitmapId nextEggId;
	// var grid process
    EggData eggMap[MAX_ROWS][MAX_COLS];
	int spawnedRowCount = 0;
	int countEggSample;
	bool visited[MAX_ROWS][MAX_COLS];
};

#endif // MODEL_HPP
