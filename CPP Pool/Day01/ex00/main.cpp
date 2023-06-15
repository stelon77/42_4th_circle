/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 08:35:24 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 08:35:24 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void ponyOnTheStack(void)
{
	Pony ponystack("Robert", 12, "blue", "stack");

	ponystack.ponyPresentation();
	std::cout << "a pony has just been declared, on the stack; Its stack address is " << &ponystack << std::endl;

}

void ponyOnTheHeap(void)
{
	Pony *ponyheap;

	ponyheap = new Pony("Hildegarde", 8, "red", "heap");
	ponyheap->ponyPresentation();
	std::cout << "a pony has just been declared, on the heap; Its heap address is " << ponyheap << std::endl;
	delete ponyheap;
}

int main()
{
    int a(5);
	int *b;

	b = new int;
	*b = 6;
    std::cout << "a has just been declared, on the stack; Its stack address is " << &a << std::endl;
    std::cout << "b has just been declared, on the heap; Its heap address is " << b << std::endl;
	std::cout << std::endl;
	std::cout << "STACK" << std::endl;
	ponyOnTheStack();
	std::cout << std::endl;
	std::cout << "HEAP" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl;
	std::cout << "END" << std::endl;
    return (0);
}