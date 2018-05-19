#pragma once
#include "smart_ptr.h"
#include <vector>

PTR( Random );

/*

　メルセンヌ・ツイスタを使用

*/

class Random {
public:
	Random( );
	virtual ~Random( );

public:
	void setRange( unsigned long min, unsigned long max );
	void setIgnore( unsigned long ignore );
	void setIgnore( double ignore );
	void resetRange( );
	void resetIgnore( );

public:
	// 32ビット長整数 0x0以上0xffffffff以下
	unsigned long getInt32( ) const;

	// 31ビット長整数 0x0以上0x7fffffff以下
	long getInt31( ) const;
	
	// 一様実乱数(32ビット精度) 0以上1以下
	double getRealOne( ) const;

	// 一様実乱数(32ビット精度) 0以上1未満
	double getRealTwo( ) const;

	// 一様実乱数(32ビット精度) 0より大きく1未満
	double getRealThree( ) const;

	// 一様実乱数(53ビット精度) 0以上1未満
	double getRes53( ) const;

private:
	bool isReplay( unsigned long num ) const;
	bool isReplay( double num ) const;

private:
	bool _setting_range;
	unsigned long _min;
	unsigned long _max;
	std::vector< unsigned long > _ignore_long;
	std::vector< double > _ignore_double;
};

