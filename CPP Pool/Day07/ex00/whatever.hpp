/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:38:26 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/01 14:48:48 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
T max(const T & a, const T & b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
T min(const T & a, const T & b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
void swap(T & a, T & b)
{
	T c = a;
	a = b;
	b = c;
}

#endif