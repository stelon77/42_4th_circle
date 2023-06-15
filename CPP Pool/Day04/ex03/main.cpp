/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:28:36 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 22:20:04 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(new Fire());

ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
me->use(0, *bob);

// time to count xp of materia
std::cout << tmp->getXP() << std::endl;
me->use(1, *bob);
std::cout << tmp->getXP() << std::endl;

//replace 0(ice) by cure
me->use(0, *bob);
me->unequip(0);
tmp = src->createMateria("cure");
me->equip(tmp);
me->use(0, *bob);

//ahah 1 is also cure
me->use(1, *bob);

//lets get fire
tmp = src->createMateria("fire");
std::cout << tmp->getXP() << std::endl;
me->equip(tmp);
me->use(2, *bob);
std::cout << tmp->getXP() << std::endl;

delete bob;
delete me;
delete src;
return 0;
}