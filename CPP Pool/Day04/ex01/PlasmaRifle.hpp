
#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <string>
#include <iostream>

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle( void );
	PlasmaRifle( PlasmaRifle const & other);
	PlasmaRifle & operator=(PlasmaRifle const & other);
	virtual ~PlasmaRifle( void );

	virtual void 	attack( void ) const;

};


#endif