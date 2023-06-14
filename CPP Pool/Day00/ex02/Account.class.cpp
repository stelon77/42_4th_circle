/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 11:53:00 by lcoiffie          #+#    #+#             */
/*   Updated: 2021/01/01 11:54:05 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) :
	_accountIndex(getNbAccounts()), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:";
	std::cout << initial_deposit << ";created" << std::endl;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:";
	std::cout << _amount << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:";
	std::cout << _amount << ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		_amount -= withdrawal;
		std::cout << _nbWithdrawals << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (true);
}

int		Account::checkAmount( void ) const{
	return _amount;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:";
	std::cout << _amount << ";deposits:"<< _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buffer[40];

	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime (buffer,40,"[%Y%m%d_%H%M%S]",timeinfo);
	std::cout << buffer;
}

Account::Account( void ){
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
