#include "ObjectTest.h"
#include "DxLib.h"
#include "const.h"

ObjectTest::ObjectTest( ) {

	_handle = LoadGraph( "Resources/walk_man.png" );
	_pos = Vector( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0 );
}

ObjectTest::~ObjectTest( ) {
}

void ObjectTest::update( ) {
	_pos.x++;
	_time++;

	if( _time > 120 ) {
		fin( );
		_time = 0;
		addObj( ObjectTestPtr( new ObjectTest( ) ) );
	}
}

void ObjectTest::draw( ) {
	DrawGraph( ( int )_pos.x, ( int )_pos.y, _handle, true );
}


