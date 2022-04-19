// Divide-and-conquer worksheet
// Solution to problem #2
// Omid Ardakanian, 2022

#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>		// std::setprecision

using namespace std;

// evaluates function f at x
double f(double x) {
	return x*x - x*log2(x) - 10;
}

// evaluates function g at x
double g(double x) {
	return x*x - 4;
}

// Given a function func() that is continuous in the range
// [low, high], this will return an approximate root of func().
// Assumptions: low <= high
//
// The first parameter is a function pointer. "func"
// is the variable name, the leading "double" is the return type,
// and the arguments in parenthesis are the function parameters.
// You *need* the parenthesis around (*func) so the compiler
// knows it is a function pointer.
//
// You can declare variables with function pointer type:
// e.g., double (*fn_ptr)(double) = find_root;
double find_root(double (*func)(double), double low, double high) {
	double tol = 1e-8; // 10^(-8)

	// func(low) and func(high) must have opposite signs or be zero
	assert(func(low) * func(high) <= 0);

	// f must be a continuous function for this algorithm to work
	while (high - low > tol) {
		double mid = (high + low)/2;
		if (func(mid) == 0) {
			return mid;
		} else if (func(mid) > 0) {
			high = mid;
		} else {
			low = mid;
		}
	}
	return (high + low)/2;
}

int main() {
	double result;

	// sets the decimal precision to be used to 
	// format floating-point values on output operations
	cout << setprecision(10) << fixed;

	result = find_root(f, 1.0, 10.0);
	cout << "f(" << result << ") = " << f(result) << endl;

	result = find_root(g, 0.0, 5.0);
	cout << "g(" << result << ") = " << g(result) << endl;
	
	return 0;
}
