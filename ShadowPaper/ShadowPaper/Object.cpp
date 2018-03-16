#include "Object.h"
#include "Collider.h"

Object::Object( ) {
}

Object::~Object( ) {
}

void Object::fin( ) {
	_fin = true;
}

int Object::getAddObjSize( ) {
	return ( int )_objs.size( );
}

ObjectPtr Object::getAddObj( ) {
	ObjectPtr obj = _objs.front( );
	_objs.pop_front( );
	return obj;
}

ColliderPtr Object::getCol( ) {
	return ColliderPtr( );
}

bool Object::isFin( ) const {
	return _fin;
}

//protected
void Object::addObj( ObjectPtr obj ) {
	_objs.push_back( obj );
}
