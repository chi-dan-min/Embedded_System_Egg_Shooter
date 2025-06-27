#ifndef MODEL_HPP
#define MODEL_HPP

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
    static const int MAX_COLS = 7;
	struct EggData {
	   int type;
	   bool active;
	};
	const EggData& getEgg(int row, int col) const { return eggMap[row][col]; }

	void spawnRow();
	int getCurrentRowCount() const { return currentRowCount; }
protected:
    ModelListener* modelListener;
    EggData eggMap[MAX_ROWS][MAX_COLS];
	int currentRowCount = 0;

	void shiftRowsDown();
};

#endif // MODEL_HPP
