#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneGame );
PTR( Player );
PTR( ObjectMap );
PTR( ObjectManager );

class SceneGame : public Scene {
public:
	SceneGame( );
	virtual ~SceneGame( );
public:
	void update( );
private:
	int _cnt;
	PlayerPtr _player;
	ObjectMapPtr _map;

	ObjectManagerPtr _manager;
};

