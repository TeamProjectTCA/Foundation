#include "DxLib.h"
#include "Manager.h"

extern void main( );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	
	ChangeWindowMode( TRUE );
	SetGraphMode( 1280, 720, 32 );
	SetDoubleStartValidFlag( TRUE );
	SetAlwaysRunFlag( TRUE );
	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}
	SetDrawScreen( DX_SCREEN_BACK );

	Manager::initialize( );
	main( );

	ManagerPtr manager = Manager::getInstance( );
	manager->allInitialize( );
	while ( true ) {
		ProcessMessage( );
		ScreenFlip( );
		ClearDrawScreen( );

		manager->update( );

		if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
			break;
		}
	}

	Manager::finalize( );
	DxLib_End( );
	return 0;
}