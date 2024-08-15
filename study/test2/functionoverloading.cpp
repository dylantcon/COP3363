//
// Function overloading is the name for a type of behavior
// exhibited by functions in C++. To "overload" a given
// function, is to have multiple functions with the same
// identifier, that are distinguishable by the compiler
// because they have different parameter lists. For example,
// see the code below.
//

#include <iostream>
using namespace std;

void multiply ( int& num );				// same function name, but different parameters.
void multiply ( int& num, double& dec );		// this means no syntax error! ordinarily there would have been.

int main()
{
	int number;
	double decimal;
	
	cout << "\nEnter an integer: ", cin >> number;
	cout << "\nEnter a decimal value: ", cin >> decimal;

	multiply( number );
	
	cout << "The product of the first overloaded function: " << number << endl;

	number = number / 2;

	multiply( number, decimal );
	
	cout << "The product of the second overloaded function: " << number << endl;

}

void multiply ( int& num )
{
	num = num * 2;
}

void multiply( int& num, double& dec )
{
	num = num * dec;
}
