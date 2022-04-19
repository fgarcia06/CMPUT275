/*
  Solution to the first part of Lecture 7's worksheet.
*/

#include <iostream>

using namespace std;

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0);

  // arithmetic with complex numbers
  Complex operator+(Complex rhs);
  Complex operator-(Complex rhs);
  Complex operator*(Complex rhs);
  Complex operator/(Complex rhs);

  // unary negation
  Complex operator-();

  // declaring a function a "friend" means it can access
  // the private members of the class
  friend istream& operator>>(istream& in, Complex& cplx);
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

Complex Complex::operator-(Complex rhs) {
  return Complex(real - rhs.real, imag - rhs.imag);
}

Complex Complex::operator*(Complex rhs) {
  double prod_real = real*rhs.real - imag*rhs.imag;
  double prod_imag = real*rhs.imag + imag*rhs.real;
  return Complex(prod_real, prod_imag);
}

Complex Complex::operator/(Complex rhs) {
  double quo_real = real*rhs.real + imag*rhs.imag;
  double quo_imag = imag*rhs.real - real*rhs.imag;
  double norm = rhs.real*rhs.real + rhs.imag*rhs.imag;

  return Complex(quo_real / norm, quo_imag / norm);
}

Complex Complex::operator-() {
  return Complex(-real, -imag);
}

istream& operator>>(istream& in, Complex& cplx) {
  // will extract from in to the real and then the imaginary component
  // and then return the reference to in again
  return in >> cplx.real >> cplx.imag;
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
  cout << a-b << endl;
  cout << a*b << endl;
  cout << a/b << endl;
  cout << -a << endl;

  // cin >> a >> b;
  // cout << a+b << endl;

  return 0;
}
