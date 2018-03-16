#pragma once
#include "Collider.h"
#include "smart_ptr.h"
#include "mathmatics.h"

PTR( ColliderCircle );

class ColliderCircle : public Collider {
public:
	ColliderCircle( );
	virtual ~ColliderCircle( );

public:
	void set( Vector pos, float size );
	
	float getSize( );
	Vector getPos( );

private:
	Vector _pos;
	float _size;
};

