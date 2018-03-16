#include "SceneTitle.h"
#include "Application.h"
#include "DxLib.h"

SceneTitle::SceneTitle( ) {
	_cnt = 0;
}

SceneTitle::~SceneTitle( ) {
}

void SceneTitle::update( ) {
	DrawString( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, "TITLE", 0xffffff );
	if ( _cnt > 100 ) {
		setNextScene( GAME );
	}
	_cnt++;
}