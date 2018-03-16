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

private:
	std::list< ColliderPtr > _cols;
};

