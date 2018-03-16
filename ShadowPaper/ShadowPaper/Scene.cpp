#include "Scene.h"

Scene::Scene( ) {
	_next_scene = SCENE_NAME::CONTINUE;
}

Scene::~Scene( ) {
}

void Scene::setNextScene( SCENE_NAME next ) {
	_next_scene = next;
}