#include "Soundplayer.h"
#include "DxLib.h"
#include "Manager.h"
#include "Sound.h"
#include <errno.h>
#include <assert.h>

SoundplayerPtr Soundplayer::getTask( ) {
	return std::dynamic_pointer_cast< Soundplayer >( Manager::getInstance( )->getTask( getTag( ) ) );
}

std::string Soundplayer::getTag( ) {
	return "SOUNDPLAYER";
}

Soundplayer::Soundplayer( std::string sound_path ) {
	_sound = SoundPtr( new Sound( sound_path ) );
}

Soundplayer::~Soundplayer( ) {
}

void Soundplayer::initialize( ) {
}

void Soundplayer::finalize( ) {
}

void Soundplayer::update( ) {
}

bool Soundplayer::isPlaying( std::string file_name ) {
	if ( CheckSoundMem( getSound( file_name ) ) == TRUE ) {
		return true;
	}
	return false;
}

void Soundplayer::play( int handle, bool loop, bool top, int volume ) {
	checkHandle( handle );

	if ( volume > 0 ) {
		ChangeVolumeSoundMem( volume, handle );
	}

	int top_flag = FALSE;
	if ( top ) {
		top_flag = TRUE;
	}
	if ( !loop ) {
		PlaySoundMem( handle, DX_PLAYTYPE_BACK, top_flag );
	} else {
		PlaySoundMem( handle, DX_PLAYTYPE_LOOP, top_flag );
	}

}

void Soundplayer::stop( int handle ) {
	StopSoundMem( handle );
}

void Soundplayer::checkHandle( int handle ) {
	errno_t not_find_handle = handle;
	assert( not_find_handle != -1 );
}

int Soundplayer::getSound( std::string file_name ) const {
	return _sound->getSound( file_name );
}