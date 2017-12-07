#include <vector>

namespace gol {
class Gameplay {

public:
	Gameplay();
	bool init(int lines, int cols);
	void tick();	
	bool isAlive(int line, int col) const;
private:

	int neighbors(std::vector<unsigned char>& buffer, int index);
	std::vector<unsigned char> _buffer[2];
	std::vector<unsigned char>& _current;
	std::vector<unsigned char>& _next;
	int _width;
};
}

