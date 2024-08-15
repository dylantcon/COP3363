// this is a file covering the basic aspects of pointers, including declaration,
// initialization, dereferencing, and basic pointer arithmetic. please note that
// a pointer can only be assigned to a variable of the same type. when declaring
// a pointer, you must first list the data type, and then an identifying name.

#include <iostream>
#include <string>
using namespace std;

void SquareByAddress( long * longptr )
{
	*longptr = (*longptr) * (*longptr);
}

int main()
{
	const int size = 5;
	int arr[size] = {1, 2, 3, 4, 5};
	int * ptr = arr;			// name of array is a pointer to the first element in the array
	
	for ( int i = 0; i < size; i++ )
		cout << "\nElement #" << *( ptr + i );	// moves through each element of the array, and prints it

	ptr = 0;				// assigning pointer to null
	int number = 0;
	ptr = &number;				// address of operator ( & )
	
	cout << "\nPointer is now assigned to a single int variable initialized to zero. It will be incremented to 9.";

	for ( int i = 0; i < 10; i++ )
	{
		cout << endl << *ptr;
		(*ptr)++;			// incrementing the target located at address ptr
	}
	cout << endl << "Now, the int pointer is set to null and a new string pointer is made. We use pointer arithmetic to go from the first item in a string array, to the fourth item by adding 3." << endl;
	ptr = 0;

		
	string list[] = {"First item", "Second item", "Third item", "Fourth item", "Fifth item"};
	string * sptr = list;

	cout << endl << *sptr;
	sptr = sptr + 3;			// moves the equivalent of three strings' worth of memory forward, leaving the pointer assigned to the fourth element in the array
	
	cout << endl << *sptr << endl;		// prints the change to the terminal
	
	sptr = 0;

	cout << endl << "Now, we will square a long integer by itself, this function's values will imitate exactly that of y = x^2, until inevitably the calculation exceeds the maximum value of a long." << endl;
	long longnumber = 2;
	long * longptr = &longnumber;
	for ( int i = 0; i <= 8; i++ )
	{
		cout << longnumber << " ---> ";
		SquareByAddress( longptr );
		cout << longnumber << endl;
	}
	
	longptr = 0;
	cout << endl;
}

