#include "ObjectManager.h"
#include "Object.h"
#include "ColliderManager.h"

ObjectManager::ObjectManager( ) {
	_col_manager = ColliderManagerPtr( new ColliderManager( ) );
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

	//当たり判定
	_col_manager->update( );
    
	//当たり判定　反映;
	for ( ite = _objs.begin( ); ite != _objs.end( ); ite++ ) {
		( *ite )->update2( );
	}

	//終了したものを削除
	for ( ite = _objs.begin( ); ite != _objs.end( );) {
		if( ( *ite )->isFin( ) ) {
			ite = _objs.erase( ite );
		} else {
			ite++;
		}
	}

	_col_manager->reset( );
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
	_col_manager->add( obj->getCol( ) );
}
