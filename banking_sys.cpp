#include<iostream>

#include "banking_sys_impl.hpp"

int main() {
    BankingSystem myBank;
    std::cout << myBank.CreateAccount(100, 100) << "\n";
    std::cout << myBank.CreateAccount(100, 100) << "\n";
    std::optional depositStatus = myBank.Deposit(200, 100);
    if(depositStatus.has_value()) {
        std::cout << "Amount deposited : " << depositStatus.value() << "\n";
    } else {
        std::cout << "Error while depositing\n";
    }
    depositStatus = myBank.Deposit(100, 100);
    if(depositStatus.has_value()) {
        std::cout << "Amount deposited : " << depositStatus.value() << "\n";
    } else {
        std::cout << "Error while depositing\n";
    }
    std::optional withdrawStatus = myBank.Withdraw(200, 100);
    if(withdrawStatus.has_value()) {
        std::cout << "Amount winthdrawn : " << withdrawStatus.value() << "\n";
    } else {
        std::cout << "Error while withdrawing\n";
    }
    withdrawStatus = myBank.Withdraw(100, 200);
    if(withdrawStatus.has_value()) {
        std::cout << "Amount winthdrawn : " << withdrawStatus.value() << "\n";
    } else {
        std::cout << "Error while withdrawing\n";
    }
    withdrawStatus = myBank.Withdraw(100, 50);
    if(withdrawStatus.has_value()) {
        std::cout << "Amount winthdrawn : " << withdrawStatus.value() << "\n";
    } else {
        std::cout << "Error while withdrawing\n";
    }
    return 0;
}