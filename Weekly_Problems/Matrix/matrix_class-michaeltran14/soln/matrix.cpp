/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #5: Matrix Class
*/

#include "matrix.h"
/*----------------------------------------------------------------------------------------------------
	Description: 
		The constructor to initializes all the elements in the created matrix to the float init value.

	Arguments:
		num_rows (size_t): the number of rows in the created matrix.
		num_columns (size_t): the number of columns in the created matrix.
		init (float): initializing float value where all elements of the matrix is set to.

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/

Matrix::Matrix(size_t num_rows, size_t num_columns, float init){
	this->num_rows = num_rows; //new matrix rows equals num_rows
	this->num_columns = num_columns; //new matrix columns equals num_columns

	//dynamically allocating a new array with the amount of num_rows elements
	matrix = new float*[this->num_rows];

	//iterating over the num_rows of new matrix
	for (size_t r = 0; r < this->num_rows; r++){
		//make a new float array in each index with size of the matrix's num_columns
		matrix[r] = new float[this->num_columns];
		for (size_t c = 0; c < this->num_columns; c++){
			matrix[r][c] = init; 
		}
	}
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		The constructor that initializes the newly created matrix to be filled with the elements in 
			the floating pointer array arr_ptr.
	Arguments:
		num_rows (size_t): the number of rows in the created matrix.
		num_columns (size_t): the number of columns in the created matrix.
		arr_ptr (float*): array of values that fills the elements in the created matrix

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/

Matrix::Matrix(size_t num_rows, size_t num_columns, float* arr_ptr){
	this->num_rows = num_rows; 
	this->num_columns = num_columns;
	int count = 0;

	matrix = new float*[this->num_rows];

	for (size_t r = 0; r < this->num_rows; r++){
		matrix[r] = new float[this->num_columns];
		for (size_t c = 0; c < this->num_columns; c++){
			matrix[r][c] = arr_ptr[count]; //the elements are set in the order in arr_ptr
			count += 1; //increase the count by another index
		}
	}
	
}
/*----------------------------------------------------------------------------------------------------
	Description: 
		Copy constructor, makes a deep copy of the matrix.

	Arguments:
		matrix_copy (const Matrix&): the matrix that is supposed to be copied

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/

Matrix::Matrix(const Matrix& matrix_copy){
	this->num_rows = matrix_copy.num_rows; 
	this->num_columns = matrix_copy.num_columns;

	matrix = new float*[this->num_rows];

	for (size_t r = 0; r < this->num_rows; r++){
		matrix[r] = new float[this->num_columns];
		for (size_t c = 0; c < this->num_columns; c++){
			matrix[r][c] = matrix_copy.matrix[r][c];
		}
	}
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Destructor, free the memory.

	Arguments:
		No arguments.

	 Returns: 
	 	Does not return anything.
----------------------------------------------------------------------------------------------------*/

