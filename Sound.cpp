#include "Sound.h"
#include "DxLib.h"
#include <errno.h>
#include <assert.h>
#include <Windows.h>

Sound::Sound( std::string path ) :
_path( path ) {
	findFile( _path );
}

Sound::~Sound( ) {
}

int Sound::getSound( std::string file_name ) const {
	if ( _sounds.find( file_name ) != _sounds.end( ) ) {
		return _sounds.find( file_name )->second;
	}
	return -1;
}

void Sound::findFile( std::string path ) {
	WIN32_FIND_DATA data;
	HANDLE handle;

	path += "/";

	handle = FindFirstFile( ( path + "*" ).c_str( ), &data );

	errno_t find_handle = ( handle != INVALID_HANDLE_VALUE );
	assert( find_handle );

	do {

		if ( ( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) ) {
			//ディレクトリ	                  
			std::string file_name = data.cFileName;
			if ( file_name != "." && file_name != ".." ) {
				//再起(サブディレクトリ検索)
				findFile( ( path + file_name ) );
			}

		} else {
			//ファイル
			//名前
			std::string file_name = data.cFileName;
			std::string file_extension = data.cFileName;

			{//ファイル名を取得
				file_name = file_name.substr( 0, file_name.find_last_of( "." ) );
			}

			{//拡張子を取得
				int pos = ( int )file_extension.find_last_of( "." ) + 1;
				file_extension = file_extension.substr( pos, file_extension.length( ) - pos );
			}

			//拡張子を識別し、サウンドロード
			if ( file_extension == "mp3" || file_extension == "ogg" ) {
				_sounds[ file_name ] = LoadSoundMem( ( path + data.cFileName ).c_str( ) );
			}
		}

	} while ( FindNextFile( handle, &data ) );

	FindClose( handle );
}