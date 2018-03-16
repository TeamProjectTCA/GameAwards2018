#include "ObjectManager.h"
#include "Object.h"

ObjectManager::ObjectManager( ) {
}

ObjectManager::~ObjectManager( ) {
}

void ObjectManager::update( ) {
	std::list< ObjectPtr >::iterator ite;

	//全アップデート
	for ( ite = _objs.begin( ); ite != _objs.end( ); ite++ ) {
		( *ite )->update( );
		//追加分を探す
		int size = ( *ite )->getAddObjSize( );
		for ( int i = 0; i < size; i++ ) {
			add( ( *ite )->getAddObj( ) );
		}
	}



	//終了したものを削除
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
	//オブジェクトデータをつめる
	_objs.push_back( obj );
	//当たり判定データをつめる
	//_cols->add ( obj->getCol( ) );
}
