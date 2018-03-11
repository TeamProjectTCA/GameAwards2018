#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Object );

class Object {
public:
	Object( );
	virtual ~Object( );

public:
	virtual void update( ) { };
	virtual void draw( ) { };
	void fin( );

public:
	int getAddObjSize( );
	ObjectPtr getAddObj( );
	bool isFin( ) const;

protected:
	void addObj( ObjectPtr obj );

private:
	bool _fin;
	std::list< ObjectPtr > _objs;
};

