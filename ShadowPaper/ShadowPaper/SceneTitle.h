#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneTitle );
PTR( Drawer );

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );
public:
	void update( );
private:
	int _cnt;
};

