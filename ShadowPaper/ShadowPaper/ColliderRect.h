#pragma once
#include "Collider.h"
#include "smart_ptr.h"

PTR( ColliderRect );

class ColliderRect : public Collider {
public:
	ColliderRect( );
	virtual ~ColliderRect( );

public:
	void set( int lx, int ly, int rx, int ry );
	void draw( );

	int getLx( ) const;
	int getLy( ) const;
	int getRx( ) const;
	int getRy( ) const;
	

private:
	int _lx;
	int _ly;
	int _rx;
	int _ry;
};

