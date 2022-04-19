/*
  Starting code for the first part of Lecture 7's worksheet.
*/

#include <iostream>

using namespace std;

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0);

  // addition of complex numbers
  Complex operator+(Complex rhs);

  // declaring a function a "friend" means it can access
  // the private members of the class
  friend ostream& operator<<(ostream& out, Complex cplx);

private:
  double real, imag;

};

Complex::Complex(double re, double im) {
  real = re;
  imag = im;
}

Complex Complex::operator+(Complex rhs) {
  return Complex(real + rhs.real, imag + rhs.imag);
}

ostream& operator<<(ostream& out, Complex cplx) {
  // even though this is not in the scope of Complex, we can still
  // access the .real and .imag attributes because this function was
  // declared a friend
  return out << cplx.real << ' ' << cplx.imag << 'i';
}


int main() {
  Complex a(1.0, 2.0), b(3.4, 5.0);

  cout << a+b << endl;

  return 0;
}
