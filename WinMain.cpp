#include "DxLib.h"
#include "Manager.h"
#include "DxSetting.h"

extern void main( );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	DxSetting::initialize( );
	Manager::initialize( );
	main( );

	ManagerPtr manager = Manager::getInstance( );
	manager->allInitialize( );
	while ( true ) {
		ProcessMessage( );

		manager->update( );

		if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
			break;
		}
	}

	Manager::finalize( );
	DxSetting::finalize( );
	DxLib_End( );
	return 0;
}