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

int ColliderMap::getRectCol( int lx, int ly, int rx, int ry ) {
	int col_l = lx / MAP_BLOCK_SIZE;
	int row_l = ly / MAP_BLOCK_SIZE;
	int col_r = rx / MAP_BLOCK_SIZE;
	int row_r = ry / MAP_BLOCK_SIZE;

	if ( col_l < 0 || col_r > MAP_SIZE_X - 1 ||
		 row_l < 0 || row_r > MAP_SIZE_Y - 1 ) {
		return 1;
	}

	for ( int i = 0; i < row_r - row_l + 1; i++ ) {
		for ( int j = 0; j < col_r - col_l + 1; j++ ) {
			if ( _col[ row_l + i ][ col_l + j ] != 0 ) {
				return 1;
			}
		}
	}

	return 0;
}
