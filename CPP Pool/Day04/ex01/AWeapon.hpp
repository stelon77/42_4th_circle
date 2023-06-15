
#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>

class AWeapon
{
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon( AWeapon const & other);
	AWeapon & operator=(AWeapon const & other);
	virtual ~AWeapon( void );

	std::string const &	getName( void)  const;
	int 				getAPCost( void ) const;
	int 				getDamage( void ) const;
	virtual void 		attack( void ) const = 0;

protected:
	std::string	_name;
	int 		_apcost;
	int			_damage;

private:
	AWeapon( void );

};


#endif