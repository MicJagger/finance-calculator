#include "balance.hpp"

long long ConvertLoan(double loan);

int main() {
    double loan = 300 * 1000;
    double interest = 5; // %

    std::cout << "Would you like to use default values?" << '\n';
    std::cout << "Y for default" <<'\n';
    std::cout << "Else for input" << '\n';
    std::string input;
    std::cin >> input;
    if (input != "Y") {
        // i am too lazy to implement proper input checking
        // "use at your own risk" this ain't no desktop software
        // either put in a proper value or watch it crash
        std::cout << "Input loan amount: " << '\n';
        std::cin >> loan;
        std::cout << "Input interest amount: " << '\n';
        std::cin >> interest;
    }
    std::cout << std::endl;

    Balance balance = Balance(ConvertLoan(loan), interest);
    balance.AllMonths(THIRTY_YEARS, THOUSANDS);

    return 0;
}

long long ConvertLoan(double loan) {
    return round(loan * 100);
}
