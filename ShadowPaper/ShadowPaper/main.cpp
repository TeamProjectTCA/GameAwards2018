#include "Application.h"
#include "SceneManager.h"
#include "Device.h"
#include "Keyboard.h"

void main( ) {
	ApplicationPtr app = Application::getInstance( );
	SceneManagerPtr manager( new SceneManager( ) );
	DevicePtr device( new Device( ) );
	KeyboardPtr keyboard( new Keyboard( ) );

	app->addTask( manager->getTag( ), manager );
	app->addTask( device->getTag( ), device );
	app->addTask( keyboard->getTag( ), keyboard );
}