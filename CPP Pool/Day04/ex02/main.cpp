/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:38:46 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/18 21:40:40 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
ISpaceMarine* bob = new TacticalMarine;
ISpaceMarine* jim = new AssaultTerminator;
ISquad* vlc = new Squad;
vlc->push(bob);
vlc->push(jim);
for (int i = 0; i < vlc->getCount(); ++i)
{
ISpaceMarine* cur = vlc->getUnit(i);
cur->battleCry();
cur->rangedAttack();
cur->meleeAttack();
}
delete vlc;

std::cout << "\n---------\n" << std::endl;
std::cout << "\nnew squad\n\n" << std::endl;



    ISquad* blueforce = new Squad;
    ISpaceMarine* rambo = new TacticalMarine;
    ISpaceMarine* terminator = new AssaultTerminator;
    ISpaceMarine* predator = new TacticalMarine;
    ISpaceMarine* indy = new AssaultTerminator;
	std::cout << "count = " << blueforce->getCount() << std::endl;
    blueforce->push(rambo);
    blueforce->push(terminator);
    blueforce->push(predator);
    blueforce->push(indy);
    blueforce->push(terminator);

    blueforce->getUnit(1)->battleCry();
    blueforce->getUnit(2)->battleCry();

    blueforce->getUnit(3)->meleeAttack();
    blueforce->getUnit(0)->rangedAttack();

    std::cout << "count = " << blueforce->getCount() << std::endl;

	return 0;

}