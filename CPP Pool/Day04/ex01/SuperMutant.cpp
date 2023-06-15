
#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) :
Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant( void )
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const & other):
Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	*this = other;
	return;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & other){
	if (this != &other)
	{
		Enemy::operator=(other);
	}
    return *this;
}

void SuperMutant::takeDamage(int damage){
	if (damage > 3)
		_hp -= (damage - 3);
	if (_hp < 0)
		_hp = 0;
	return ;
}
