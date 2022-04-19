/*
  Solution to the second part of Lecture 7's worksheet.

  Just making the complex value use a template argument for the type
  of the real and imaginary components.
*/

#include <iostream>

using namespace std;

template <typename T> // copy and past this a lot :)
class Complex {
public:
  // changed from 0.0 to 0 so integers types are also supported
  Complex(T re = 0, T im = 0);

  // arithmetic with complex numbers
  Complex<T> operator+(Complex<T> rhs);
  Complex<T> operator-(Complex<T> rhs);
  Complex<T> operator*(Complex<T> rhs);
  Complex<T> operator/(Complex<T> rhs);

  // unary negation
  Complex<T> operator-();

  // declaring a function a "friend" means it can access
  // the private members of the class
  // TRICKY: a friend function should have a separate template parameter
  template <typename Q>
  friend istream& operator>>(istream& in, Complex<Q>& cplx);

  template <typename Q>
  friend ostream& operator<<(ostream& out, Complex<Q> cplx);

private:
  T real, imag;

};

template <typename T>
Complex<T>::Complex(T re, T im) {
  real = re;
  imag = im;
}

template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> rhs) {
  return Complex(real + rhs.real, imag + rhs.imag);
}

template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> rhs) {
  return Complex(real - rhs.real, imag - rhs.imag);
}

template <typename T>
Complex<T> Complex<T>::operator*(Complex<T> rhs) {
  double prod_real = real*rhs.real - imag*rhs.imag;
  double prod_imag = real*rhs.imag + imag*rhs.real;
  return Complex(prod_real, prod_imag);
}

template <typename T>
Complex<T> Complex<T>::operator/(Complex<T> rhs) {
  double quo_real = real*rhs.real + imag*rhs.imag;
  double quo_imag = imag*rhs.real - real*rhs.imag;
  double norm = rhs.real*rhs.real + rhs.imag*rhs.imag;

  return Complex(quo_real / norm, quo_imag / norm);
}

template <typename T>
Complex<T> Complex<T>::operator-() {
  return Complex(-real, -imag);
}

template <typename T>
istream& operator>>(istream& in, Complex<T>& cplx) {
  // will extract from in to the real and then the imaginary component
  // and then return the reference to in again
  return in >> cplx.real >> cplx.imag;
}

template <typename T>
ostream& operator<<(ostream& out, Complex<T> cplx) {
  // even though this is not in the scope of Complex, we can still
  // access the .real and .imag attributes because this function was
  // declared a friend
  return out << cplx.real << ' ' << cplx.imag << 'i';
}


int main() {
  Complex<double> a(1.0, 2.0), b(3.4, 5.0);

  cout << a+b << endl;
  cout << a-b << endl;
  cout << a*b << endl;
  cout << a/b << endl;
  cout << -a << endl;

  // cin >> a >> b;
  // cout << a+b << endl;

  Complex<int> c(1, 2), d(3, 4);
  cout << c+d << endl << c*d << endl;

  return 0;
}
