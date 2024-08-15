//
// Concept category: Functions
// Concept: Pass by value and pass by reference
// 
// Pass by value and pass by reference are different terms referring to
// the method by which a piece of data is sent in (or passed) into a
// function in the C++ programming language.
// 
// When a variable is passed by value:
// 	If the program is operating in the scope of the function,
// 	a copy of the parameter passed in is made. For example, if int num = 5,
// 	and num is passed into function( num ); another variable will be created
// 	at a different address within the system. This can result in unneeded use
// 	of computer resources, but can be necessary or beneficial in certain
// 	instances. The variable created is identical to the value passed from main,
//	but is contained at a different address. Therefore, if you alter the value
//	passed in, changes will only be reflected within the scope of the function
//	that it was passed to.
// When a variable is passed by reference:
//	If the program is operating in the scope of the function, and the variable is
//	passed by reference, there are NO COPIES MADE. Instead, the language sends the
//	function the exact memory address that the variable passed in is stored at, which
//	gives the function direct access to the original data. No copies are made, which
//	means that theoretically system resources are conserved. However, the programmer
//	must be aware that this means ANY CHANGES MADE TO THE REFERENCE VARIABLE IN THE
//	SCOPE OF THE FUNCTION WILL BE REFLECTED IN ANY OTHER FUTURE INSTANCES OF THE 
//	VARIABLE IN THE PROGRAM. This can be useful in many situations, but it is important
//	that the coder is aware of this so that the program does not behave in any unintended
//	ways.
//
// Example of pass by reference versus pass by value:

#include <iostream>
using namespace std;

void byvalue ( int a, int b );
void byreference ( int& a, int& b );

int main()
{

	int x, y;
	cout << "\nPlease enter two integers, which will be used for (x) and (y) respectively: ", cin >> x, cin >> y;
	
	byvalue(x, y);
	
	cout << "\nCurrent values of x and y (outside function scope): " << x << " , " << y;

	byreference(x, y);
	
	cout << "\nCurrent values of x and y (outside function scope): " << x << " , " << y << endl;
}


void byvalue ( int a, int b )
{
	a = a * 10;
	b = b * 10;
	cout << "\nCurrent values of a and b (inside function scope): " << a << " , " << b;
}

void byreference ( int& a, int& b )
{
	a = a * 10;
        b = b * 10;
        cout << "\nCurrent values of a and b (inside function scope): " << a << " , " << b;
}
