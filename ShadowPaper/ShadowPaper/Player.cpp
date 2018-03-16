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
	_col->set( _pos.x - 25, _pos.y - 25, _pos.x + 25, _pos.y + 25 );
}

Player::~Player( ) {
}

void Player::update( ) {
	bool move = false;
	if ( _keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		_pos.x++;
		move = true;
	}
	if ( _keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		_pos.x--;
		move = true;
	}

	if ( !move ) {
		return;
	}
	_col->set( _pos.x - 25, _pos.y - 25, _pos.x + 25, _pos.y + 25 );
}

void Player::draw( ) {
	DrawRotaGraph( _pos.x, _pos.y, 1, 0, _handle, TRUE );
}

ColliderPtr Player::getCol( ) {
	return _col;
}


