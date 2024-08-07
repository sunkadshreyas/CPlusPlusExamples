#ifndef _BANK_IMPL
#define _BANK_IMPL
#include <map>
#include <optional>

class BankingSystem {
    private:
        std::map<int, int> bankAccounts;
    public:
        bool CreateAccount(int accountID, int balance);
        std::optional<int> Deposit(int accountID, int amount);
        std::optional<int> Withdraw(int accountID, int amount);
};

#endif
