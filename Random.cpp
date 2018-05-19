#include "Random.h"
#include "MersenneTwister.h"
#include <time.h>

const unsigned long RANGE_MAX_ULONG = 0xffffffff;
const long RANGE_MAX_LONG = 0x7fffffff;

Random::Random( ) :
_min( 0 ),
_max( RANGE_MAX_ULONG - 1 ),
_setting_range( false ) {
	init_genrand( ( unsigned int )time( NULL ) );
}

Random::~Random( ) {
}

void Random::setRange( unsigned long min, unsigned long max ) {
	_setting_range = true;
	_min = min;
	_max = max;

	if ( _max == RANGE_MAX_ULONG ) {
		_max = RANGE_MAX_ULONG - 1;
	}
}

void Random::setIgnore( unsigned long ignore ) {
	_ignore_long.push_back( ignore );
}

void Random::setIgnore( double ignore ) {
	_ignore_double.push_back( ignore );
}

void Random::resetRange( ) {
	_min = 0;
	_max = RANGE_MAX_ULONG - 1;
}

void Random::resetIgnore( ) {
	std::vector< unsigned long >( ).swap( _ignore_long );
	std::vector< double >( ).swap( _ignore_double );
}

unsigned long Random::getInt32( ) const {
	unsigned long num = genrand_int32( ) % ( _max - _min + 1 ) + _min;

	if ( isReplay( num ) ) {
		return getInt32( );
	} else {
		return num;
	}
}

long Random::getInt31( ) const {
	long num = 0;
	if ( _min >= RANGE_MAX_LONG || _max >= RANGE_MAX_LONG ) {
		num = genrand_int31( );
	} else {
		num = genrand_int31( ) % ( _max - _min + 1 ) + _min;
	}

	if ( isReplay( ( unsigned long )num ) ) {
		return getInt31( );
	} else {
		return num;
	}
}

double Random::getRealOne( ) const {
	double num = genrand_real1( );

	if ( isReplay( num ) ) {
		return getRealOne( );
	} else {
		return num;
	}
}

double Random::getRealTwo( ) const {
	double num = genrand_real2( );

	if ( isReplay( num ) ) {
		return getRealTwo( );
	} else {
		return num;
	}
}

double Random::getRealThree( ) const {
	double num = genrand_real3( );

	if ( isReplay( num ) ) {
		return getRealThree( );
	} else {
		return num;
	}
}

double Random::getRes53( ) const {
	double num = genrand_res53( );

	if ( isReplay( num ) ) {
		return getRes53( );
	} else {
		return num;
	}
}

bool Random::isReplay( unsigned long num ) const {
	for ( unsigned long i = 0; i < ( unsigned long )_ignore_long.size( ); i++ ) {
		if ( num != _ignore_long[ i ] ) {
			continue;
		}
		return true;
	}
	return false;
}

bool Random::isReplay( double num ) const {
	// ¬”‘æŽOˆÊ‚Ü‚Å‚Ì‹ßŽ—’l‚Å”»’è
	for ( unsigned long i = 0; i < ( unsigned long )_ignore_double.size( ); i++ ) {
		if ( ( int )( num * 1000 ) != ( int )( _ignore_double[ i ] * 1000 ) ) {
			continue;
		}
		return true;
	}
	return false;
}