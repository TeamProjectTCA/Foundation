#include "Drawer.h"
#include "DxLib.h"
#include "Manager.h"
#include "Image.h"
#include <errno.h>
#include <assert.h>

DrawerPtr Drawer::getTask( ) {
	return std::dynamic_pointer_cast< Drawer >( Manager::getInstance( )->getTask( getTag( ) ) );
}

std::string Drawer::getTag( ) {
	return "DRAWER";
}

Drawer::Drawer( std::string resource_path ) {
	_image = ImagePtr( new Image( resource_path ) );
}

Drawer::~Drawer( ) {
}

void Drawer::initialize( ) {
}

void Drawer::finalize( ) {
}

void Drawer::update( ) {

}

void Drawer::drawGraph( float x, float y, int handle, bool transflag ) {
	errno_t not_find_handle = handle;
	assert( not_find_handle != -1 );
	DrawGraphF( x, y, handle, transflag );
}

void Drawer::drawRotaGraph( float x, float y, double exrate, double angle, int handle, bool transflag ) {
	errno_t not_find_handle = handle;
	assert( not_find_handle != -1 );
	DrawRotaGraphF( x, y, exrate, angle, handle, transflag );
}

void Drawer::drawExtendGraph( float x1, float y1, float x2, float y2, int handle, bool transflag ) {
	errno_t not_find_handle = handle;
	assert( not_find_handle != -1 );
	DrawExtendGraphF( x1, y1, x2, y2, handle, transflag );
}

void Drawer::drawBox( float x1, float y1, float x2, float y2, int color, bool fillflag ) {
	DrawBoxAA( x1, y1, x2, y2, color, fillflag );
}

void Drawer::drawCircle( float x, float y, float r, int color, bool fillflag ) {
	DrawCircleAA( x, y, r, 32, color, fillflag );
}

void Drawer::drawLine( float x1, float y1, float x2, float y2, int color ) {
	DrawLineAA( x1, y1, x2, y2, color );
}

void Drawer::drawString( float x, float y, int color, std::string str ) {
	DrawFormatStringF( x, y, color, str.c_str( ) );
}

void Drawer::flip( ) {
	ClearDrawScreen( );
	ScreenFlip( );
}

int Drawer::getImage( std::string file_name ) const {
	return _image->getImage( file_name );
}

int Drawer::getImageWidth( std::string file_name ) const {
	return _image->getImageWidth( file_name );
}

int Drawer::getImageHeight( std::string file_name ) const {
	return _image->getImageHeight( file_name );
}