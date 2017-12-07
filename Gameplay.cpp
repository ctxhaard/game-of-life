#include "Gameplay.h"
#include <stdlib.h>
#include <array>

#define DEAD (0)
namespace gol {

Gameplay::Gameplay()
: _current { }
, _next { }
, _width{ 0 }
{

}

bool Gameplay::init(int h, int w)
{
	_current.resize(h * w);
	_next.resize(h * w);

	srand(123);
	int r = rand();
	
	for(auto &val : _current) {
		val = !(rand() % 15);
	}
	_width = w;
	return true;
}

void Gameplay::tick()
{
	for (int i = 0; i < _current.size(); ++i) {
		int nNeigh = neighbors(_current, i);
		if(DEAD == _current[i]) {
			/*currently dead*/
			if (3 == nNeigh) _next[i] = !DEAD;
			else _next[i] = DEAD;
		} else {
			/* currently alive*/
			if (nNeigh < 2) _next[i] = DEAD;
			else if(nNeigh > 3) _next[i] = DEAD;
			else _next[i] = !DEAD;
		}
	}
	std::swap(_current, _next);
}

bool Gameplay::isAlive(int line, int col) const
{
	return (_current.at( line * _width + col) != DEAD);
}

int Gameplay::neighbors(std::vector<unsigned char>& buffer, int index) const
{
	int res = 0;
	std::array<int,8> ineigh = { 
		(index - _width - 1), (index - _width), (index - _width + 1),
		(index - 1), (index + 1),
		(index + _width - 1), (index + _width), (index + _width + 1)
	};

	auto begin = ineigh.begin();
	auto end = ineigh.end();
	if (0 == (index % _width)) {
		begin = begin + 3;
	} else if ( (index % _width) == (_width - 1) ) {
		end = end - 3;
	}

	for (auto i = begin; i != end; ++i) {
		if (*i >= 0 && *i < buffer.size()) {
			res += !!buffer[*i];
		}
	}
	return res;
}
} // namespace
