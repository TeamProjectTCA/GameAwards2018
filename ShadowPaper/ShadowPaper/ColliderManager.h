#pragma once
#include "smart_ptr.h"
#include "Collider.h"
#include <list>

PTR( ColliderManager );
PTR( Collider );

class ColliderManager {
public:
	ColliderManager( );
	virtual ~ColliderManager( );

public:
	void draw( );
	void update( );

	void add( ColliderPtr col );
	void reset( );

private:
	void collideCircleToCircle( ColliderPtr col_circle1, ColliderPtr col_circle2 );
	void collideCircleToRect( ColliderPtr col_circle, ColliderPtr col_rect );
	void collideRectToRect( ColliderPtr col_rect1, ColliderPtr col_rect2 );
	void collideMapToRect( ColliderPtr col_map, ColliderPtr col_rect );

private:
	std::list< ColliderPtr > _cols;
};

