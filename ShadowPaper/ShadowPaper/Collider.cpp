#include "Collider.h"

Collider::Collider( ) {
	_type = COL_NONE;
	_hit = false;
	_fin = false;
	reset( );
}

Collider::~Collider( ) {
}

void Collider::setType( COL_TYPE type ) {
	_type = type;
}

void Collider::setMove( Vector move ) {
	_move = move;
}

void Collider::addVecStatic( Vector vec ) {
	_vec_static += vec;
}

void Collider::addVecDynamic( Vector vec ) {
	_vec_dynamic += vec;
}

void Collider::hit( ) {
	_hit = true;
}

void Collider::reset( ) {
	_hit = false;
	_vec_dynamic = Vector( );
	_vec_static = Vector( );
}

void Collider::fin( ) {
	_fin = true;
}

COL_TYPE Collider::getType( ) const {
	return _type;
}

Vector Collider::getMove( ) {
	return _move;
}

Vector Collider::getVecStatic( ) {
	return _vec_static;
}

Vector Collider::getVecDynamic( ) {
	return _vec_dynamic;
}

bool Collider::isHit( ) const {
	return _hit;
}

bool Collider::isFin( ) const {
	return _fin;
}