#pragma once
#ifndef _BALANCE_HPP
#define _BALANCE_HPP

#include "const-includes.hpp"

class Balance {
    long long amount;
    double annualInterest;
    unsigned int age;
public:
    Balance();
    Balance(long long amt);
    Balance(long long amt, double annInt);
    ~Balance();
    // Getters and Setters
    long long GetAmount();
    double GetInterest();
    void SetAmount(long long amt);
    void SetInterest(double annInt);
    void ResetAge();
    // Display
    void PrintInfo();
    void PrintBalance(bool asNegative);
    // Rest of Functions
    void Deposit(long long amt);
    void Withdraw(long long amt);
};

#endif