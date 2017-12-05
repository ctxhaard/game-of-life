
namespace gol {
class Gameplay {

public:
	Gameplay();
	bool init(int lines, int cols);
	void tick();	
	bool isAlive(int line, int col) const;
};
}

