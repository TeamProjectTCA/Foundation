#include "DxSetting.h"
#include "DxLib.h"

const int DEFAULT_GRAPH_WIDTH   = 1280;
const int DEFAULT_GRAPH_HEIGHT  = 720;
const int DEFAULT_GRAPH_DEPTH   = 32;
const int DEFAULT_SCREEN_WIDTH  = 1280;
const int DEFAULT_SCREEN_HEIGHT = 720;

DxSetting::DxSetting( ) :
_window_mode( TRUE ),
_window_width( DEFAULT_SCREEN_WIDTH ),
_window_height( DEFAULT_SCREEN_HEIGHT ),
_screen_width( DEFAULT_GRAPH_WIDTH ),
_screen_height( DEFAULT_GRAPH_HEIGHT ),
_draw_screen( DX_SCREEN_BACK ) {
	initialize( );
}

DxSetting::~DxSetting( ) {
}

void DxSetting::initialize( ) {
	ChangeWindowMode( _window_mode );
	SetWindowSize( _window_width, _window_height );
	SetGraphMode( _screen_width, _screen_height, DEFAULT_GRAPH_DEPTH );
	SetDoubleStartValidFlag( TRUE );
	SetAlwaysRunFlag( TRUE );
	DxLib_Init( );
	SetDrawScreen( _draw_screen );
}

void DxSetting::setDrawScreenBack( ) {
}

void DxSetting::changeWindowMode( bool flag ) {
	_window_mode = ( flag ? TRUE : FALSE );

	initialize( );
}

void DxSetting::setGraphMode( int width, int height ) {
	_screen_width = width;
	_screen_height = height;

	initialize( );
}

void DxSetting::setWindowSize( int width, int height ) {
	_window_width = width;
	_window_height = height;

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

int DxSetting::getWindowWidth ( ) const {
	return _window_width;
}

int DxSetting::getWindowHeight( ) const {
	return _window_height;
}

int DxSetting::getScreenWidth ( ) const {
	return _screen_width;
}

int DxSetting::getScreenHeight( ) const {
	return _screen_height;
}