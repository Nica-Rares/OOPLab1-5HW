#include <iostream>
#include <string>

class Bank {
private:
    std::string username = "user";
    std::string password = "pass";
    double balance;
    bool loggedIn;

public:
    Bank() : balance(0.0), loggedIn(false) {}

    void login(const std::string& user, const std::string& pass) {
        if (user == username && pass == password) {
            loggedIn = true;
            std::cout << "Login successful!\n";
        }
        else {
            std::cout << "Invalid credentials!\n";
        }
    }

    void deposit(double amount) {
        if (!loggedIn) {
            std::cout << "Please log in to perform this operation.\n";
            return;
        }
        balance += amount;
        std::cout << "Deposited: " << amount << "\n";
    }

    void withdraw(double amount) {
        if (!loggedIn) {
            std::cout << "Please log in to perform this operation.\n";
            return;
        }
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew: " << amount << "\n";
        }
        else {
            std::cout << "Insufficient balance!\n";
        }
    }

    void displayBalance() {
        if (!loggedIn) {
            std::cout << "Please log in to view your balance.\n";
            return;
        }
        std::cout << "Current balance: " << balance << "\n";
    }

    static int countUsers() {
        return 1; // Since we have one hardcoded user
    }
};

int main() {
    Bank bank;
    std::string user, pass;

    std::cout << "Enter username: ";
    std::cin >> user;
    std::cout << "Enter password: ";
    std::cin >> pass;

    bank.login(user, pass);

    bank.deposit(100.50);
    bank.withdraw(50.00);
    bank.displayBalance();

    std::cout << "Number of existing users: " << Bank::countUsers() << "\n";

    return 0;
}
