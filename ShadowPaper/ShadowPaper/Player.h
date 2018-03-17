#pragma once
#include "smart_ptr.h"
#include "Object.h"
#include "Device.h"
#include "Keyboard.h"
#include "mathmatics.h"

PTR( Player );
PTR( Device );
PTR( Keyboard );
PTR( ColliderRect );

class Player : public Object {
public:
	Player( );
	virtual ~Player( );
public:
	void update( );
	void update2( );
public:
	void draw( );
	ColliderPtr getCol( );
private:
	Vector _pos;
	Vector _pos_past;
	int _handle;

	DevicePtr _device;
	KeyboardPtr _keyboard;
	ColliderRectPtr _col;
};

