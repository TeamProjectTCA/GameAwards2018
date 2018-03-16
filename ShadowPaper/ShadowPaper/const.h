#pragma once

const short int SCREEN_WIDTH = 1280;
const short int SCREEN_HEIGHT = 720;

const short int MAP_SIZE_X = 40;
const short int MAP_SIZE_Y = 30;
const short int MAP_BLOCK_SIZE = 32;


//�V�[��
enum SCENE_NAME {
	CONTINUE,
	TITLE,
	GAME,	
	END,
};

//�����蔻��̃^�C�v
enum COL_TYPE {
	COL_MAP,
	COL_RECT,
	COL_CIRCLE,
};

//�����蔻��̃^�O
enum HIT_TAG {
};