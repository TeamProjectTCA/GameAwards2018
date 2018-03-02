#include "Player.h"
#include "Device.h"
#include "Keyboard.h"
#include "DxLib.h"

Player::Player( ) {
	_device = Device::getTask( );
	_keyboard = Keyboard::getTask( );
	_pos = Vector( );
	_pos.x = 1280 / 2;
	_pos.y = 720 / 2;
	_handle = LoadGraph( "Resources/walk_man.png" );
}

Player::~Player( ) {
}

void Player::update( ) {
	if ( _keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		_pos.x++;
	}
	if ( _keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		_pos.x--;
	}
}

void Player::draw( ) const {
	DrawModiGraphF( _pos.x - 25.0f, _pos.y -  25.0f, _pos.x +  25.0f, _pos.y -  25.0f, _pos.x +  25.0f, _pos.y +  25.0f, _pos.x -  25.0f, _pos.y +  25.0f, _handle, TRUE );
}