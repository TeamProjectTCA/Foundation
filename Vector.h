#pragma once
#include <math.h>

struct Vector {

	double x;
	double y;
	double z;

	Vector( ) :
		x( 0 ),
		y( 0 ),
		z( 0 ) {
	}

	Vector( double input_x, double input_y, double input_z = 0 ) :
		x( input_x ),
		y( input_y ),
		z( input_z ) {
	}

	virtual ~Vector( ) {
	}

	// 足し算
	inline Vector add( const Vector &vec ) {
		return Vector( 
			x + vec.x,
			y + vec.y,
			z + vec.z );
	}
	inline Vector operator+( const Vector &vec ) {
		return add( vec );
	}
	inline Vector operator+=( const Vector &vec ) {
		*this = *this + vec;
		return *this;
	}

	// 引き算
	inline Vector sub( const Vector &vec ) {
		return Vector( 
			this->x - vec.x,
			this->y - vec.y,
			this->z - vec.z );
	}
	inline Vector operator-( const Vector &vec ) {
		return sub( vec );
	}
	inline Vector operator-=( const Vector &vec ) {
		*this = *this - vec;
		return *this;
	}

	// 掛け算
	inline Vector mult( const double &num ) {
		return Vector( 
			x * num,
			y * num,
			z * num );
	}
	inline Vector operator*( const double &num ) {
		return mult( num );
	}
	inline Vector operator*=( const double &num ) {
		*this = *this * num;
		return *this;
	}

	// 比較 ==
	inline bool operator==( const Vector &vec ) {
		return ( 
			x == vec.x &&
			y == vec.y &&
			z == vec.z );
	}

	// 比較 !=
	inline bool operator!=( const Vector &vec ) {
		return (
			x != vec.x ||
			y != vec.y ||
			z != vec.z );
	}

	// 距離を返す
	inline double getLength( ) const {
		double num[ 3 ] = { fabs( x ), fabs( y ), fabs( z ) };
		double max = num[ 0 ];
		for ( int i = 1; i < 3; i++ ) {
			if ( max < num[ i ] ) {
				max = num[ i ];
			}
		}
		if ( max == 0.0 ) {
			return 0;
		}

		// 超過しないように小数点ををずらす
		double x = this->x / max;
		double y = this->y / max;
		double z = this->z / max;

		return sqrt( x * x + y * y + z * z ) * max;
	}

	// 距離を返す(sqrtによる速度低下を防ぐ)
	inline double getLength2( ) const {
		return x * x + y * y + z * z;
	}

	// 正規化
	inline Vector normalize( ) {
		double len = getLength( );
		Vector normal = Vector( x / len, y / len, z / len );

		return normal;
	}

	// 内積
	inline double dot( const Vector &vec ) {
		return x * vec.x + y * vec.y + z * vec.z;
	}
};