Matrix::~Matrix(){
	for (size_t r = 0; r < num_rows; r++){ 
		delete[] matrix[r]; //iterate through the columns of the matrix, deleting each array present in the index
	}
	delete[] matrix; //delete the matrix array
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Operator overloading +; allows for matrix addition, adds both matrix elements and sets it to the result matrix

	Arguments:
		rhs (const Matrix&): the matrix on the right hand side of the operator.

	 Returns: 
	 	result (Matrix): returns the resulting matrix.
----------------------------------------------------------------------------------------------------*/

Matrix Matrix::operator+(const Matrix& rhs) const{

	Matrix result(rhs.num_rows, rhs.num_columns, 0.0); 
	for (size_t r = 0; r < rhs.num_rows; r++){
		for (size_t c = 0; c < rhs.num_columns; c++){
			result.matrix[r][c] = this->matrix[r][c] + rhs.matrix[r][c];
		}
	}
	return result;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Operator overloading -: allows for matrix subtraction, does the difference between both matrices elements

	Arguments:
		rhs (const Matrix&): the matrix on the right hand side of the operator.

	 Returns: 
	 	result (Matrix): returns resulting matrix that has same dimensions of the two matrices.
----------------------------------------------------------------------------------------------------*/

Matrix Matrix::operator-(const Matrix& rhs) const{
	Matrix result(rhs.num_rows,rhs.num_columns, 0.0);
	for (size_t r = 0; r < rhs.num_rows; r++){
		for (size_t c = 0; c < rhs.num_columns; c++){
			result.matrix[r][c] = this->matrix[r][c] - rhs.matrix[r][c];
		}
	}
	return result;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Operator overloading *: allows for matrix multiplication, does the dot product between the rows and the columns of the two matrices being multiplied.

	Arguments:
		rhs (const Matrix&): the matrix on the right hand side of the operator.

	 Returns: 
	 	result (Matrix): returns resulting matrix that has the dimensions of the first matrix rows, second matrix columns.
----------------------------------------------------------------------------------------------------*/

Matrix Matrix::operator*(const Matrix& rhs) const{
	Matrix result(this->num_rows, rhs.num_columns, 0.0);

	for (size_t r = 0; r < this->num_rows; r++){ //determines placement of resulting matrix
		for (size_t c = 0; c < rhs.num_columns; c++){
			for (size_t k = 0; k < rhs.num_rows; k++){ 
				result.matrix[r][c] += this->matrix[r][k]*rhs.matrix[k][c];
			}
		}
	}
	return result;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Operator overloading -; negation function, negate all elements of the matrix.

	Arguments:
		No arguments.

	 Returns: 
	 	Returns result matrix after negation.
----------------------------------------------------------------------------------------------------*/

Matrix Matrix::operator-() const{
	Matrix result(this->num_rows,this->num_columns, 0.0);
	for (size_t r = 0; r < this->num_rows; r++){
		for (size_t c = 0; c < this->num_columns; c++){
			if (0.0-this->matrix[r][c] == 0.0) { //check if matrix element is 0.0, set it to -0.0
				result.matrix[r][c] = -0.0;
			} else {
				result.matrix[r][c] = 0.0 - this->matrix[r][c]; //set to negative element
			}
		}
	}
	return result;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Matrix tranpose.

	Arguments:
		No arguments.

	 Returns: 
	 	Tranposed result matrix.
----------------------------------------------------------------------------------------------------*/

Matrix Matrix::transpose(){
	Matrix result(this->num_columns, this->num_rows, 0.0); //result matrix created with swapped dimensions of pre-tranposed matrix
		
		for (size_t c = 0; c < result.num_columns; c++){
			for (size_t r = 0; r < result.num_rows; r++){
				result.matrix[r][c] = this->matrix[c][r]; //transpose the matrix
			}
		}
	return result;
}
/*----------------------------------------------------------------------------------------------------
	Description: 
		Bracket operator overloading.

	Arguments:
		element (const int): element to access
		element (int) const: element to access

	 Returns: 
	 	The specified element in the matrix.
----------------------------------------------------------------------------------------------------*/

float* Matrix::operator[](const int element) {
	return this->matrix[element];
}

float* Matrix::operator[](int element) const {
	return this->matrix[element];
}
/*----------------------------------------------------------------------------------------------------
	Description: 
		Insertion operator overloading.

	Arguments:
		in (input stream address): input stream
		matrix_in (Matrix): input matrix

	 Returns: 
	 	in (input stream address): new input stream
----------------------------------------------------------------------------------------------------*/

istream& operator>>(istream& in, Matrix& matrix_in){
	for (size_t	r = 0; r < matrix_in.num_rows; r++){
		for (size_t c = 0; c < matrix_in.num_columns; c++){
			in >> matrix_in.matrix[r][c];
		}
	}

	return in;
}

/*----------------------------------------------------------------------------------------------------
	Description: 
		Extraction operator overloading.

	Arguments:
		out (output stream address): output stream
		matrix_out (Matrix): output matrix

	 Returns: 
	 	out (output stream address): new output stream
----------------------------------------------------------------------------------------------------*/

ostream& operator<<(ostream& out, const Matrix& matrix_out){
	for (size_t	r = 0; r < matrix_out.num_rows; r++){
		for (size_t c = 0; c < matrix_out.num_columns; c++){
			if (c == matrix_out.num_columns-1){
				out << matrix_out.matrix[r][c]; //if columns is at the end of the row, do not add a white space
			} else {
				out << matrix_out.matrix[r][c] << " ";
			}
		}
		if (r != (matrix_out.num_rows - 1)){
			cout << endl; //if matrix_out rows not equal to the matrix row number, add newline
		}
	}
	return out;
}