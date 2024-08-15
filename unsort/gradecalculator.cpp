#include <iostream>
using namespace std;
int main()
{

	double grade, sum, foo, bar;
	foo = 0;
	cout << "\nWelcome to Grade Calculator! Input class grade percentage below, and type '-1' to end.\n";

	do
	{
		bar = ( 1 + foo );
		cout << "Student grade #" << bar << " : ", cin >> grade;
		if ( grade > 0 && grade <= 100 )
		{
			foo++;
			sum += grade;
		}
		else if ( grade != -1 )
		{
			cout << "\n\t||| !! ERROR !! |||\n\tPlease type a valid input.\n\n";
		}
	}
	while ( grade != -1 );
	cout << "\nThank you for using Grade Calculator.\nTotal Grades: " << foo << "\nAverage Grade: " << sum/foo << "%\n\n";
}
