#pragma once
#include "const.h"

class Collider {
public:
	Collider( );
	virtual ~Collider( );

public:
	virtual void draw( ) { };
	void setType( COL_TYPE type );
	void hit( );
	void reset( );
	void fin( );

	COL_TYPE getType( ) const;
	bool isHit( ) const;
	bool isFin( ) const;

private:
	COL_TYPE _type;
	bool _hit;
	bool _fin;
};

