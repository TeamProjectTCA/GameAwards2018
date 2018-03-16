#pragma once
#include "const.h"

class Scene {
public:
	Scene( );
	virtual ~Scene( );
public:
	virtual void update( ) = 0;
public:
	void setNextScene( SCENE_NAME next );
	SCENE_NAME getNextScene( ) { return _next_scene; };

private:
	SCENE_NAME _next_scene;
};

