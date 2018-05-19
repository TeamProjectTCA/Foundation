#pragma once
#include "smart_ptr.h"
#include <vector>

PTR( Random );

/*

�@�����Z���k�E�c�C�X�^���g�p

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
	// 32�r�b�g������ 0x0�ȏ�0xffffffff�ȉ�
	unsigned long getInt32( ) const;

	// 31�r�b�g������ 0x0�ȏ�0x7fffffff�ȉ�
	long getInt31( ) const;
	
	// ��l������(32�r�b�g���x) 0�ȏ�1�ȉ�
	double getRealOne( ) const;

	// ��l������(32�r�b�g���x) 0�ȏ�1����
	double getRealTwo( ) const;

	// ��l������(32�r�b�g���x) 0���傫��1����
	double getRealThree( ) const;

	// ��l������(53�r�b�g���x) 0�ȏ�1����
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

