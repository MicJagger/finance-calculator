#include "balance.hpp"

int main() {
    double loan = 300 * 1000;
    double interest = 10; // %

    long long loanAmount = round(loan * 100);

    Balance balance = Balance(loanAmount, interest);
    balance.AllMonths(THIRTY_YEARS, THOUSANDS);

    return 0;
}