#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    this->_accountIndex = this->_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";created" << std::endl;
    this->_nbAccounts++;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void )
{
   _displayTimestamp();
   std::cout << "accounts:" << getNbAccounts() << ";";
   std::cout << "total:" << getTotalAmount() << ";";
   std::cout << "deposits:" << getNbDeposits() << ";";
   std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount;
    
    p_amount = this->_amount;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl; 
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;

    p_amount = this->_amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    if (this->_amount < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl; 
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_totalAmount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";";
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
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    static time_t timeval;
    static tm *current;

    if (_nbAccounts == 0)
    {
        time(&timeval);
        current = localtime(&timeval);
    }
    std::cout << "[" ;
    std::cout << current->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2)  << current->tm_mon + 1 << std::setfill('0') << std::setw(2) << current->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << current->tm_hour << std::setfill('0') << std::setw(2) << current->tm_min << std::setfill('0') << std::setw(2) << current->tm_sec;
    std::cout << "] " << std::flush;
}