#pragma once
#include "const.h"

class Scene {
public:
	Scene( );
	virtual ~Scene( );
public:
	virtual void update( ) = 0;
public:
	SCENE_NAME getNextScene( ) { return _next_scene; };

private:
	SCENE_NAME _next_scene;
};

