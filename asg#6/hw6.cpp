//////////////////////////////////////////////////////
// Name: Dylan T. Connolly			    //
// Section: 6					    //
// File: hw6.cpp				    //
// Asg:  #6					    //
// Date: 11/10/23				    //
// Purpose:					    //
//	This file contains integer array manip-	    //
//	ulation algorithms; the user is presented   //
//	a list of options on a menu. They can       //
//	choose to print the array, fill it with     //
//	contents, or insert/delete an integer at    //
//	a specified index. They also can reverse    //
//	the order of the indices in the array. In   //
//	addition, they can inquire the total # of   //
//	occurrences of a certain integer, or get    //
//	the sum of the first N odd integers.	    //
//						    //
//////////////////////////////////////////////////////
#include <iostream>
#include <cctype>

using namespace std;

void PrintArray (const int arr[], const int size );			// creating function prototypes according to specifications in hw6 manual
void FillArray (int arr[], const int size );				// prof. myers supplied above 2 funct
void Insert ( int arr[], const int size, int newnum, int pos );		// below are all mine, they take parameters in reqd order
void Delete ( int arr[], const int size, int pos );			// -
void Reverse ( int arr[], const int size );				// - 
int HowMany ( int arr[], const int size, int target );			// -
int SumOdds ( int arr[], const int size, int target );			// - 


int main()								// beginning of main
{

	const int SIZE = 15;						// array size
	int array[SIZE] = {0};						// initialize all indices to 0
	char uInput = 'm';						// userinput var, initialized to m for initial menu display
	int position, target, newInt;					// necessary ints to pass into functions
	bool validentry = false;					// boolean for SumOdds function, verifies a valid entry

	do {								// dowhile loop containing menu switch, while sentinel is exit key ('q')
		switch (uInput)						// switch statement, all user input is turned into lowercase by tolower(ch) by <cctype>
		{
			case 'm':					
			// menu display case, gives and receives no data
				cout << "\n\t** Given features **\nP\tPrint the array contents\nF\tFill the array (user entry)" << endl;
				cout << "\n\t** Function Tests **\nI\tInsert\nD\tDelete\nR\tReverse\nH\tHowMany\nS\tSumOdds\n\nM\tPrint this menu\nQ\tQuit this program\n";
				break;
			case 'p':
			// print array case, calls function
				PrintArray(array, SIZE);
				break;
			case 'f':
			// fill array case, calls function
				FillArray(array, SIZE);
				break;
			case 'i':
			// insert array case, takes 2 user inputs to pass then calls function
				cout << "Enter value to insert: ", cin >> newInt;
				cout << "Enter index at which to insert: ", cin >> position;
				Insert( array, SIZE, newInt, position );
				PrintArray( array, SIZE );
				break;
			case 'd':
			// delete array case, takes 1 user input to pass then calls function
				cout << "Enter index of item to delete: ", cin >> position;
				Delete( array, SIZE, position );
				PrintArray( array, SIZE );
				break;
			case 'r':
			// reverse array case, receives no data and reverses order of array contents
				Reverse(array, SIZE);
				PrintArray( array, SIZE );
				break;
			case 'h':
			// howmany array case, takes 1 user input then calls function
				cout << "Enter value to look for: ", cin >> target;
				cout << "\nThe value " << target << " appears in the list " << HowMany( array, SIZE, target ) << " times\n";
				break;
			case 's':
			// sumodds array case, takes 1 user input, performs validity check, then calls function
				do {
					cout << "How many odd numbers to add: ", cin >> target;
					if ( target < 0 || target > SIZE  )
					{
						validentry = false;
						cout << "** Invalid entry. Try again **" << endl;
					}
					else
						validentry = true;
				} while ( !validentry );
				cout << "The sum of the first " << target << " odd numbers is: " << SumOdds( array, SIZE, target ) << endl;
				break;
			default:
				cout << "\n** Not a valid menu option.  Try again **";
				if ( !cin )
					cin.clear();
				
		}
															// end of switch statement, gets next user input 
	cout << "\nEnter your menu selection: ", cin >> uInput;
	uInput = tolower( uInput );											// changes user input to lowercase to simplify switch case checking

	} while ( tolower( uInput ) != 'q' ); 										// "is their input the exit sentinel?" if so,
	
	PrintArray( array, SIZE );											// print final array

}
/* Definitions of PrintArray and FillArray below
 *  Written by Bob Myers for C++			*/

void PrintArray(const int arr[], const int size)
// this function prints the contents of the array
{
	cout << "\nThe array:\n { ";
	for (int i = 0; i < size-1; i++)	// print all but last item
		cout << arr[i] << ", ";

	cout << arr[size-1] << " }\n";		// print last item
}


void FillArray(int arr[], const int size)
// this function loads the contents of the array with user-entered values
{
	cout << "Please enter " << size 
		<< " integers to load into the array\n> ";

	for (int i = 0; i < size; i++)
		cin >> arr[i];			// enter data into array slot
}

	
void Insert( int arr[], const int size, int newnum, int pos )
// this function inserts an integer value to index 'i', moving all other values to the right
{
	if ( pos >= 0 && pos < size )
	{
		arr[size - 1] = 0;				// shifting to right, let last index = 0
		for ( int i = size - 1; i >= pos; i-- ) 	// i = final index, decrement til i = position, and arr[pos] is 0 
			arr[i] = arr[i - 1];			// this "swaps" the placeholder with the integer in index to its left, until it is in position 
		arr[pos] = newnum;				// then, replace placeholder with value
	}
}


void Delete( int arr[], const int size, int pos )
// this function deletes the integer stored in a specific index, and then shifts all of the values to the right to fill it in
{	
	if ( pos >= 0 && pos < size )
	{
		for ( int i = pos; i < size - 1; i++ )
			arr[i] = arr[i + 1];			// overwrites the specified index with the one to the right of it, up to 1 less than max index
		arr[size - 1] = 0;				// after all necessary "shifting", max index is overwritten as zero
	}
}


void Reverse( int arr[], const int size )
// this function reverses the order of the indices in the array, so 0 is size-1, size-1 is zero, etc.
{
	int temp;						// need placeholder value for swapping !
	for ( int i = 0; i < size / 2; i++ )			// integer division, because in this case, if the size is odd there is a median value that must remain undisturbed
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];			// i begins at zero, so first iteration index 0 and size - 1 - 0, second iteration, index 1 and size - 1 - 1...
		arr[size - 1 - i] = temp;
	}
}

int HowMany( int arr[], const int size, int target )
// this function counts and returns the total number of occurances of a user specified integer in an array
{
	int numTally = 0;
	for ( int i = 0; i < size; i++ )			// straight forward linear search of array, as it is rather short
	{
		if ( arr[i] == target )				// if int at index i is equivalent to target int,
			numTally++;				// increment our number of occurrences
	}
	return numTally;					// end of array; return total occurrences
}

int SumOdds( int arr[], const int size, int target )
// this function sums the first N odd numbers in the array, with N being specified by the user
{
	int oddSum = 0;
	for ( int i = 0; i < size; i++ )
	{
		if ( arr[i] % 2 != 0 )				// if mod value is not zero ( is 1 ), we know int at index i is odd. 
		{
			oddSum += arr[i];			// addition assignment of ( odd verified ) arr[i] to oddSum
			target--;				// decrement passed by value target
		}
		if ( target <= 0 )				// if target reaches 0, we have added the maximum amount of odd numbers allowed by the user
			return oddSum;
	}
	return oddSum;						// if for loop ends, there simply wasnt target number of odds, return anyway
}

