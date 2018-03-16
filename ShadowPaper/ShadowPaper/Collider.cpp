#include "Collider.h"

Collider::Collider( ) {
	_type = COL_NONE;
	_hit = false;
	_fin = false;
}

Collider::~Collider( ) {
}

void Collider::setType( COL_TYPE type ) {
	_type = type;
}

void Collider::hit( ) {
	_hit = true;
}

void Collider::reset( ) {
	_hit = false;
}

void Collider::fin( ) {
	_fin = true;
}

COL_TYPE Collider::getType( ) const {
	return _type;
}

bool Collider::isHit( ) const {
	return _hit;
}

bool Collider::isFin( ) const {
	return _fin;
}