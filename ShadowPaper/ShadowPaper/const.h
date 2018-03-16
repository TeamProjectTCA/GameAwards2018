#pragma once

const short int SCREEN_WIDTH = 1280;
const short int SCREEN_HEIGHT = 720;

const short int MAP_SIZE_X = 40;
const short int MAP_SIZE_Y = 30;
const short int MAP_BLOCK_SIZE = 32;


//シーン
enum SCENE_NAME {
	CONTINUE,
	TITLE,
	GAME,	
	END,
};

//当たり判定のタイプ
enum COL_TYPE {
	COL_MAP,
	COL_RECT,
	COL_CIRCLE,
};

//当たり判定のタグ
enum HIT_TAG {
};