
#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy
{
public:
	Enemy(int hp, std::string const & type);
	Enemy( Enemy const & other);
	Enemy & operator=(Enemy const & other);
	virtual ~Enemy( void );

	std::string const & getType( void ) const;
	int getHP( void ) const;
	virtual void takeDamage(int damage);

protected:
	std::string _type;
	int			_hp;

private:
	Enemy( void );
};

#endif