/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:02:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/09 23:19:26 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <list>
#include <iostream>
#include <string>

int main()
{
	std::cout << "avec une liste \n";
	std::list<int> liste;
	liste.push_back (5);
	liste.push_back(17);
	std::cout << liste.back() << std::endl;
	liste.pop_back();
	std::cout << liste.size() << std::endl;
	liste.push_back(3);
	liste.push_back(5);
	liste.push_back(737);

	liste.push_back(0);
	std::list<int>::iterator it1 = liste.begin();
	std::list<int>::iterator ite1 = liste.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
	std::cout << *it1 << std::endl;
	++it1;
	}
	std::list<int> liste2(liste);
	std::cout << liste2.back() << std::endl;

	std::cout << "\nle meme programme avec mutantstack\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;

	std::cout << "\net avec des string\n";
	MutantStack<std::string> mutantstring;
	mutantstring.push("what");
	mutantstring.push("winner");
	mutantstring.push("are");
	mutantstring.push("you");
	mutantstring.push("?");
	std::cout << "le haut de la pile\n";
	std::cout << mutantstring.top() << std::endl;
	std::cout << "\nde bas en haut\n";

	MutantStack<std::string>::iterator it3 = mutantstring.begin();
	MutantStack<std::string>::iterator ite3 = mutantstring.end();
	while (it3 != ite3)
	{
	std::cout << *it3 << " ";
	++it3;
	}
	std::cout << "\n\net de presque en haut jusqu'a presque en bas ;-)\n";
	--it3;
	--it3;
	for (int i(0); i < 3; i++)
	{
		std::cout << *it3 << " ";
		--it3;
	}
	std::cout << std::endl;
	return 0;
}
