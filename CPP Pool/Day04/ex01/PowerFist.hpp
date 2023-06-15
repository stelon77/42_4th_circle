
#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"
#include <string>
#include <iostream>

class PowerFist : public AWeapon
{
public:
	PowerFist( void );
	PowerFist( PowerFist const & other);
	PowerFist & operator=(PowerFist const & other);
	virtual ~PowerFist( void );

	virtual void 	attack( void ) const;
};


#endif