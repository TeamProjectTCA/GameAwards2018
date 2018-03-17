#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Object );
PTR( Collider );

class Object {
public:
	Object( );
	virtual ~Object( );

public:
	virtual void update( ) { };
	virtual void update2( ) { };
	virtual void draw( ) { };
	void fin( );

public:
	int getAddObjSize( );
	bool isFin( ) const;
	ObjectPtr getAddObj( );
	virtual ColliderPtr getCol( );

protected:
	void addObj( ObjectPtr obj );

private:
	bool _fin;
	std::list< ObjectPtr > _objs;
};

