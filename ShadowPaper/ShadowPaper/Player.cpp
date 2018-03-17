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

	_vec = Vector( );

	_col = ColliderRectPtr( new ColliderRect( ) );
	_col->set( ( int )_pos.x - 25, ( int )_pos.y - 25, ( int )_pos.x + 25, ( int )_pos.y + 25, Vector( ) );
}

Player::~Player( ) {
}

void Player::update( ) {
	_pos_past = _pos;
	_vec *= 0.95;

	float speed = 0.4;
	if ( _keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		_vec.x += speed;
	}
	if ( _keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		_vec.x -= speed;
	}
	if ( _keyboard->isHoldKey( "ARROW_DOWN" ) ) {
		_vec.y += speed;
	}
	if ( _keyboard->isHoldKey( "ARROW_UP" ) ) {
		_vec.y -= speed;
	}
	_vec.y += 0.2;

	_pos += _vec;
	if ( _vec.x < 0 ) {
		_pos.x += 1; 
	}

	_pos = Vector( ( int )_pos.x, ( int )_pos.y, ( int )_pos.z );

	_col->set( ( int )_pos.x - 25, ( int )_pos.y - 25, ( int )_pos.x + 25, ( int )_pos.y + 25, _pos - _pos_past );
}

void Player::update2( ) {

	if ( _col->isHit( ) ) {
		//_pos = _pos_past;

		_pos += _col->getVecStatic( );
	}

}

void Player::draw( ) {
	DrawRotaGraph( _pos.x, _pos.y, 1, 0, _handle, TRUE );
	DrawFormatString( 20, 20, 0xff0000, "%.2lf, %.2lf", _pos.x, _pos.y );
}

ColliderPtr Player::getCol( ) {
	return _col;
}


