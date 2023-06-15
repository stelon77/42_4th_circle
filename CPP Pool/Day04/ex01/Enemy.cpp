
#include "Enemy.hpp"

Enemy::Enemy( void )
{
}

Enemy::Enemy(int hp, std::string const & type):
_type(type), _hp(hp)
{
}

Enemy::~Enemy( void )
{
}

Enemy::Enemy( Enemy const & other){
	*this = other;
	return;
}


Enemy & Enemy::operator=(Enemy const & other){
	if (this != &other)
	{
		_hp = other._hp;
		_type = other._type;
	}
    return *this;
}

std::string const & Enemy::getType( void ) const{
	return (_type);
}

int Enemy::getHP( void ) const{
	return (_hp);
}

void Enemy::takeDamage(int damage){
	if (damage > 0)
		_hp -= damage;
	if (_hp < 0)
		_hp = 0;
	return ;
}
