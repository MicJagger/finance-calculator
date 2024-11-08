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
        std::cout << "Type: Deposit" << '\n';
        std::cout << "Amount: $"; 
        this->PrintBalance(false);
        std::cout << '\n';
        std::cout << "Age: " << age << " months" << '\n';
    }
    else {
        std::cout << "Type: Debt" << '\n';
        std::cout << "Amount: $"; 
        this->PrintBalance(false);
        std::cout << '\n';
        std::cout << "Age: " << age << " months" << '\n';
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
    amount += amt;
}

void Balance::Withdraw(long long amt) {
    amount -= amt;
}

void Balance::CompoundMonth(bool incAge) {
    double monthlyInterest = 1 + ((annualInterest / 12) / 100);
    amount = round(pow((double)amount, monthlyInterest));
    if (incAge) {
        age++;
    }
}

void Balance::MakeMonthly(long long payment) {
    this->CompoundMonth(true);
    amount -= payment;
}

int Balance::CalculateTime(long long payments) {
    int time = 0;
    long long tempAmount = amount;
    double monthlyInterest = 1 + ((annualInterest / 12) / 100);
    if (payments <= (double)abs(amount) * (annualInterest / 1200)) {
        std::cout << "Payment not enough! Must be above ";
        std::cout << (double)abs(amount) * (annualInterest / 1200);
        std::cout << " in order to overcome interest" << '\n';
        return -1;
    }
    while (true) {
        tempAmount = round(pow((double)amount, monthlyInterest));
        tempAmount += payments;
        time++;
        if (tempAmount <= 0) {
            return time;
        }
    }
}

long long Balance::CalculateMonthly(unsigned int months) {
    // thanks to 
    // https://www.bankrate.com/mortgages/mortgage-calculator/#calculate-mortgage-payment
    // for the formula
    if (months == 0) {
        return amount;
    }
    double monthlyRate = ((annualInterest / 12) / 100);
    double compounded = pow(1 + monthlyRate, months);
    double temp = compounded - 1;
    temp = monthlyRate * compounded / temp;
    return round((double)abs(amount) * temp);
}

long long Balance::CalculateTotalCost(unsigned int months) {
    return this->CalculateMonthly(months) * months;
}

void Balance::TheWholeShebang(long long payments) {
    if ((double)abs(amount) * (annualInterest / 1200) >= payments) {
        std::cout << "Payment not enough! Must be above ";
        std::cout << (double)abs(amount) * (annualInterest / 1200);
        std::cout << " in order to overcome interest" << '\n';
        return;
    }
    std::cout << "Incomplete" << '\n';
}

void Balance::AllMonths(unsigned short monthLimit, int verticalOffset) {
    std::vector<long long> paymentAmounts;
    std::vector<long long> totalAmounts;
    long long payment;
    for (int i = 0; i <= monthLimit; i++) {
        payment = this->CalculateMonthly(i);
        paymentAmounts.push_back(payment);
        totalAmounts.push_back(payment * i);
    }
    totalAmounts[0] = amount;
    std::cout << '\n' << "Monthly payments: " << '\n';
    for (int i = 0; i <= monthLimit; i++) {
        std::cout << "(" << i << ", ";
        std::cout << std::fixed << std::setprecision(3) << (double)paymentAmounts[i] / 100 / (double)verticalOffset;
        std::cout << ")";
        if (i % 12 == 0) {
            std::cout << '\n';
        }
        else {
            std::cout << ", ";
        }
    }
    std::cout << '\n' << "Total amounts: " << '\n';
    for (int i = 0; i <= monthLimit; i++) {
        std::cout << "(" << i << ", ";
        std::cout << std::fixed << std::setprecision(3) << (double)totalAmounts[i] / 100 / (double)verticalOffset;
        std::cout << ")";
        if (i % 12 == 0) {
            std::cout << '\n';
        }
        else {
            std::cout << ", ";
        }
    }
}
