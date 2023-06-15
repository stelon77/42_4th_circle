/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:02:09 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 18:20:34 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "Sorcerer.hpp"
#include "Alien.hpp"
#include "Peon.hpp"

int main()
{
Sorcerer robert("Robert", "the Magnificent");
Victim jim("Jimmy");
Peon joe("Joe");
std::cout << robert << jim << joe;
robert.polymorph(jim);
robert.polymorph(joe);
std::cout << "\n\n------------------\n\n";

Sorcerer sar("Saroumane", "the White");
Victim fro("Frodo");
Peon bil("Bilbo");
Alien leg("Legolas");

sar.polymorph(fro);
sar.polymorph(bil);
sar.polymorph(leg);
std::cout << sar << fro << bil << leg ;
fro = bil;
sar.polymorph(fro);
std::cout << sar << fro << bil << leg;


return 0;
}