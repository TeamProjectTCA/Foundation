#pragma once

//スクリーンサイズ
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
//解像度
const int WIDTH = 1280;
const int HEIGHT = 720;
const float WIDTH_F = ( float )WIDTH;
const float HEIGHT_F = ( float )HEIGHT;

const int FRAME = 60;
const int MINUTE = FRAME * 60;
const int TIME_OUT = FRAME * 5;
const int CONNECT_INTERVAL = FRAME * 2;

const double PI = 3.14;

const int TCP_PORT = 9850;
const int UDP_PORT = 9900;

struct NetWorkData {
};

enum MACHINE_TYPE {
	CLIENT,
	SERVER,
	TEST,
};

enum COLOR {
	BLACK,
	WHITE,
	RED,
	BLUE,
	WATER,
	YELLOW,
	PURPLE,
	COLOR_MAX,
};

enum SCENE {
	NONE_SCENE,
	ALL,
	CONNECT,
	TITLE,
	SCENE_MAX,
};

enum IMAGE {
	NONE_IMAGE,
	IMAGE_DIR_MAX
};

enum SOUND {
	NONE_SOUND,
	SOUND_MAX
};