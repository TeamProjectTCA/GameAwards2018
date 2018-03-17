#pragma once
#include "const.h"
#include "mathmatics.h"

class Collider {
public:
	Collider( );
	virtual ~Collider( );

public:
	virtual void draw( ) { };
	void setType( COL_TYPE type );
	void setMove( Vector move );
	void addVecStatic( Vector vec );
	void addVecDynamic( Vector vec );
	void hit( );
	void reset( );
	void fin( );

	COL_TYPE getType( ) const;
	Vector getMove( );
	Vector getVecStatic( );
	Vector getVecDynamic( );
	bool isHit( ) const;
	bool isFin( ) const;

private:
	COL_TYPE _type;
	bool _hit;
	bool _fin;

	Vector _move;
	Vector _vec_static;	//絶対に動かないオブジェクトからの戻すべきベクトル
	Vector _vec_dynamic;//動いているオブジェクトからの戻すべきベクトル

};

