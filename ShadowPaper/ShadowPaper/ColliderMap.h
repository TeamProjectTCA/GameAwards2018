#pragma once
#include "Collider.h"
#include "const.h"
#include "smart_ptr.h"
#include <array>

PTR( ColliderMap );

class ColliderMap : public Collider {
public:
	ColliderMap( );
	virtual ~ColliderMap( );

public:
	void set( std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y > data );

	bool getPointCol( int x, int y );
	int getRectCol( int lx, int ly, int rx, int ry );

private:
	std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y > _col;
};

