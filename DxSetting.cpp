#include "DxSetting.h"
#include "DxLib.h"

DxSettingPtr DxSetting::_instance;

const int DEFAULT_GRAPH_WIDTH   = 1280;
const int DEFAULT_GRAPH_HEIGHT  = 720;
const int DEFAULT_GRAPH_DEPTH   = 32;
const int DEFAULT_SCREEN_WIDTH  = 1280;
const int DEFAULT_SCREEN_HEIGHT = 720;

DxSetting::DxSetting( ) {
	changeWindowMode( true );
	setWindowSize( DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT );
	setGraphMode( DEFAULT_GRAPH_WIDTH, DEFAULT_GRAPH_HEIGHT, DEFAULT_GRAPH_DEPTH );
	SetDoubleStartValidFlag( TRUE );
	SetAlwaysRunFlag( TRUE );
	DxLib_Init( );
	setDrawScreenBack( );
}

DxSetting::~DxSetting( ) {
}

void DxSetting::initialize( ) {
	if ( !_instance ) {
		_instance = DxSettingPtr( new DxSetting( ) );
	}
}

void DxSetting::finalize( ) {
	if ( _instance ) {
		_instance.reset( );
	}
}

DxSettingPtr DxSetting::getInstance( ) {
	return _instance;
}

void DxSetting::initDxLib( ) {
	DxLib_Init( );
}

void DxSetting::setDrawScreenBack( ) {
	SetDrawScreen( DX_SCREEN_BACK );
}

void DxSetting::setDrawScreen( unsigned int screen ) {
	SetDrawScreen( screen );
}

void DxSetting::changeWindowMode( bool flag ) {
	ChangeWindowMode( flag );
}

void DxSetting::setGraphMode( int width, int height, int color_bit_depth, int refresh_rate ) {
	SetGraphMode( width, height, color_bit_depth, refresh_rate );
}

void DxSetting::setWindowSize( int width, int height ) {
	SetWindowSize( width, height );
}

void DxSetting::setCameraNearFar( float near_length, float far_length ) {
	SetCameraNearFar( near_length, far_length );
}

void DxSetting::setUseLighting( bool flag ) {
	SetUseLighting( flag );
}

void DxSetting::setUseZBuffer( bool flag ) {
	SetUseZBufferFlag( flag );
	SetWriteZBufferFlag( flag );
}