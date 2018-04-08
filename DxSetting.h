#pragma once
#include "smart_ptr.h"

PTR( DxSetting );

class DxSetting {
public:
	DxSetting( );
	virtual ~DxSetting( );

public:
	static void initialize( );
	static void finalize( );
	static DxSettingPtr getInstance( );

public:
	void initDxLib( );
	void setDrawScreenBack( );
	void setDrawScreen( unsigned int screen );
	void changeWindowMode( bool flag );
	void setGraphMode( int width, int height, int color_bit_depth, int refresh_rate = 60 );
	void setWindowSize( int width, int height );

public:
	void setCameraNearFar( float near_length, float far_length );
	void setUseLighting( bool flag );

private:
	static DxSettingPtr _instance;
};

