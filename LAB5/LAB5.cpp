#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ComplexNumber{

  private: double _real, _imag ;
  
  public:
  
  ComplexNumber() : _real(0.0), _imag(0.0) {}
  
  ComplexNumber( double r, double i ) : _real(r), _imag(i){}
  
  double Re(){ return _real ; }
  
  double Im(){ return _imag ; }
  
  void setRe( double r ) { _real = r ; }
  
  void setIm( double i ) { _imag = i ; }
  
  ComplexNumber operator+ (ComplexNumber) const ;
  
  ComplexNumber operator- (ComplexNumber) const ;
  
  ComplexNumber operator* (ComplexNumber) const ;
  
  ComplexNumber operator/ (ComplexNumber) const ;
  
  ComplexNumber operator! () const{ return ComplexNumber(this->_real, -this->_imag) ; }
  
  friend ostream& operator<< (ostream&, ComplexNumber&) ;
  
  } ;
  
  ComplexNumber ComplexNumber::operator+ (ComplexNumber c2) const { return ComplexNumber (this->_real+c2._real, this->_imag+c2._imag) ; }
  
  ComplexNumber ComplexNumber::operator- (ComplexNumber c2) const { return ComplexNumber(this->_real-c2._real, this->_imag-c2._imag) ; }
  
  ComplexNumber ComplexNumber::operator* (ComplexNumber c2) const {
  
  return ComplexNumber(this->_real*c2._real-this->_imag*c2._imag,  
  this->_imag*c2._real+this->_real*c2._imag);

  }
  
  ComplexNumber ComplexNumber::operator/ (ComplexNumber c2) const{
  
  double d = c2._real*c2._real + c2._imag*c2._imag ;
  
  return ComplexNumber((this->_real*c2._real+this->_imag*c2._imag)/d,(this->_imag*c2._real-this->_real*c2._imag)/d) ;

  }
  
  ostream &operator<< (ostream& out, ComplexNumber& c){
    
    out << c._real << "+" << c._imag << 'i' ;
    
    return out ;

  }
  
  int main(int argc, char *argv[]){
    
    ComplexNumber c1, c2(1.0, 2.0), c3(3.0, 4.0);
    
    cout << "Value of c1 (default constructor):" << endl;
    
    cout << "c1.Re() == " << c1.Re() << ", c1.Im() == " << c1.Im() << endl;
    
    cout << "Value of c2 (value constructor):" << endl;
    
    cout << "c2.Re() == " << c2.Re() << ", c2.Im() == " << c2.Im() << endl << endl;
    
    c1 = c2 + c3;
    
    cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << c1 << endl;
    
    c1 = c2 - c3; 
    
    cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << c1 << endl;	
    
    c1 = c2 * c3;
    
    cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << c1 << endl;
    
    c1 = c2 / c3;
    
    cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << c1 << endl;
    
    c1 = (c2/c3) + (c2*c3); 
    
    cout << "(c2/c3) + (c2*c3) == " << c1 << endl;
    
    c1 = !c2; 
    
    cout << "Conjugate of c2 (" << c2 << ") == " << c1 << endl << endl;
    
    vector < ComplexNumber> vc;
    
    for (int i = 0; i < 10; i++) vc.push_back(ComplexNumber(i, 2*i));
    
    cout << "Vector output using indexed for-loop:\n";
    
    for (int i = 0; i < 10; i++) cout << vc[i] << endl;
    
    cout << "\nVector output using an iterator in for-loop:\n";
    
    for (auto it = vc.begin(); it != vc.end(); ++it) cout << *it << endl;
    
    return 0 ;

  }
