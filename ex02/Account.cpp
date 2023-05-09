#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account() : _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

// void Account::_displayTimestamp() {
//     std::time_t t = std::time(0);
//     std::tm *now = std::localtime(&t);
//     std::cout << "[" << (now->tm_year + 1900) << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
//               << std::setw(2) << std::setfill('0') << now->tm_mday << "_" << std::setw(2) << std::setfill('0')
//               << now->tm_hour << std::setw(2) << std::setfill('0') << now->tm_min << std::setw(2)
//               << std::setfill('0') << now->tm_sec << "]";
// }

void Account::_displayTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm* localTime = std::localtime(&t);
    std::cout << std::put_time(localTime, "[%Y%m%d_%H%M%S]");
}
 
void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	Account::_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout <<  " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}