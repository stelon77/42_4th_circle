/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:05:50 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/16 11:57:49 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	delete me;
	std::cout << "\n-----------------------------\n";
	Character* rambo = new Character("Rambo");
	Enemy* a = new SuperMutant();
	rambo->attack(a);
	std::cout << *rambo;
	rambo->equip(pf);
	std::cout << *rambo;
	rambo->attack(a);
	std::cout << *rambo;
	rambo->attack(a);
	std::cout << *rambo;
	rambo->equip(pr);
	rambo->attack(a);
	std::cout << *rambo;
	rambo->attack(a);
	std::cout << *rambo;
	rambo->attack(a);
	std::cout << *rambo;
	rambo->attack(a);
	std::cout << *rambo;
	rambo->attack(a);
	std::cout << *rambo;
	rambo->recoverAP();
	rambo->attack(a);
	std::cout << *rambo;

	delete rambo;
	delete pf;
	delete pr;
	
	return 0;
}