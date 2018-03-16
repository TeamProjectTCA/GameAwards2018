#include "ColliderRect.h"
#include "DxLib.h"

ColliderRect::ColliderRect( ) {
	setType( COL_RECT );
}

ColliderRect::~ColliderRect( ) {
}

void ColliderRect::set( int lx, int ly, int rx, int ry ) {
	_lx = lx;
	_ly = ly;
	_rx = rx;
	_ry = ry;
}

void ColliderRect::draw( ) {
	DrawBox( _lx, _ly, _rx, _ry, 0x00ff00, false );
}

int ColliderRect::getLx( ) const {
	return _lx;
}

int ColliderRect::getLy( ) const {
	return _ly;
}

int ColliderRect::getRx( ) const {
	return _rx;
}

int ColliderRect::getRy( ) const {
	return _ry;
}	