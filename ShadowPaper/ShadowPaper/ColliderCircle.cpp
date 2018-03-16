#include "ColliderCircle.h"

ColliderCircle::ColliderCircle( ) {
}

ColliderCircle::~ColliderCircle( ) {
}


void   ColliderCircle::set( Vector pos, float size ) {
	_pos = pos;
	_size = size;
}

float  ColliderCircle::getSize( ) {
	return _size;
}

Vector ColliderCircle::getPos( ) {
	return _pos;
}


