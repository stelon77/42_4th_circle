/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:37:59 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/02/03 17:21:36 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP


template <typename T>
class Array{
	public:
		Array(unsigned int const n = 0);
		Array(Array<T> const & other);
		virtual ~Array();

		Array<T> & operator=(Array<T> const & other);
		T & operator[](unsigned int index);
		const T & operator[](unsigned int index) const;

		unsigned int size(void) const;

		class  outOfRangeException: public std::exception{
			public:
				virtual const char* what() const throw() {return ("Out of the array range"); }
	};

	private:
		unsigned int _size;
		T* _tab;
};

//fonctions

// constructor
template <typename T>
Array<T>::Array(unsigned int const  n) :
_size(n), _tab(0)
{
	_tab = new T[n]();
}

//destuctor
template <typename T>
Array<T>::~Array( void){
	delete [] _tab;
}

//constructor by copy
template <typename T>
Array<T>::Array(Array<T> const & other) {
	_size = other.size();
	_tab = new T[_size]();
	if (_size > 0)
		for (unsigned int i(0); i < _size; i++)
			_tab[i] = other._tab[i];
}

//assignation
template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & other){
	if (this != &other)
	{
		delete [] _tab;
		_size = other._size;
		_tab = new T[_size]();
		if (_size > 0)
			for (unsigned int i(0); i < _size; i++)
				_tab[i] = other._tab[i];
	}
	return (*this);
}

//operator [] (constant ref and ref)
template <typename T>
T & Array<T>::operator[](unsigned int index){
	if (index >= _size)
		throw(outOfRangeException());
	return ( _tab[index] );
}

template <typename T>
const T &  Array<T>::operator[](unsigned int index) const{
	if (index >= _size)
		throw(outOfRangeException());
	return (_tab[index]);
}

//size
template <typename T>
unsigned int  Array<T>::size(void) const{
	return (_size);
}
#endif