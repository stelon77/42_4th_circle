/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 08:35:37 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/04 08:35:37 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include <iostream>

class Pony
{
    public:
        Pony(std::string const name, int const age, std::string const color, std::string const announce);
        ~Pony(void);

        void ponyPresentation(void) const;


    private:
        std::string const _name;
        int         const _age;
        std::string const _color;
        std::string const _announce;
};

#endif