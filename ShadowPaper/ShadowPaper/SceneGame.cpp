#include "SceneGame.h"
#include "DxLib.h"
#include "Player.h"
#include "Map.h"
#include "ObjectManager.h"
#include "ObjectTest.h"

SceneGame::SceneGame( ) {
	_cnt = 0;
	_player = PlayerPtr( new Player( ) );
	_map = MapPtr( new Map( ) );
	_manager = ObjectManagerPtr( new ObjectManager( ) );
	_manager->add( ObjectTestPtr( new ObjectTest( ) ) );

	SetBackgroundColor( 100,100,100 );
}

SceneGame::~SceneGame( ) {
}

void SceneGame::update( ) {
	DrawString( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "GAME", 0xffffff );
	//_player->update( );
	//_player->draw( );
	_manager->update( );
	_manager->draw( );
	_map->draw( );
}


