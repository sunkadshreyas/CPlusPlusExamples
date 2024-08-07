#include "banking_sys_impl.hpp"

// This is syntax for saying CreateAccount is a member function of BankingSystem Class
bool BankingSystem::CreateAccount(int accountID, int amount) {
    if(bankAccounts.count(accountID) != 0) {
        return false;
    }
    bankAccounts[accountID] = 0;
    return true;
}

std::optional<int> BankingSystem::Deposit(int accountID, int amount) {
    if(bankAccounts.count(accountID) == 0) {
        return std::nullopt;
    }
    bankAccounts[accountID] += amount;
    return bankAccounts[accountID];
}

std::optional<int> BankingSystem::Withdraw(int accountID, int amount) {
    if(bankAccounts.count(accountID) == 0) {
        return std::nullopt;
    }
    if(bankAccounts[accountID] < amount) {
        return std::nullopt;
    }
    bankAccounts[accountID] -= amount;
    return bankAccounts[accountID];
}