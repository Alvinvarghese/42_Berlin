#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawls:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
	_nbAccounts++;
	return;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed:" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";

	_amount -= withdrawal;
	if (checkAmount())
	{
		_amount += withdrawal;
		std::cout << "withdrawl:refused" << std::endl;
		return false;
	}
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	if (_amount < 0)
		return 1;
	return 0;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawls:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t current_time_ptr;
	struct tm *t_stmp; // a structure type that holds calendar time.a structure type that holds calendar time.

	std::time(&current_time_ptr);		   // retrieves the current calendar time and stores it in current_time_pt
	t_stmp = localtime(&current_time_ptr); // converts the calendar time to local time and stores it in t_stmp
	std::cout << "[";
	std::cout << t_stmp->tm_year + 1900;									  // year
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;	  // month 01 - 12
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_"; // day 01 - 31
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
	std::cout << "]";
}