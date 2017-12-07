#include "Gameplay.h"
#include <stdlib.h>

#define DEAD (0)
namespace gol {

Gameplay::Gameplay()
: _buffer{ }
, _current { _buffer[0] }
, _next { _buffer[1] }
, _width{ 0 }
{

}

bool Gameplay::init(int h, int w)
{
	_buffer[0].resize(h * w);
	_buffer[1].resize(h * w);

	_current = _buffer[0];

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

	if (&_current == &_buffer[0]) {
		_current = _buffer[1];
		_next = _buffer[0];
	} else {
		_current = _buffer[0];
		_next = _buffer[1];
	}
}

bool Gameplay::isAlive(int line, int col) const
{
	return (_current.at( line * _width + col) != DEAD);
}

int Gameplay::neighbors(std::vector<unsigned char>& buffer, int index) const
{
	int res = 0;
	std::vector<int> ineigh = { 
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
