#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneGame );
PTR( Player );
PTR( Map );
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
	MapPtr _map;

	ObjectManagerPtr _manager;
};

