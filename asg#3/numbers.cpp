/////////////////////////////////////////////////////////////
// Name: Dylan Connolly                                    //
// Section: 6                                              //
// File: numbers.cpp                                       //
// Asg:  #3                                                //
// Date: 10/6/23                                           //
// Purpose:                                                //
//      This file contains a program that will allow the   //
//      user to enter a list of numbers until they input   //
//      0 to stop. The program will then analyze the       //
//      numbers that were inputted, listing some of the    //
//      properties (such as: total inputs, sum, average,   //
//      #'s divisible by 9, max, and min).                 //
//                                                         //
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
int main()
{

int div9, input, max, min;						//declaring integer only variables
double avg, total, sum;							  //declaring double only variables, sum and total for avg calculation
max = 0, min = 0, total = 0, div9 = 0, avg = 0, input = 1;		//initializing variables to 0, input to 1 for entry into loop
cout << endl;

while ( input != 0 )							   //sentinel is zero, minimum loop entries = 1
{
	cout << "Input integer (0 to stop): ", cin >> input;		//user input
	if ( input != 0 )						       //checking if zero was entered to prevent incorrect total and avg
	{
		total++;						            //count++
		sum += input;						        //runnning total from +=
		avg = ( sum / total );					//sum and total are type double to prevent data loss

		if ( ( input % 9 ) == 0 )				//if modulus of ( input / 9 ) == 0, allow entry
		{
			div9++;						        //count++
		}
		if ( input > max )					//if current input exceeds current max, max = input
		{
			max = input;
		}
		if ( input < min )					//if current input is lower than current min, min = input
		{
			min = input;
		}
	}
}	

cout << "\nTotal: " << total << endl; 				//user input printout lines below
cout << "Sum: " << sum << endl;
cout.setf(ios::fixed);						//fixed point declared after sum and total to prevent
cout.setf(ios::showpoint);					//erroneous printing of (sum).00 and (total).00
cout.precision(2);
cout << "Average: " << avg << endl;
cout << "Divisible by 9: " << div9 << endl;
cout << "Max: " << max << endl;
cout << "Min: " << min << endl;

}
