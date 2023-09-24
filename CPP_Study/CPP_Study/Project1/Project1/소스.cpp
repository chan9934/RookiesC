
class Unit
{
	friend class Grid;

public:
	Unit(Grid* grid, double x, double y)
		:grid_(grid), x_(x), y_(y)
	{

	}

private:
	double x_, y_;
	Grid* grid_;
	Unit* prev_;
	Unit* next_;
};

class Grid
{

public:
	Grid()
	{
		for (int x = 0; x < NUM_CELLS; ++x)
		{
			for (int y = 0; y < NUM_CELLS; ++y)
			{
				cells_[x][y] = nullptr;
			}
		}
	}
	static const int NUM_CELLS = 10;
	static const int CELL_SIZE = 20;
private:
	Unit* cells_[NUM_CELLS][NUM_CELLS];
};