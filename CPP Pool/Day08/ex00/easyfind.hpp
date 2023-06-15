/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:39:49 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/06 12:35:32 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T >
typename T::iterator easyFind(T & container, int const n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw(std::exception());
	return (it);
}

#endif