#include "Application.h"
#include "SceneManager.h"
#include "Keyboard.h"


void main( ) {
	ApplicationPtr app = Application::getInstance( );
	SceneManagerPtr manager( new SceneManager( ) );
	KeyboardPtr keyboard( new Keyboard( ) );

	app->addTask( manager->getTag( ), manager );
	app->addTask( keyboard->getTag( ), keyboard );
}