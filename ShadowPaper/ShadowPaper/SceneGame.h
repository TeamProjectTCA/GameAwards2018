#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneGame );
PTR( Player );

class SceneGame : public Scene {
public:
	SceneGame( );
	virtual ~SceneGame( );
public:
	void update( );
private:
	int _cnt;
	PlayerPtr _player;
};

