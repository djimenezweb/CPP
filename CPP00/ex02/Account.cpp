#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";closed" << std::endl;
	Account::_nbAccounts++;
}

Account::Account( void ) {}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" <<getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << checkAmount()
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout	<< ";amount:" << checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << checkAmount();
	
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << checkAmount()
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	struct tm	*timer;
	time_t		current;

	time(&current);
	timer = localtime(&current);
	std::cout	<< "["
				<< timer->tm_year + 1900
				<< std::setw(2) << std::setfill('0') << timer->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << timer->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << timer->tm_hour
				<< std::setw(2) << std::setfill('0') << timer->tm_min
				<< std::setw(2) << std::setfill('0') << timer->tm_sec
				<< "] ";
}
