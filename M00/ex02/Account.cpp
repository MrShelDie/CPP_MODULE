#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
		: _accountIndex(_nbAccounts),
		  _amount(initial_deposit),
		  _nbDeposits(0),
		  _nbWithdrawals(0) {
	++_nbAccounts;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

int Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
			  << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
			  << ";deposit:" << deposit << ";amount:" << _amount + deposit
			  << ";nb_deposits:" << _nbDeposits + 1 << "\n";
	_totalAmount += deposit;
	_amount += deposit;
	++_totalNbDeposits;
	++_nbDeposits;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (_amount >= withdrawal) {
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:" << withdrawal << ";amount:"
				  << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals + 1
				  << "\n";
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		++_totalNbWithdrawals;
		++_nbWithdrawals;
		return true;
	} else {
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << "\n";
		return false;
	}
}

void Account::_displayTimestamp( void ) {
	std::time_t time = std::time(NULL);
	if (time == (std::time_t)(-1))
		return;
	std::tm *tm = std::localtime(&time);
	if (!tm)
		return;
	std::cout << std::put_time(tm, "[%Y%m%d_%H%M%S] ");
}