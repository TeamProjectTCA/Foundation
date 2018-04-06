#pragma once
#include <string>
#include "smart_ptr.h"

PTR( Base );

class Base {
public:
	Base( );
	virtual ~Base( );

	virtual void update( ) = 0;
	virtual void initialize( ) = 0;
	virtual void finalize( ) = 0;
};