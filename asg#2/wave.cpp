#include <iostream>
using namespace std;

int main()
{
	char material;								//char type for switch statement
	double displacement, coefficient, result; 				//double type for all calculated values to prevent incompatibility
	int exit;								//sentinel value for invalid entries
	cout << "\nWelcome to Sound Wave Calculator\n\nSelect the medium the soundwave will travel through." << endl;	//user prompt
	cout << "\tA\tAir\n\tW\tWater\n\tS\tSteel\n\n> ", cin >> material;	//user prompt and user input 		
	exit = 0;	
	switch( material )							//switch to check for lowercase entries via cascading
	{
		case 'a':
		case 'A':
			coefficient = 1100;
			break;
		case 'w':
		case 'W':
			coefficient = 4900;
			break;
		case 's':
		case 'S':
			coefficient = 16400;
			break;
		default:							//default case adds to exit sentinel, preventing entry of while loop
			cout << "Illegal entry. Aborting program.\n";
			exit++;
	}
	while( exit == 0 )
	{
		cout << "How far will the sound wave travel (in feet)? ", cin >> displacement;
		if( displacement > 0 )
		{
			cout.setf(ios::fixed);				//fixed point precision, adds to exit sentinel after final calculation,	
			cout.setf(ios::showpoint);			//for exiting while loop. Calculation is from values assigned from
			cout.precision(4);				//appropriate switch case

			cout << "The sound wave will travel " << ( displacement / coefficient ) << " seconds\n";
			exit++;
		}
		else
		{
			cout << "Distance cannot be negative. Aborting program.\n";
			exit++;
		}
	}					//important: I realize that the while loop is not necessary and functions exactly like
	cout << "Goodbye\n" << endl;		//an if selection statement, however I implemented the loop to allow me to add a failure
}						//statement in another version of this program, if I want to. This is mainly for my own
						//practice. Hopefully this is okay with the instructors. I just wanted to clarify :)

