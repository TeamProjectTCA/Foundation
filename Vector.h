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

	double length( ) const {
		double num[ 3 ] = { fabs( x ), fabs( y ), fabs( z ) };
		double max = num[ 0 ];
		for ( int i = 1; i < 3; i++ ) {
			if ( max < num[ i ] ) {
				max = num[ i ];
			}
			if ( max == 0.0 ) {
				return 0;
			}

			//’´‰ß‚µ‚È‚¢‚æ‚¤‚É¬”“_‚ð‚ð‚¸‚ç‚·
			double x = this->x / max;
			double y = this->y / max;
			double z = this->z / max;

			return sqrt( x * x + y * y + z * z ) * max;
		}

		return x * x + y * y + z * z;
	}
};