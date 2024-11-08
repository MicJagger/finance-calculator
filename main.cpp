#include "balance.hpp"

int main() {
    double loan = 30000;
    double interest = 10; // %

    long long loanAmount = round(loan * 100);

    Balance balance = Balance(loanAmount, interest);
    balance.AllMonths(120);

    return 0;
}