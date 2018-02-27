#pragma once
#include "Task.h"
#include "smart_ptr.h"
#include "const.h"
#include <string>

PTR( SceneManager );
PTR( Scene );

class SceneManager : public Task {
public:
	static std::string getTag( ) { return "SCENEMANAGER"; }
	static SceneManagerPtr getTask( );
public:
	SceneManager( );
	virtual ~SceneManager( );
public:
	void update( );
private:
	void changeNextScene( );
	std::string convSceneToString( SCENE_NAME scene );
private:
	SCENE_NAME _next_scene;
	ScenePtr _scene;
};

