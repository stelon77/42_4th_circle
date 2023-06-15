
#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"
#include <string>
#include <iostream>

class SuperMutant : public Enemy
{
public:
	SuperMutant( void );
	SuperMutant( SuperMutant const & other);
	SuperMutant & operator=(SuperMutant const & other);
	virtual ~SuperMutant( void );

	virtual void takeDamage(int damage);

private:

};


#endif