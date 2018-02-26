#include "SceneManager.h"
#include "Application.h"
#include "SceneGame.h"


SceneManagerPtr SceneManager::getTask( ) {
	return std::dynamic_pointer_cast< SceneManager >( Application::getInstance( )->getTask( SceneManager::getTag( ) ) );
}

SceneManager::SceneManager( ) {
	_scene = SceneGamePtr( new SceneGame( ) );
}

SceneManager::~SceneManager( ) {
}

void SceneManager::update( ) {
	_scene->update( );

	//Ÿ‚ÌƒV[ƒ“‚ğ”»’è
	changeNextScene( );

}

void SceneManager::changeNextScene( ) {
	switch ( _scene->getNextScene( ) ) {
	case CONTINUE: 
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