#include "ColliderManager.h"

ColliderManager::ColliderManager( ) {
}

ColliderManager::~ColliderManager( ) {
}

void ColliderManager::draw( ) {
	std::list< ColliderPtr >::iterator ite = _cols.begin( );
	for ( ite; ite != _cols.end( ); ite++ ) {
		( *ite )->draw( );
	}
}

void ColliderManager::update( ) {
	//std::list< ColliderPtr >::iterator ite = _cols.begin( );
	//std::list< ColliderPtr >::iterator ite2;
	//int size = ( int )_cols.size( );
	//if ( size < 2 ) {
	//	return;
	//}

	//for( int i = 0; i < size; i++ ) {
	//	ite2 = ite;
	//	ite2++;
	//	for( int j = 0; j < size - 1 - i; j++ ) {
	//		bool test = false;
	//		if ( ( *ite )->getType( ) == COL_CIRCLE ) {
	//			if( (*ite2)->getTag( ) == COL_CIRCLE ) {
	//				collideBallToBall( *ite,*ite2 );
	//			}
	//			if( (*ite2)->getTag( ) == "LINE" ) {
	//				collideBallToLine( *ite, *ite2 );
	//			}
	//			if ( (*ite2)->getTag() == COL_RECT ) {
	//				collideBallToBox( *ite, *ite2 );
	//			}
	//		}
	//		if( (*ite)->getTag() == "LINE" ) {
	//			if( (*ite2)->getTag() == COL_CIRCLE ) {
	//				collideBallToLine( *ite2, *ite );
	//			}
	//			if( (*ite2)->getTag() == "LINE" ) {
	//				collideLineToLine( *ite, *ite2 );
	//			}
	//			if ( (*ite2)->getTag() == COL_RECT ) {
	//				collideLineToBox( *ite, *ite2 );
	//			}
	//		}
	//		if( (*ite)->getTag() == COL_RECT ) {
	//			if( (*ite2)->getTag() == COL_CIRCLE ) {
	//				collideBallToBox( *ite2, *ite );
	//			}
	//			if( (*ite2)->getTag() == "LINE" ) {
	//				collideLineToBox( *ite2, *ite );
	//			}
	//			if ( (*ite2)->getTag() == COL_RECT ) {
	//				collideBoxToBox( *ite, *ite2 );
	//			}
	//		}


	//		if( (*ite)->getTag() == "MAP" ) {
	//			if( (*ite2)->getTag( ) == "BOXS" ) {
	//				collideMapToBoxStatic( (*ite), (*ite2) );
	//			}
	//		}
	//		if( (*ite)->getTag() == "BOXS" ) {
	//			if( (*ite2)->getTag() == "MAP" ) {
	//				collideMapToBoxStatic( (*ite2), (*ite) );
	//			}
	//		}
	//		ite2++;
	//	}
	//	ite++;
	//}
}
//
//void ColliderManager::addCollide( ColliderPtr col ) {
//	_cols.push_back( col );
//}
//
//void ColliderManager::clearHit( ) {
//	std::list< ColliderPtr >::iterator ite = _cols.begin( );
//	while ( ite != _cols.end( ) ) {
//		(*ite)->setHit( false );
//		ite++;
//	}
//}
//
////protected
//void ColliderManager::collideBallToBall( ColliderPtr ball1, ColliderPtr ball2 ) {
//	ColliderBallPtr c_ball1 = std::dynamic_pointer_cast< CollideBall >( ball1 );
//	ColliderBallPtr c_ball2 = std::dynamic_pointer_cast< CollideBall >( ball2 );
//
//	if ( VSize( VSub( c_ball1->getPos(), c_ball2->getPos() ) ) < c_ball1->getSize() + c_ball2->getSize() ) {
//		c_ball1->setHit( true );
//		c_ball2->setHit( true );
//	}
//
//}
//
//void ColliderManager::collideBallToLine( ColliderPtr ball, ColliderPtr line ) {
//	ColliderBallPtr c_ball = std::dynamic_pointer_cast< CollideBall >( ball );
//	ColliderLinePtr c_line = std::dynamic_pointer_cast< CollideLine >( line );
//
//	VECTOR v_to_ball = VSub( c_ball->getPos( ), c_line->getStart( ) );
//	VECTOR v_to_end = VSub( c_line->getEnd( ), c_line->getStart( ) );
//	double line_falf_length = VSize2( v_to_end ) * 0.5;
//	c_line->setPos( VAdd( c_line->getStart( ), VScale( v_to_end, 0.5 ) ) );
//	v_to_end = VNorm( v_to_end );// ê≥ãKâª
//
//	double line_to_ball = cross2D( v_to_end, v_to_ball );
//
//	if ( abs( line_to_ball ) < c_ball->getSize( ) ) {
//
//		if( VSize( VSub( c_ball->getPos( ) ,c_line->getPos( ) ) ) < line_falf_length  || 
//			VSize( VSub( c_ball->getPos( ) ,c_line->getStart( ) ) ) < c_ball->getSize()  ||
//			VSize( VSub( c_ball->getPos( ) ,c_line->getEnd( ) ) ) < c_ball->getSize()  ) {
//			c_ball->setHit( true );
//			c_line->setHit( true );
//		}
//	}
//
//}
//
//void ColliderManager::collideBallToBox( ColliderPtr ball, ColliderPtr box ) {
//	CollideBallPtr c_ball = std::dynamic_pointer_cast< CollideBall >( ball );
//	//CollideBallPtr c_box = std::dynamic_pointer_cast< CollideBall >( box );
//}
//
//void ColliderManager::collideLineToLine( ColliderPtr line1, ColliderPtr line2 ) {
//	CollideLinePtr c_line1 = std::dynamic_pointer_cast< CollideLine >( line1 );
//	CollideLinePtr c_line2 = std::dynamic_pointer_cast< CollideLine >( line2 );
//}
//
//void ColliderManager::collideLineToBox( ColliderPtr line, ColliderPtr box ) {
//	CollideLinePtr c_line = std::dynamic_pointer_cast< CollideLine >( line );
//	//CollideLinePtr c_line = std::dynamic_pointer_cast< CollideLine >( line );
//}
//
//void ColliderManager::collideBoxToBox( ColliderPtr Box1, ColliderPtr box2 ) {
//	//CollideLinePtr c_line = std::dynamic_pointer_cast< CollideLine >( line );
//	//CollideLinePtr c_line = std::dynamic_pointer_cast< CollideLine >( line );
//}
//
//void ColliderManager::collideMapToBoxStatic( ColliderPtr map, ColliderPtr boxst ) {
//	CollideMapPtr         c_map = std::dynamic_pointer_cast< CollideMap >( map );
//	CollideBoxStaticPtr c_boxst = std::dynamic_pointer_cast< CollideBoxStatic >( boxst );
//}
