#pragma once
#include "smart_ptr.h"
#include <string>
#include <unordered_map>

PTR( Sound );

class Sound {
public:
	Sound( std::string path );
	virtual ~Sound( );

public:
	void findFile( std::string path );
	int getSound( std::string file_name ) const;

private:
	std::string _path;
	std::unordered_map< std::string, int > _sounds;
};