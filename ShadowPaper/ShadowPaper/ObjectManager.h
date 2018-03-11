#pragma once
#include <list>
#include "smart_ptr.h"

PTR( ObjectManager );
PTR( Object );

class ObjectManager {
public:
	ObjectManager( );
	virtual ~ObjectManager( );

public:
	void update( );
	void draw( );
	void add( ObjectPtr obj );

private:
	std::list< ObjectPtr > _objs;
};

