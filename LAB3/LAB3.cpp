#include <iostream>
#include <cmath>
using namespace std;

class Mass
{
public:
    void setMassAvoirdupoisPounds(double pounds)
    {
        Drams = pounds * 256.0;
    }
    double getMassAvoirdupoisPounds()
    {
        return (Drams / 256.0);
    }
        void setMassTroyPounds(double pounds)
    {
        Drams = pounds * 96.0;
    }
    double getMassTroyPounds()
    {
        return (Drams / 96.0);
    }
    void setMassMetricGrams(double grams)
    {
        Drams = grams / 1.7718451953125;
    }
    double getMassMetricGrams()
    {
        return (Drams * 1.7718451953125);
    }
private:
    double Drams;
};

int main(int argc, const char* argv[])
{
    Mass dram;
    int mode = -1;
    bool statusLoop = false;
    while (statusLoop == false){
        while ((cout << "Please enter 1 to use Avoirdupois Pounds, 2 to use Troy Pounds, 3 to use grams, or 0 to exit:") &&(!(cin >> mode) || mode > 3 || mode < 0)){
            cout << "Please enter a valid number between 0-3." << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            
        }
        double input;
        switch (mode)
        {
            case 1:
                while ((cout << "Please enter a mass in Avordupois Pounds: ") &&(!(cin >> input) || input < 0.0 || input < NAN)){
                    cout << "That was not a valid number, try again." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                dram.setMassAvoirdupoisPounds(input);
                cout << "Mass in Avoirdupois Pounds is: "
                     << dram.getMassAvoirdupoisPounds() << endl
                     << "Mass in Troy Pounds is: " << dram.getMassTroyPounds() << endl
                     << "Mass in Metric Grams is : " << dram.getMassMetricGrams() << endl;
                break;
            case 2:
                while ((cout << "Please enter a mass in Troy Pounds: ") &&(!(cin >> input) || input < 0.0 || input < NAN)){
                    cout << "That was not a valid number, try again." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                dram.setMassTroyPounds(input);
                cout << "Mass in Avoirdupois Pounds is: "
                     << dram.getMassAvoirdupoisPounds() << endl
                     << "Mass in Troy Pounds is: " << dram.getMassTroyPounds() << endl
                     << "Mass in Metric Grams is : " << dram.getMassMetricGrams() << endl;
                break;
            case 3:
                while ((cout << "Please enter a mass in Metric Grams: ") &&(!(cin >> input) || input < 0.0 || input < NAN)){
                    cout << "That was not a valid number, try again." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                dram.setMassMetricGrams(input);
                cout << "Mass in Avoirdupois Pounds is: "
                     << dram.getMassAvoirdupoisPounds() << endl
                     << "Mass in Troy Pounds is: " << dram.getMassTroyPounds() << endl
                     << "Mass in Metric Grams is : " << dram.getMassMetricGrams() << endl;
                break;
            default:
                statusLoop = true;
                cout << "Thanks for using the mass conversion program!" << endl;
                break;
        }
    }
    return 1;
}
