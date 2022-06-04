#include <iostream>
#include <string>
#include <iomanip>
#include "Account.hpp"

static void PrintAccordingToFormat(int time);

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	static int index = 0;

	this->_accountIndex = index;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "created" << std::endl;
	++index;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "closed" << std::endl;
}

//defined as static
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

//defined as static
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

//defined as static
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

//defined as static
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

//defined as static
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";

	this->_nbDeposits += 1;
	this->_amount += deposit;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;

	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";

	std::cout << "withdrawal:";
	if (Account::checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << withdrawal << ";";
	}

	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;

	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{

    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);

	std::cout << "[";

	PrintAccordingToFormat(localTime->tm_year + 1900);
	PrintAccordingToFormat(localTime->tm_mon + 1);
	PrintAccordingToFormat(localTime->tm_mday);
	std::cout << "_";
	PrintAccordingToFormat(localTime->tm_hour);
	PrintAccordingToFormat(localTime->tm_min);
	PrintAccordingToFormat(localTime->tm_sec);

	std::cout << "] ";
}

static void PrintAccordingToFormat(int time)
{
	std::cout << std::setw(2) << std::setfill('0') << time;
}
