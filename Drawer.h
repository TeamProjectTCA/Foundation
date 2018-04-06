#pragma once
#include "smart_ptr.h"
#include "Base.h"
#include <map>
#include <vector>
#include <string>

PTR( Drawer );

class Drawer : public Base {
public:
	static DrawerPtr getTask( );
	static std::string getTag( );

public:
	Drawer( );
	virtual ~Drawer( );

public:
	void initialize( );
	void finalize( );
	void update( );

public:
	void drawGraph( float x, float y, int handle, bool transflag );
	void drawRotaGraph( float x, float y, double exrate, double angle, int handle, bool transflag );
	void drawExtendGraph( float x1, float y1, float x2, float y2, int handle, bool transflag );
	void drawBox( float x1, float y1, float x2, float y2, int color, bool fillflag );
	void drawCircle( float x, float y, float r, int color, bool fillflag );
	void drawLine( float x1, float y1, float x2, float y2, int color );
	void drawString( float x, float y, int color, std::string str );
	void flip( );
};