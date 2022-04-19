/*
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #5: Matrix Class
*/


#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstdlib>
#include <iostream>
using namespace std;


class Matrix
{
	public:
		Matrix(size_t num_rows, size_t num_columns, float init);
		//constructor initializing all elements to init
 
		Matrix(size_t num_rows, size_t num_columns, float* arr_ptr);
		//constructor initializing all elements to order of arr_ptr

		Matrix (const Matrix& matrix_copy);
		//copy matrix

		~Matrix();
		//destructor

		//operator overloading 
		Matrix operator+(const Matrix& rhs) const;
		Matrix operator-(const Matrix& rhs) const;
		Matrix operator*(const Matrix& rhs) const;
		Matrix operator-() const;
		Matrix transpose();

		//bracket operator overloading 
		float* operator[](const int element);
		float* operator[](int element) const;

		//insertion and extraction operator overloading
		friend istream &operator>>(istream& in, Matrix& matrix_in);
		friend ostream &operator<<(ostream& out, const Matrix& matrix_out);


	private:
		size_t num_rows; //number of rows for matrix
		size_t num_columns; //number of columns for matrix
		float** matrix; //dynamically allocated matrix array
};

#endif