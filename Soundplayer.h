#pragma once
#include "Base.h"
#include <string>

PTR( Soundplayer );
PTR( Sound );

class Soundplayer : public Base {
public:
	static SoundplayerPtr getTask( );
	static std::string getTag( );

public:
	Soundplayer( std::string sound_path );
	virtual ~Soundplayer( );

public:
	void initialize( );
	void finalize( );
	void update( );

public:
	bool isPlaying( std::string file_name );
	void play( int handle, bool loop = false, bool top = false, int volume = -1 );
	void stop( int handle );

public:
	int getSound( std::string file_name ) const;
	void checkHandle( int handle );

private:
	SoundPtr _sound;
};