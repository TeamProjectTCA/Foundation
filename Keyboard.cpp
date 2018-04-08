#include "Keyboard.h"
#include "DxLib.h"
#include "Manager.h"
#include <errno.h>
#include <assert.h>

const int KEY_MAX = 256;

KeyboardPtr Keyboard::getTask( ) {
	return std::dynamic_pointer_cast< Keyboard >( Manager::getInstance( )->getTask( getTag( ) ) );
}

std::string Keyboard::getTag( ) {
	return "KEYBOARD";
}

Keyboard::Keyboard( ) {
	_key_string[ KEY_INPUT_0         ] = "0";
	_key_string[ KEY_INPUT_1         ] = "1";
	_key_string[ KEY_INPUT_2         ] = "2";
	_key_string[ KEY_INPUT_3         ] = "3";
	_key_string[ KEY_INPUT_4         ] = "4";
	_key_string[ KEY_INPUT_5         ] = "5";
	_key_string[ KEY_INPUT_6         ] = "6";
	_key_string[ KEY_INPUT_7         ] = "7";
	_key_string[ KEY_INPUT_8         ] = "8";
	_key_string[ KEY_INPUT_9         ] = "9";
	_key_string[ KEY_INPUT_A         ] = "a";
	_key_string[ KEY_INPUT_B         ] = "b";
	_key_string[ KEY_INPUT_C         ] = "c";
	_key_string[ KEY_INPUT_D         ] = "d";
	_key_string[ KEY_INPUT_E         ] = "e";
	_key_string[ KEY_INPUT_F         ] = "f";
	_key_string[ KEY_INPUT_G         ] = "g";
	_key_string[ KEY_INPUT_H         ] = "h";
	_key_string[ KEY_INPUT_I         ] = "i";
	_key_string[ KEY_INPUT_J         ] = "j";
	_key_string[ KEY_INPUT_K         ] = "k";
	_key_string[ KEY_INPUT_L         ] = "l";
	_key_string[ KEY_INPUT_M         ] = "m";
	_key_string[ KEY_INPUT_N         ] = "n";
	_key_string[ KEY_INPUT_O         ] = "o";
	_key_string[ KEY_INPUT_P         ] = "p";
	_key_string[ KEY_INPUT_Q         ] = "q";
	_key_string[ KEY_INPUT_R         ] = "r";
	_key_string[ KEY_INPUT_S         ] = "s";
	_key_string[ KEY_INPUT_T         ] = "t";
	_key_string[ KEY_INPUT_U         ] = "u";
	_key_string[ KEY_INPUT_V         ] = "v";
	_key_string[ KEY_INPUT_W         ] = "w";
	_key_string[ KEY_INPUT_X         ] = "x";
	_key_string[ KEY_INPUT_Y         ] = "y";
	_key_string[ KEY_INPUT_Z         ] = "z";
	_key_string[ KEY_INPUT_MINUS     ] = "-";
	_key_string[ KEY_INPUT_PERIOD    ] = ".";
	_key_string[ KEY_INPUT_SLASH     ] = "/";
	_key_string[ KEY_INPUT_NUMPAD0   ] = "0";
	_key_string[ KEY_INPUT_NUMPAD1   ] = "1";
	_key_string[ KEY_INPUT_NUMPAD2   ] = "2";
	_key_string[ KEY_INPUT_NUMPAD3   ] = "3";
	_key_string[ KEY_INPUT_NUMPAD4   ] = "4";
	_key_string[ KEY_INPUT_NUMPAD5   ] = "5";
	_key_string[ KEY_INPUT_NUMPAD6   ] = "6";
	_key_string[ KEY_INPUT_NUMPAD7   ] = "7";
	_key_string[ KEY_INPUT_NUMPAD8   ] = "8";
	_key_string[ KEY_INPUT_NUMPAD9   ] = "9";
	_key_string[ KEY_INPUT_MULTIPLY  ] = "*";
	_key_string[ KEY_INPUT_ADD       ] = "+";
	_key_string[ KEY_INPUT_SUBTRACT  ] = "-";
	_key_string[ KEY_INPUT_DECIMAL   ] = ".";
	_key_string[ KEY_INPUT_DIVIDE    ] = "/";
	_key_string[ KEY_INPUT_SPACE     ] = " ";

	_key_state[ "0" ] = 0;
	_key_state[ "1" ] = 0;
	_key_state[ "2" ] = 0;
	_key_state[ "3" ] = 0;
	_key_state[ "4" ] = 0;
	_key_state[ "5" ] = 0;
	_key_state[ "6" ] = 0;
	_key_state[ "7" ] = 0;
	_key_state[ "8" ] = 0;
	_key_state[ "9" ] = 0;
	_key_state[ "a" ] = 0;
	_key_state[ "b" ] = 0;
	_key_state[ "c" ] = 0;
	_key_state[ "d" ] = 0;
	_key_state[ "e" ] = 0;
	_key_state[ "f" ] = 0;
	_key_state[ "g" ] = 0;
	_key_state[ "h" ] = 0;
	_key_state[ "i" ] = 0;
	_key_state[ "j" ] = 0;
	_key_state[ "k" ] = 0;
	_key_state[ "l" ] = 0;
	_key_state[ "m" ] = 0;
	_key_state[ "n" ] = 0;
	_key_state[ "o" ] = 0;
	_key_state[ "p" ] = 0;
	_key_state[ "q" ] = 0;
	_key_state[ "r" ] = 0;
	_key_state[ "s" ] = 0;
	_key_state[ "t" ] = 0;
	_key_state[ "u" ] = 0;
	_key_state[ "v" ] = 0;
	_key_state[ "w" ] = 0;
	_key_state[ "x" ] = 0;
	_key_state[ "y" ] = 0;
	_key_state[ "z" ] = 0;
	_key_state[ "-" ] = 0;
	_key_state[ "." ] = 0;
	_key_state[ "/" ] = 0;
	_key_state[ "0" ] = 0;
	_key_state[ "1" ] = 0;
	_key_state[ "2" ] = 0;
	_key_state[ "3" ] = 0;
	_key_state[ "4" ] = 0;
	_key_state[ "5" ] = 0;
	_key_state[ "6" ] = 0;
	_key_state[ "7" ] = 0;
	_key_state[ "8" ] = 0;
	_key_state[ "9" ] = 0;
	_key_state[ "*" ] = 0;
	_key_state[ "+" ] = 0;
	_key_state[ "-" ] = 0;
	_key_state[ "." ] = 0;
	_key_state[ "/" ] = 0;
	_key_state[ " " ] = 0;
}

