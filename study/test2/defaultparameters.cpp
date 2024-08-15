//
// Concept category: Functions
// Concept: Default Parameters
// In C++, there is more flexibility regarding the usage of functions,
// such as pass by reference or function overloading. Another such case
// is that of default parameters, which allows a function to utilize a
// "default" value as one of the parameters of the function, if an
// expected value is not passed. See the code below.
// NOTE: ALL DEFAULT PARAMETERS MUST BE LAST IN THE PARAMETER LIST !
// IN ADDITION, DEFAULT ARGUMENTS ARE NOT CONSIDERED PART OF THE FUNCTION TYPE.
// THEREFORE, IT IS NOT USED IN SELECTING OVERLOADED FUNCTIONS. TWO FUNCTIONS
// THAT DIFFER ONLY IN THEIR DEFAULT ARGUMENTS ARE CONSIDERED MULTIPLE DEFINITIONS
// RATHER THAN OVERLOADED FUNCTIONS. DEFAULT ARGUMENTS CAN NOT BE SUPPLIED FOR
// ANY OVERLOADED OPERATORS.
//
#include <iostream>
#include <cctype>
using namespace std;

char defaultparameters ( char ch = 'd' );

int main()
{
	char ch;
	bool valid = false;
	do {
		cout << "\nWould you like to pass a character into the function? [Y] [N] : ", cin >> ch;
		if (tolower(ch) == 'y')
		{
			cout << "\nInput the character to be passed: ", cin >> ch;
			cout << "\nYour new character passed into the function is: " << defaultparameters(ch) << endl;
			valid = true;
		}
		if (tolower(ch) == 'n' )
		{
			cout << "You have chosen to use the default character: " << defaultparameters() << endl;
			valid = true;
		}
			
		else if ( !valid )
			cout << "\nThat is not a valid choice, try again.";
	} while( !valid );
}

char defaultparameters ( char ch )
{
	return ch;
}
