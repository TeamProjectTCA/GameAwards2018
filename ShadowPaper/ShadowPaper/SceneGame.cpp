#include "SceneGame.h"
#include "DxLib.h"
#include "Player.h"
#include "ObjectMap.h"
#include "ObjectManager.h"
#include "ObjectTest.h"

SceneGame::SceneGame( ) {
	_cnt = 0;
	_player = PlayerPtr( new Player( ) );
	_map = ObjectMapPtr( new ObjectMap( ) );
	_manager = ObjectManagerPtr( new ObjectManager( ) );
	//_manager->add( ObjectTestPtr( new ObjectTest( ) ) );
	_manager->add( _map );
	_manager->add( _player );

	SetBackgroundColor( 100,100,100 );
}

SceneGame::~SceneGame( ) {
}

void SceneGame::update( ) {
	DrawString( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "GAME", 0xffffff );
	_manager->update( );
	_manager->draw( );
}


