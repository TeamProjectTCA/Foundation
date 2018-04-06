#pragma once
#include "smart_ptr.h"
#include "Base.h"
#include <map>

PTR( Manager );

class Manager {
public:
	Manager( );
	virtual ~Manager( );

public:
	static ManagerPtr getInstance( );
	static void initialize( );
	static void finalize( );

public:
	void update( );
	void allInitialize( );
	void add( std::string tag, BasePtr ptr );
	BasePtr getTask( std::string tag );
	bool isFin( ) const;

private:
	static ManagerPtr _instance;
	bool _fin;

	std::map< std::string, BasePtr > _exe;
};

