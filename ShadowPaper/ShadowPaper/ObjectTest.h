#pragma once
#include "Object.h"
#include "mathmatics.h"
#include "smart_ptr.h"

PTR( ObjectTest );

class ObjectTest : public Object {
public:
	ObjectTest();
	virtual ~ObjectTest();

public:
	void update( );
	void draw( );

public:
	int _handle;
	int _time;
	Vector _pos;
};

