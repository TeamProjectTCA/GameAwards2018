#include "SceneGame.h"
#include "DxLib.h"

SceneGame::SceneGame( ) {
	_cnt = 0;
}

SceneGame::~SceneGame( ) {
}

void SceneGame::update( ) {
	DrawString( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "GAME", 0xffffff );
}


