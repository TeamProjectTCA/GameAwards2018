#pragma once
#include "smart_ptr.h"
#include "Object.h"
#include "Device.h"
#include "Keyboard.h"
#include "mathmatics.h"

PTR( Player );
PTR( Device );
PTR( Keyboard );

class Player : public Object {
public:
	Player( );
	virtual ~Player( );
public:
	void update( );
public:
	void draw( );
private:
	Vector _pos;
	int _handle;

	DevicePtr _device;
	KeyboardPtr _keyboard;
};

