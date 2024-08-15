//
// Concept category: I/O streams, file I/O
// Concept: .get() vs .getline(), and put vs standard insertion operator
// 
// In C++, there are more ways to control the flow of I/O streams than the standard
// insertion ( << ) and extraction ( >> ) operators. Ordinarily, the extraction
// operator will skip leading whitespace, until the data requested is sent into the 
// input stream. If the input stream expects 3 ints, a user can type 3 5 1 and these
// integers will be sent in without the whitespace associated with them. However, if
// this whitespace skipping behavior is not desired, one can use so-called member
// functions .get() and .getline() to take in more specific categories of data, like
// everything up to a new line, or everything up to a special character, etc...
//
// Example of this behavior:

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int SIZE = 256;									// size of char array, this is where we will temporarily store each call to .getline()/.get()
	ifstream in1;
	char readline[SIZE];
	char letter;
	in1.open("testInput.txt");
	in1.getline( readline, SIZE );

	cout << "\nFirst line: " << readline << endl;

	in1.getline( readline, SIZE, ',' );

// parameters:  array location, space, delimiter. Getline specifically operates with char arrays (in cstring use case)
// This means that it is different from our previous usage of .get(), which only extracts a single character from the
// input stream. This .getline() will DISCARD the next ',' delimiter identified, so that it cannot be extracted from
// the input stream anymore.

	in1.get( letter );

// this is how we have previously used .get(), it only stores the next char to be extracted from the input stream, to a char variable

	cout << "First example line: " << readline << "\tNext letter: " << letter << endl;

	in1.ignore( 100, '\n' );

// ignores the rest of the input stream, stopping after the next \n read.

	in1.get( readline, SIZE, ',' ); 

// this is the "NEW" use case of .get(), where instead of storing a single char, it will store multiple up to the specified delimiter
// in a char[] array. The difference between .getline( char arr[], int size, char delimiter = '\n' ) and .get( char arr[], int size, char delimiter = '\n' )
// is that .getline will proceed to the delimiter and THEN REMOVE IT FROM THE INPUT STREAM PERMANENTLY, whereas .get will proceed to the delimiter and THEN
// LEAVE IT UNTOUCHED, LETTING THE DELIMITER REMAIN IN THE INPUT STREAM TO BE READ BY THE NEXT MEMBER FUNCTION CALL. You can see an example of this in this code.

	in1.get( letter );

	cout << "Second example line: " << readline << "\tNext letter: " << letter << endl;
	in1.close();
	return 0;
}
