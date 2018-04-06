#pragma once
#include "smart_ptr.h"
#include <string>
#include <map>
#include <Windows.h>

PTR( Image );

class Image {
public:
	Image( std::string path );
	virtual ~Image( );

public:
	void findFile( std::string path );
	int getImage( std::string file_name );

private:
	std::string _path;
	std::map< std::string, int > _images;
};

