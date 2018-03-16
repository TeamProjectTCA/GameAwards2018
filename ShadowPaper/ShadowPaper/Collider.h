#pragma once
#include "const.h"

class Collider {
public:
	Collider( );
	virtual ~Collider( );

public:
	virtual void draw( ) { };
	void setType( COL_TYPE type );
	COL_TYPE getType( ) const;

private:
	COL_TYPE _type;
};

