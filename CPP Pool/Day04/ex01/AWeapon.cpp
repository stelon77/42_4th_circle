
#include "AWeapon.hpp"

AWeapon::AWeapon( void )
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
	_name(name),
	_apcost(apcost),
	_damage(damage)
{
}

AWeapon::~AWeapon( void )
{
}

AWeapon::AWeapon( AWeapon const & other){
	*this = other;
	return;
}

AWeapon & AWeapon::operator=(AWeapon const & other){
	if (this != &other)
	{
		_name = other._name;
		_apcost = other._apcost;
		_damage = other._damage;
	}
    return *this;
}

std::string const & AWeapon::getName( void)  const{
	return (_name);
}

int AWeapon::getAPCost( void ) const{
	return (_apcost);
}
int AWeapon::getDamage( void ) const{
	return (_damage);
}