#include "SceneGame.h"
#include "DxLib.h"
#include "Player.h"

SceneGame::SceneGame( ) {
	_cnt = 0;
	_player = PlayerPtr( new Player( ) );
}

SceneGame::~SceneGame( ) {
}

void SceneGame::update( ) {
	DrawString( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "GAME", 0xffffff );
	_player->update( );
	_player->draw( );
}


