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
	void play( std::string file_name, int volume = -1, bool loop = false, bool top = false  );
	void stop( std::string file_name );

public:
	int getSound( std::string file_name ) const;

private:
	SoundPtr _sound;
};