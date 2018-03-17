#include "SceneManager.h"
#include "Application.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"

SceneManagerPtr SceneManager::getTask( ) {
	return std::dynamic_pointer_cast< SceneManager >( Application::getInstance( )->getTask( SceneManager::getTag( ) ) );
}

SceneManager::SceneManager( ) {
	_scene = SceneTitlePtr( new SceneTitle( ) );
}

SceneManager::~SceneManager( ) {
}

void SceneManager::update( ) {
	ClearDrawScreen( );
	_scene->update( );

	//ŽŸ‚ÌƒV[ƒ“‚ð”»’è
	changeNextScene( );

	//DrawString( 20, 20, convSceneToString( _next_scene ).c_str( ), 0xffffff );
	ScreenFlip( );
}

void SceneManager::changeNextScene( ) {
	switch ( _scene->getNextScene( ) ) {
	case CONTINUE: 
		break;
	case TITLE:
		_scene = SceneTitlePtr( new SceneTitle( ) );
		break;
	case GAME:
		_scene = SceneGamePtr( new SceneGame( ) );
		break;
	case END:
		Application::getInstance( )->terminate( );
		break;
	default:
		break;
	}
}

std::string SceneManager::convSceneToString( SCENE_NAME scene ) {
	std::string str = "";
	switch ( scene ) {
	case CONTINUE: 
		str = "continue";
		break;
	case TITLE:
		str = "title";
		break;
	case GAME:
		str = "game";
		break;
	case END:
		str = "end";
		break;
	default:
		break;
	}

	return str;
}