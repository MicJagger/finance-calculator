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

    // Insert / Remove Money

    void Deposit(long long amt);
    void Withdraw(long long amt);
    
    // Interest

    void CompoundMonth(bool incAge);

    // Payments

    void MakeMonthly(long long payment);
    int CalculateTime(long long payments);
    long long CalculateMonthly(unsigned int months);
    long long CalculateTotalCost(unsigned int months);

    // The Whole Shebangs

    void TheWholeShebang(long long payments);
    void AllMonths(unsigned short monthLimit);
};

#endif