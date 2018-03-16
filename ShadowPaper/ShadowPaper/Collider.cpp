#include "Collider.h"

Collider::Collider( ) {
}

Collider::~Collider( ) {
}

void Collider::setType( COL_TYPE type ) {
	_type = type;
}

COL_TYPE Collider::getType( ) const {
	return _type;
}