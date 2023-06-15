
#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle( void )
{
}

PlasmaRifle::PlasmaRifle( PlasmaRifle const & other) :
AWeapon("Plasma Rifle", 5, 21)
{
	*this = other;
	return;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & other){
	if (this != &other)
	{
		AWeapon::operator=(other);
	}
    return *this;
}

void 	PlasmaRifle::attack( void ) const{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
