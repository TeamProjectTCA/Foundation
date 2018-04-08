#include "DxSetting.h"
#include "DxLib.h"

DxSettingPtr DxSetting::_instance;

DxSetting::DxSetting( ) {
	ChangeWindowMode( TRUE );
	SetGraphMode( 1280, 720, 32 );
	SetDoubleStartValidFlag( TRUE );
	SetAlwaysRunFlag( TRUE );
	DxLib_Init( );
	SetDrawScreen( DX_SCREEN_BACK );
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