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
	return "Soundplayer";
}

Soundplayer::Soundplayer( std::string resource_path ) {
	_sound = SoundPtr( new Sound( resource_path ) );
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
void Soundplayer::play( std::string file_name, int volume, bool loop, bool top ) {
	if ( getSound( file_name ) < 1 ) {
		return;
	}

	if ( volume > 0 ) {
		ChangeVolumeSoundMem( volume, getSound( file_name ) );
	}

	int top_flag = FALSE;
	if ( top ) {
		top_flag = TRUE;
	}
	if ( !loop ) {
		PlaySoundMem( getSound( file_name ), DX_PLAYTYPE_BACK, top_flag );
	} else {
		PlaySoundMem( getSound( file_name ), DX_PLAYTYPE_LOOP, top_flag );
	}

}
void Soundplayer::stop( std::string file_name ) {
	StopSoundMem( getSound( file_name ) );
}

int Soundplayer::getSound( std::string file_name ) const {
	return _sound->getSound( file_name );
}