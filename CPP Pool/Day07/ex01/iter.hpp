/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:58:37 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/02 22:49:03 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T array[], int length, void (*f)(T &))
{
	for (int i(0); i < length; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void display(T & value){
	std::cout << value << "  ";
}

template<typename T>
void increment(T & value){
	value++;
}

template<typename T>
void decrement(T & value){
	value--;
}

#endif