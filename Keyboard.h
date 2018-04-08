#pragma once
#include "Base.h"
#include <unordered_map>
#include <vector>
#include <string>

PTR( Keyboard );

class Keyboard : public Base {
public:
	static KeyboardPtr getTask( );
	static std::string getTag( );

public:
	Keyboard( );
	virtual ~Keyboard( );

public:
	void initialize( );
	void finalize( );
	void update( );

public:
	int getState( std::string key );
	std::string getString( );
	bool getKeyUp( std::string key );
	bool getKeyDown( std::string key );

private:
	std::unordered_map< int, std::string > _key_string;
	std::unordered_map< std::string, int > _key_state;
	std::vector< std::string > _key_up;
};

