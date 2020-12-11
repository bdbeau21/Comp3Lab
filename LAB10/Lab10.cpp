#include <iostream>
#include <string>
#include <limits>
#include <exception>

using namespace std;

const int IGNORE_SIZE = 256;
const double MAX_DOUBLE = std::numeric_limits<double>::max();

class  input_exception: public exception
{
public:
  input_exception();
  input_exception(string inputMessage) {errorMessage = inputMessage;}
  string what() {
    return errorMessage;
  }
  
private:
  string errorMessage;
};


/**
 *  Generic function to input a number, and check whether the number is within
 *  the specified bounds.
 *  If within bounds, return the input number.
 *  If not a number or not within bounds, should throw an input_error exception with the
 *  specified error message.
 */
template<typename T>
T checkInput(T lower, T upper, string message)
{
    T in;
    
    if ( !(cin >> in) || (in < lower) || (in > upper) ) {
        cin.clear();
        cin.ignore(IGNORE_SIZE, '\n');
    throw message;
    }
    
    return in;
}


class Mass {
    public:
        void setMassAvoirdupoisPounds( double ap ) { drams = ap*dramsPerAvoirdupoisPound; }
        void setMassTroyPounds( double tp ) { drams = tp*dramsPerTroyPound; }
        void setMassMetricGrams( double mg ) { drams = mg/metricGramsPerDram; }
        double getMassAvoirdupoisPounds() { return drams/dramsPerAvoirdupoisPound; }
        double getMassTroyPounds() { return drams/dramsPerTroyPound; }
        double getMassMetricGrams() { return drams*metricGramsPerDram; }
    private:
        double drams;
        const int dramsPerAvoirdupoisPound = 256;
        const int dramsPerTroyPound = 96;
        const double metricGramsPerDram = 1.7718451953125;
};


int main()
{
    int choice = -854050;
    double inputMass = -854050;
    Mass m;
    
    do {
        do{
            cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, "
                 << "3 to use grams, or 0 to exit: ";
                 
         try {
            choice = checkInput(0, 3, "That's not a number between 0 and 3!");
            if (choice != -854050) break;
          }
          catch(string e) {
            input_exception myException(e);
            cout << "Caught Exception : Try again"<< myException.what() << endl;
          }
            
            break;
            
        } while (true);
        
        switch ( choice ) {
            case 1:
                do {
                    cout << "Please enter a mass in Avoirdupois pounds: ";
                    try{
                      inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
              if (inputMass != -854050) break;
            }
            catch(string e) {
              input_exception myException(e);
              cout << "Caught Exception : Try again"<< myException.what() << endl;
            }
                    
                
            } while (true);
                m.setMassAvoirdupoisPounds( inputMass );
                break;
                
            case 2:
                do {
                    cout << "Please enter a mass in Troy pounds: ";
            
                  try
          {
            inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
            if (inputMass != -854050) break;
          }
          catch(string e)
          {
            input_exception myException(e);
            cout << "Caught Exception : Try again" << myException.what() << endl;
          }
                    
                   
                    
                } while (true);
                m.setMassTroyPounds( inputMass );
                break;
                
            case 3:
                do {
                    cout << "Please enter a mass in grams: ";
                    
                    
          try {
           inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
           if (inputMass != -854050) break;
          }
          catch(string e) {
            input_exception myException(e);
            cout << "Caught Exception : Try again"<< myException.what() << endl;
          }
 
                } while (true);
                m.setMassMetricGrams( inputMass );
                break;
                
            default:
                cout << "Thanks for using the mass conversion program!\n";
                exit( 1 );
                
        } // end switch
        
        cout << "Mass in Avoirdupois pounds is " << m.getMassAvoirdupoisPounds() << endl;
        cout << "Mass in Troy pounds is " << m.getMassTroyPounds() << endl;
        cout << "Mass in grams is " << m.getMassMetricGrams() << endl << endl;
        
    } while (true);
    
    return 0;
}
