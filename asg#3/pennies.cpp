/////////////////////////////////////////////////////////////
// Name: Dylan Connolly				 	 
// Section: 6						   
// File: pennies.cpp					   
// Asg:  #3						   
// Date: 10/6/23					   
// Purpose:						   
// 	This file contains a program that will calculate   
//      the total funds earned from a job over a user	   
//	inputted number	of days, where the pay earned on   
//	day 1 is $0.01, and the pay on each consecutive	   
//	day is twice that of the previous.		   
//							   
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
int main()
{
	int foo, days;	    							//foo allows exit from error checking loop, days is cin'ed.
	double earnings, net;							//earnings starts at 0.01, and increases by 2*(days - 1).
	foo = 0;
	earnings = 0.01, net = 0;						//must set net to zero, and earnings to starting val.
	cout.setf(ios::fixed);						
	cout.setf(ios::showpoint);
	cout.precision(2);							//fixed point notation such that cout is "N.nn".

	do									            //beginning of input error checking loop.
	{
		cout << "\nPlease enter the number of days worked: ", cin >> days;
		if ( days > 0 )								//if valid day num is given, add to foo to allow exit.
		{
			foo++;
		}
		else								//extention of error checking, reprompts user if # of
		{								    //days is illogical (negative).
			cout << "Invalid number of days. Try again";
		}
	} while ( foo == 0 );							//end of input error checking loop, only leaves with valid var.

	cout << "\nDay\t\t\tAmount Earned\n-------------------------------------------\n";	//displays cout legend for for loop.
	for ( int i = 1; i <= days; i++)					                                          // for loop, guided by counter i with respect to inputted days
	{
		cout << i << "\t\t\t$ " << earnings << endl;			//generation of individual days, and the earnings assoc.
		net += earnings;						                      //adds individual day to running net total.
		earnings = ( earnings * 2 );					            //after displaying earnings for day, doubles for next iteration.
	}
	cout << "\nTotal earnings: $ " << net << endl;		  //displays total earnings to user :)
}
