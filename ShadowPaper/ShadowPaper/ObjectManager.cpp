#include "ObjectManager.h"
#include "Object.h"

ObjectManager::ObjectManager( ) {
}

ObjectManager::~ObjectManager( ) {
}

void ObjectManager::update( ) {
	std::list< ObjectPtr >::iterator ite;

	//�S�A�b�v�f�[�g
	for ( ite = _objs.begin( ); ite != _objs.end( ); ite++ ) {
		( *ite )->update( );
		//�ǉ�����T��
		int size = ( *ite )->getAddObjSize( );
		for ( int i = 0; i < size; i++ ) {
			add( ( *ite )->getAddObj( ) );
		}
	}



	//�I���������̂��폜
	for ( ite = _objs.begin( ); ite != _objs.end( );) {
		if( ( *ite )->isFin( ) ) {
			ite = _objs.erase( ite );	
		} else {
			ite++;
		}
	}
}

void ObjectManager::draw( ) {
	std::list< ObjectPtr >::iterator ite;
	for ( ite = _objs.begin( ); ite != _objs.end( ); ite++ ) {
		( *ite )->draw( );
	}
}

void ObjectManager::add( ObjectPtr obj ) {
	//�I�u�W�F�N�g�f�[�^���߂�
	_objs.push_back( obj );
	//�����蔻��f�[�^���߂�
	//_cols->add ( obj->getCol( ) );
}
