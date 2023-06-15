/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:05:57 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/30 18:24:20 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

std::string randomString(int const length){
	std::string alphaNum = "abcdefghijklmnopqrstuvwABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string ret;
	int n = alphaNum.size();

	for (int i = 0; i < length; i++)
		ret += alphaNum[(rand() % n)];
	std::cout << "Random string : " << ret << std::endl; // affichage du string
	return (ret);
}

int randomInt(void){
	int a = (rand());

	std::cout << "Random int : " << a << std::endl;	//affichage du int
	return (a);
}

void * serialize(void){
	char *raw = new char[20];
	std::string s = randomString(8);


	for (int i = 0; i < 8; i++)
		raw[i] = s[i];

	*(reinterpret_cast<int*>(raw + 8)) = randomInt();

	s = randomString(8);

	for (int i = 0; i < 8; i++)
		raw[i + 12] = s[i];
	return (raw);
}

Data * deserialize(void * raw){
	char* raw2 = reinterpret_cast<char*>(raw);
	Data* lolo = new Data;

	for (int i = 0; i < 8; i++)
	{
		lolo->s1 += *raw2;
		raw2++;
	}
	lolo->n = *(reinterpret_cast<int*>(raw2));
	raw2 += 4;
	for (int i = 0; i < 8; i++)
	{
		lolo->s2 += *raw2;
		raw2++;
	}
	return (lolo);
}

int main()
{
	srand(time(0));

	std::cout << "-------------serialize---------------\n\n";
	void* raw= serialize();

	std::cout << "\n\n------------deserialize---------------\n\n";
	Data* data = deserialize(raw);

	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << "\n" <<std::endl;

	delete data;
	delete [] reinterpret_cast<char*>(raw);
	return (0);
}