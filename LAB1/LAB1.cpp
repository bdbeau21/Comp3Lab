#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int interestRate;
    double loanAmount;
    int loanDuration;
    double monthlyPayment;
    double trueLoanAmount;
    cout << fixed;
    cout << setprecision(2);
    do
    {
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit): ";
        cin >> interestRate;
        if (interestRate == 0)
        {
            exit(0);
        }
        cout << "Please enter the amount you would like to receive: ";
        cin >> loanAmount;
        cout << "Please enter loan period in months: ";
        cin >> loanDuration;
        trueLoanAmount = loanAmount / (1.00 - ((interestRate / 100.0) * (loanDuration / 12.0)));
        monthlyPayment = trueLoanAmount / loanDuration;
        cout << "The total amount of your loan (including interest at " << interestRate      <<"% per annum) is $" << trueLoanAmount
             << ".\n";
        cout << "Your monthly payment for " << loanDuration << " months will be $" << monthlyPayment << ".\n\n";
    }while(1);
    return 0;
}
