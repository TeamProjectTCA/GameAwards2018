#include "ColliderMap.h"

ColliderMap::ColliderMap( ) {
	setType( COL_MAP );
}

ColliderMap::~ColliderMap( ) {
}

void ColliderMap::set( std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y > data ) {
	_col = data;
}

bool ColliderMap::getPointCol( int x, int y ) {

	int col = x / MAP_BLOCK_SIZE;
	int row = y / MAP_BLOCK_SIZE;

	if( col < 0 || row < 0 || col > MAP_SIZE_X - 1 || row > MAP_SIZE_Y - 1 ) {
		return true;
	}

	if( _col[row][col] == 1 ) {
		return true;
	}

	return false;
}

