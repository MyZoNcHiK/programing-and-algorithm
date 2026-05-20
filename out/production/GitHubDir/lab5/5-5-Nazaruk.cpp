#include <iostream>
using namespace std;

class BankAccount{
protected:
    float balance;

public:
    BankAccount(float initialBalance = 0.0) : balance(initialBalance) {}

    virtual void deposit(float amount) {
        if (amount > 0) balance += amount;
    }

    virtual bool withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    float getBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    float interestRate;

public:
    SavingsAccount(float initialBalance, float interestRate) : BankAccount(initialBalance), interestRate(interestRate) {}

    bool withdraw(float amount) override {
        if (amount > 0 && amount <= balance * 0.9) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void addInterest() {
        balance += balance * (interestRate / 100.0);
    }
};

int main() {
    BankAccount base(1000);
    SavingsAccount save(1000, 5);
    float am=0;
    cin >> am; 

    cout << "Base withdraw: " << (base.withdraw(am) ? "Операція успішна" : "Помилка, недостатньо коштів") << endl;
    cout << "Base balance: " << base.getBalance() << endl;
    cin >> am; 
    cout << "Savings withdraw: " << (save.withdraw(am) ? "Операція успішна" : "Помилка, недостатньо коштів") << endl;
    cout << "Savings balance: " << save.getBalance() << endl;

    save.addInterest();
    cout << "Savings after interest: " << save.getBalance() << endl;

    return 0;
}
