#include "balance.hpp"

Balance::Balance() {
    amount = 0;
    annualInterest = 0;
    age = 0;
}

Balance::Balance(long long amt) {
    amount = amt;
    annualInterest = 0;
    age = 0;
}

Balance::Balance(long long amt, double annInt) {
    amount = amt;
    annualInterest = annInt;
    age = 0;
}

Balance::~Balance() {

}

long long Balance::GetAmount() {
    return amount;
}

double Balance::GetInterest() {
    return annualInterest;
}

void Balance::SetAmount(long long amt) {
    amount = amt;
}

void Balance::SetInterest(double annInt) {
    annualInterest = annInt;
}

void Balance::ResetAge() {
    age = 0;
}

void Balance::PrintInfo() {
    if (amount >= 0) {

    }
    else {
        std::cout << "Type: Debt" << '\n';
        std::cout << "Amount: $"; 
        this->PrintBalance(false);
        std::cout << '\n';
        std::cout << "Age: " << age << '\n';
    }
}

void Balance::PrintBalance(bool asNegative) {
    if (asNegative) {
        std::cout << amount / 100;
    }
    else {
        std::cout << abs(amount) / 100;
    }
    std::cout << "." << abs(amount) % 100;
}

void Balance::Deposit(long long amt) {
    
}

void Balance::Withdraw(long long amt) {

}
