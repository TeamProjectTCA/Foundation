#pragma once
#include "Base.h"
#include <string>

PTR( Sound );

class Sound : public Base {
public:
	static SoundPtr getTask( );
	static std::string getTag( );

public:
	Sound( );
	virtual ~Sound( );

public:
	void initialize( );
	void finalize( );
	void update( );

public:
	bool isPlaying( int handle );
	void play( int handle, bool loop = false, bool top = false, int volume = -1 );
	void stop( int handle );

public:
	int load( std::string file_name ) const;
	void checkHandle( int handle );
};