#include "ColliderManager.h"
#include "ColliderCircle.h"
#include "ColliderMap.h"
#include "ColliderRect.h"

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
	std::list< ColliderPtr >::iterator ite;
	for ( ite = _cols.begin( ); ite != _cols.end( );) {
		if( ( *ite )->isFin( ) ) {
			ite = _cols.erase( ite );
		} else {
			ite++;
		}
	}


	int size = ( int )_cols.size( );
	if ( size < 2 ) {
		return;
	}

	std::list< ColliderPtr >::iterator ite2 = ite;
	for ( ite = _cols.begin( ); ite != _cols.end( ); ite++ ) {
		( *ite )->draw( );

		ite2 = ite;
		ite2++;

		COL_TYPE type1 = ( *ite )->getType( );
		for ( ite2; ite2 != _cols.end( ); ite2++ ) {
			bool test = false;
			COL_TYPE type2 = ( *ite2 )->getType( );

			if ( type1 == COL_CIRCLE ) {
				if( type2 == COL_CIRCLE ) {
					collideCircleToCircle( *ite, *ite2 );
				}
				if ( type2 == COL_RECT ) {
					collideCircleToRect( *ite, *ite2 );
				}
			}

			if ( type1 == COL_RECT ) {
				if( type2 == COL_CIRCLE ) {
					collideCircleToRect( *ite2, *ite );
				}
				if ( type2 == COL_RECT ) {
					collideRectToRect( *ite, *ite2 );
				}

				if( type2 == COL_MAP ) {
					collideMapToRect( *ite2, *ite );
				}
			}

			if ( type1 == COL_MAP ) {
				if ( type2 == COL_RECT ) {
					collideMapToRect( *ite, *ite2 );
				}
			}
		}
	}
}

void ColliderManager::collideCircleToCircle( ColliderPtr col_circle1, ColliderPtr col_circle2 ) {
	ColliderCirclePtr c_ball1 = std::dynamic_pointer_cast< ColliderCircle >( col_circle1 );
	ColliderCirclePtr c_ball2 = std::dynamic_pointer_cast< ColliderCircle >( col_circle2 );

	if ( ( c_ball1->getPos( ) - c_ball2->getPos( ) ).getLength( ) < c_ball1->getSize( ) + c_ball2->getSize( ) ) {
		c_ball1->hit( );
		c_ball2->hit( );
	}
}

void ColliderManager::collideCircleToRect( ColliderPtr col_circle, ColliderPtr col_rect ) {

}
void ColliderManager::collideRectToRect( ColliderPtr col_rect1, ColliderPtr col_rect2 ) {

}

void ColliderManager::collideMapToRect( ColliderPtr col_map, ColliderPtr col_rect ) {
	ColliderMapPtr map = std::dynamic_pointer_cast< ColliderMap >( col_map );
	ColliderRectPtr rect = std::dynamic_pointer_cast< ColliderRect >( col_rect );
	Vector move = rect->getMove( );
	int dif_move = 0;

	if ( map->getRectCol( rect->getLx( ), rect->getLy( ) - ( int )move.y, rect->getRx( ), rect->getRy( ) - ( int )move.y ) ) {//xÇ∂Ç≠ÇÃìñÇΩÇËîªíË
		if ( move.x > 0 ) {
			dif_move = rect->getRx( ) % MAP_BLOCK_SIZE;
			dif_move = -dif_move - 1;
		} else {
			dif_move = MAP_BLOCK_SIZE - ( rect->getLx( ) % MAP_BLOCK_SIZE );
		}
		rect->addVecStatic( Vector( dif_move, 0, 0 ) );
		map->hit( );
		rect->hit( );
	}

	if ( map->getRectCol( rect->getLx( ) - ( int )move.x, rect->getLy( ), rect->getRx( ) - ( int )move.x, rect->getRy( ) ) ) {//yÇ∂Ç≠ÇÃìñÇΩÇËîªíË
		if ( move.y > 0 ) {
			dif_move = rect->getRy( ) % MAP_BLOCK_SIZE;
			dif_move = -dif_move - 1;
		} else {
			dif_move = MAP_BLOCK_SIZE - ( rect->getLy( ) % MAP_BLOCK_SIZE );
		}
		rect->addVecStatic( Vector( 0, dif_move, 0 ) );
		map->hit( );
		rect->hit( );
	}


	//if ( map->getRectCol( rect->getLx( ), rect->getLy( ), rect->getRx( ), rect->getRy( ) != 0 ) ) {
	//	int diff = rect->getLx( ) % MAP_BLOCK_SIZE;
	//	map->hit( );
	//	rect->hit( );
	//}

}

void ColliderManager::add( ColliderPtr col ) {
	_cols.push_back( col );
}

void ColliderManager::reset( ) {
	std::list< ColliderPtr >::iterator ite;
	for ( ite = _cols.begin( ); ite != _cols.end( ); ite++ ) {
		( *ite )->reset( );
	}
}

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
