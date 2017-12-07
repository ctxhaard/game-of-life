#include <vector>

namespace gol {
class Gameplay {

public:
	Gameplay();
	bool init(int lines, int cols);
	void tick();	
	bool isAlive(int line, int col) const;
private:

	int neighbors(std::vector<unsigned char>& buffer, int index) const;
	std::vector<unsigned char> _buffer[2];
	decltype(_buffer[0])& _current;
	decltype(_buffer[0])& _next;
	int _width;
};
}

