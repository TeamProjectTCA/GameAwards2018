#pragma once
#include "const.h"
#include "smart_ptr.h"
#include "Object.h"
#include <array>
#include "ColliderMap.h"

PTR( ObjectMap );


class ObjectMap : public Object {
public:
	ObjectMap( );
	virtual ~ObjectMap( );

public:
	void update( );
	void draw( );

	ColliderPtr getCol( );

private:
	std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y  > _map_obj;
	std::array< std::array< unsigned char, MAP_SIZE_X >, MAP_SIZE_Y  > _map_collider;

	int _handle;
	int _cnt;

	ColliderMapPtr _col;
};

