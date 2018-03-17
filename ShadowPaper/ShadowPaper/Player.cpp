#include "Player.h"
#include "Device.h"
#include "Keyboard.h"
#include "DxLib.h"
#include "ColliderRect.h"

Player::Player( ) {
	_device = Device::getTask( );
	_keyboard = Keyboard::getTask( );
	_pos = Vector( );
	_pos.x = 1280 / 2;
	_pos.y = 720 / 2;
	_handle = LoadGraph( "Resources/walk_man.png" );

	_col = ColliderRectPtr( new ColliderRect( ) );
	_col->set( ( int )_pos.x - 25, ( int )_pos.y - 25, ( int )_pos.x + 25, ( int )_pos.y + 25 );
}

Player::~Player( ) {
}

void Player::update( ) {
	_pos_past = _pos;

	bool move = false;
	float speed = 10;
	if ( _keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		_pos.x += speed;
		move = true;
	}
	if ( _keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		_pos.x -= speed;
		move = true;
	}
	if ( _keyboard->isHoldKey( "ARROW_DOWN" ) ) {
		_pos.y += speed;
		move = true;
	}
	if ( _keyboard->isHoldKey( "ARROW_UP" ) ) {
		_pos.y -= speed;
		move = true;
	}


	if ( !move ) {
		return;
	}
	_col->set( _pos.x - 25, _pos.y - 25, _pos.x + 25, _pos.y + 25 );
}

void Player::update2( ) {

	if ( _col->isHit( ) ) {
		_pos = _pos_past;
	}

}

void Player::draw( ) {
	DrawRotaGraph( _pos.x, _pos.y, 1, 0, _handle, TRUE );
	DrawFormatString( 20, 20, 0xff0000, "%.2lf, %.2lf", _pos.x, _pos.y );
}

ColliderPtr Player::getCol( ) {
	return _col;
}


