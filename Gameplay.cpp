#include "Gameplay.h"

#define DEAD (0)
namespace gol {

Gameplay::Gameplay()
: _buffer{ std::vector<unsigned char>{}, std::vector<unsigned char>{} }
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
	_current.at( w * h/2 + w/2) = !DEAD;
	_current.at( w * h/2 + w/2 + 1 ) = !DEAD;
	_current.at( w * h/2 + w/2 + 2 ) = !DEAD;
	_width = w;
	return true;
}

void Gameplay::tick()
{
	for (int i = 0; i < _current.size(); ++i) {
		int nNeigh = neighbors(_current, i);
		if(DEAD == _current[i]) {
			/*currently dead*/
			if (3 == nNeigh) _next.at(i) = !DEAD;
		} else {
			/* currently alive*/
			if (nNeigh < 2) _next.at(i) = DEAD;
			else if(nNeigh > 3) _next.at(i) = DEAD;
			else _next.at(i) = !DEAD;
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
	return (_current.at( line * _width + col) != 0);
}
}


int Gameplay::neighbors(std::vector<unsigned char>& buffer, int index)
{
	// TODO: continue here
}
