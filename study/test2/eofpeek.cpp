//
// Concept category: I/O stream member functions
// Concept: .eof() and .peek(), and how they can be applied to file I/O
//
// Two member functions of the <iostream> and <fstream> libraries, .peek() and
// .eof(), have good synergistic effects when used in conjunction with one
// another. .peek() returns the ascii value of the NEXT character in the input
// stream, but does not extract it. This is useful for detecting specific types
// of data in the stream, and extracting it for use. .eof() is a member function
// of the <fstream> library, and returns a boolean value corresponding to whether
// or not the end of the filestream has been detected. If it has, an end of file
// bit will be tripped in the filestream itself which is what .eof() checks for.
//
// Example program illustrating this concept:
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int fileInt;
	char ch;
	ifstream in1;
	in1.open("peekTest.txt");

	do
	{
		ch = in1.get();
		
		if ( in1.peek() <= '9' && in1.peek() >= '0' )
		{
			in1 >> fileInt;
			cout << "\n**NUMBER IDENTIFIED** ( " << fileInt << " )";
		}
	
	}
	while ( !in1.eof() );

	cout << endl;
}


// If you are dealing with data that has not been entered yet, .peek() may not be the best choice. In this case, you 
// can use the .putback() member function in conjunction with .get(), to get a temporary reading of the data in the
// stream. .putback(ch) sends ch back into the input stream it was taken from