Keyboard::~Keyboard( ) {
}

void Keyboard::initialize( ) {
}

void Keyboard::finalize( ) {
}

void Keyboard::update( ) {
	std::vector< std::string >( ).swap( _key_up );

	char key_c[ KEY_MAX ] = { };
	GetHitKeyStateAll( key_c );

	for ( int i = 0; i < KEY_MAX; i++ ) {
		if ( _key_string.find( i ) != _key_string.end( ) ) {
			std::string str = _key_string[ i ];

			if ( _key_state.find( str ) == _key_state.end( ) ) {
				errno_t not_find_keycode = 0;
				assert( not_find_keycode );
			}

			if ( key_c[ i ] ) {
				_key_state[ str ]++;
			} else {
				if ( _key_state[ str ] != 0 ) {
					_key_up.push_back( str );
				}
				_key_state[ str ] = 0;
			}
		}
	}
}

int Keyboard::getState( std::string key ) {
	if ( _key_state.find( key ) != _key_state.end( ) ) {
		return _key_state[ key ];
	}
	return 0;
}

std::string Keyboard::getString( ) {
	std::unordered_map< std::string, int >::iterator ite;
	ite = _key_state.begin( );
	for ( ite; ite != _key_state.end( ); ite++ ) {
		if ( ite->second == 1 ) {
			return ite->first;
		}
	}

	return "";
}

bool Keyboard::getKeyUp( std::string key ) {
	int size = ( int )_key_up.size( );
	for ( int i = 0; i < size; i++ ) {
		if ( _key_up[ i ] == key ) {
			return true;
		}
	}

	return false;
}

bool Keyboard::getKeyDown( std::string key ) {
	if ( _key_state.find( key ) != _key_state.end( ) ) {
		if ( _key_state[ key ] == 1 ) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}