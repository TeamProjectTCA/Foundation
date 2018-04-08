#pragma once
#include "smart_ptr.h"
#include <string>
#include <unordered_map>
#include <Windows.h>

PTR( Image );

class Image {
public:
	Image( std::string path );
	virtual ~Image( );

public:
	void findFile( std::string path );
	int getImage( std::string file_name ) const;
	int getImageWidth( std::string file_name ) const;
	int getImageHeight( std::string file_name ) const;

private:
	struct ImageProperty {
		int width;
		int height;
		int handle;
	};

	std::string _path;
	std::unordered_map< std::string, ImageProperty > _images;
};

