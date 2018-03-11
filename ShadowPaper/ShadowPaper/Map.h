#pragma once
#include "const.h"
#include <array>

class Map {
public:
	Map( );
	virtual ~Map( );

public:
	void update( );
	void draw( );

private:
	std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y  > _map_obj;
	std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y  > _map_collider;

	int _handle;
	int _cnt;
};

