#include <iostream>
#include <limits>
#include <cmath>

using namespace std;
const int ozPerLbs = 16;
const double lbsPerKg = 0.45359237;
const int gPerKg = 1000;
void getInput(int &pounds, double &ounces);
void changeValues(int pounds, double ounces, int &kilograms, double &grams);
void outputValues(int pounds, double ounces, int kilograms, double grams);

int main()
{
    int pounds;
    double ounces;
    int kilograms;
    double grams;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(8);
    getInput(pounds, ounces);
    changeValues(pounds, ounces, kilograms, grams);
    outputValues(pounds, ounces, kilograms, grams);
    return 0;
}

void getInput(int &pounds, double &ounces)
{
    while (cout << "Please enter the number of pounds: " && (!(cin >> pounds) || pounds <0))
    {
        cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (cout << "Please enter the number of ounces: " && (!(cin >> ounces) || ounces < 0 || ounces >= 16)){
        cout << "That's not a number greater than or equal to 0, and less than 16! Please        try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void changeValues(int pounds, double ounces, int &kilograms, double &grams)
{
    double poundsAndOunces = (ounces / ozPerLbs) + pounds;
    double tempKilograms = poundsAndOunces * lbsPerKg;
    kilograms = floor(tempKilograms);
    grams = (tempKilograms - kilograms) * gPerKg;
}

void outputValues(int pounds, double ounces, int kilograms, double grams)
{
    cout << pounds << " pounds and " << ounces << " ounces converts to " << kilograms << " kilograms and " << grams << "grams" << end;
}
