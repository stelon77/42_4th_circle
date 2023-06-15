
#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist( void )
{
}

PowerFist::PowerFist( PowerFist const & other) :
AWeapon("Power Fist", 8, 50)
{
	*this = other;
	return;
}

PowerFist & PowerFist::operator=(PowerFist const & other){
	if (this != &other)
	{
		AWeapon::operator=(other);
	}
    return *this;
}

void 	PowerFist::attack( void ) const{
	std::cout <<  "* pschhh... SBAM! *" << std::endl;
}
