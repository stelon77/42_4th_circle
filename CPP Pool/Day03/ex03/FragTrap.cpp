/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:34:10 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/11 12:28:25 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap(){
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "Visible...invisible! Visible! Invisible. Hey, how ya doin, I’m invisible" << std::endl;
}

FragTrap::FragTrap( std::string const name ) : ClapTrap(name){
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "Visible...invisible! Visible! Invisible. Hey, how ya doin, I’m ";
	std::cout << _name << " and I’m INVISIBLE! " << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "Minion, what have you DONE?!...DESTRUCTION !!!" << std::endl;
}

FragTrap::FragTrap( FragTrap const & other){
	*this = other;
	std::cout << "Visible...invisible! Visible! Invisible. Hey, how ya doin, I’m ";
	std::cout << _name << " and I’m INVISIBLE! " << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & other){
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
    return *this;
}

void	FragTrap::rangedAttack(std::string const & target) const{
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << " at range, causing " << _rangedAttackDamage << " points of damage!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) const{
	std::cout << "FR4G-TP " << _name << " attacks " << target;
	std::cout << " at melee, causing " << _meleeAttackDamage << " points of damage!" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target){
	if (_energyPoints < 25)
	{
		std::cout << "I'm out of energy !! Damn you, " << target << "!!" << std::endl;
		return;
	}
	else
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target;
		std::cout << " and shouts : " << _attackShout[rand() % 5] << std::endl;
	}
}

std::string FragTrap::_attackShout[5] = {
	"They're weak to bullets, let'shoot them",
	"You've earned it !! FIRESTOOOORM !! See you in hell, sucker !!",
	"Blow 'em apart!",
	"Hey, bandits -- FREEZE! AHAHAHAHAHAHAHAH! ",
	"There's oil everywherrrre…IGNITION !!! "
};




