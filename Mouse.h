#pragma once
#include "Base.h"
#include <string>

PTR( Mouse );

class Mouse : public Base {
public:
	static MousePtr getTask( );
	static std::string getTag( );

public:
	Mouse( );
	virtual ~Mouse( );

public:
	void initialize( );
	void finalize( );
	void update( );

private:
	void calcLeftClick( );
	void calcRightClick( );

public:
	int getPointX( ) const;
	int getPointY( ) const;
	bool isClickDownLeft( ) const;
	bool isClickDownRight( ) const;
	bool isClickUpLeft( ) const;
	bool isClickUpRight( ) const;
	int getClickingLeft( ) const;
	int getClickingRight( ) const;

private:
	int _mouse;
	int _click_left;
	int _click_right;
	int _x;
	int _y;
	bool _clickup_left;
	bool _clickup_right;
};

