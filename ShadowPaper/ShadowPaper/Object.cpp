#include "Object.h"
#include "Collider.h"

Object::Object( ) {
	_col = ColliderPtr( );
}

Object::~Object( ) {
}

int Object::getAddObjSize( ) {
	return ( int )_objs.size( );
}

ObjectPtr Object::getAddObj( ) {
	ObjectPtr obj = _objs.front( );
	_objs.pop_front( );
	return obj;
}

void Object::fin( ) {
	_fin = true;
}

bool Object::isFin( ) const {
	return _fin;
}

//protected
void Object::addObj( ObjectPtr obj ) {
	_objs.push_back( obj );
}
