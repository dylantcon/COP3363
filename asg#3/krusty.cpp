/////////////////////////////////////////////////////////////
// Name: Dylan Connolly                                    //
// Section: 6                                              //
// File: krusty.cpp                                        //
// Asg:  #3                                                //
// Date: 10/7/23                                           //
// Purpose:                                                //
//      This file contains a program that simulates the	   //
//	ordering process at a familiar establishment, by       //
//	greeting the user, and displaying a menu with the      //
//	items numbered to enable selection. Users will	       //
//	specify the item and quantity, and may continue	       //
//	ordering until they want to stop. After the order      //
//	has ended, the total is displayed. This program        //
//	utilizes functions as a core component.          		   //
//                                        							   //
/////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
double OrderTotal( int kp, int bf, int ks, int kkp );				//function prototype for order total calculation
void menu();									                              //function prototype for menu depiction

int main()	
{						                            //beginning of main

cout.setf(ios::fixed);								  //specifying fixed point notation, so that
cout.setf(ios::showpoint);							//the total can be displayed in $D.cc form
cout.precision(2);
cout << "\nWelcome to the Krusty Krab!" << endl;				//greets user
int ord, quantity, burger, fries, shake, pizza;
ord = 0, quantity = 0, burger = 0, fries = 0, shake = 0, pizza = 0;		//initializes all necessary parameters to 0

do
{										              //beginning of do/while
	menu();													//menu fn call
	cout << "\nWhat would you like? (Enter 0 to finish order!): ", cin >> ord;				//user order input
	if ( ord > 0 && ord <= 4 )										                                    //order must be in range...
	{
		cout << "How many: ", cin >> quantity;								//initial prompt, no "try again."
		while ( quantity < 0 )										            //if quantity < 0, continue to
		{												                              //prompt with failure statement
			cout << "You can't order a negative amount of food!\nTry Again: ", cin >> quantity;	//and reinput until valid
		}
		if ( ord == 1 )
		{
			burger += quantity;					//if valid item is selected, quantity is added to total patties.
		}								              //this will allow for additional duplicate orders, all items will
		if ( ord == 2 )							  //accomodate for this
		{
			fries += quantity;
		}
		if ( ord == 3 )
		{
			shake += quantity;
		}
		if ( ord == 4 )
		{
			pizza += quantity;
		} 
	}
	else if ( ord > 4 || ord < 0 )						//ensures that the erroneous inputs are not sentinel value, to
	{									                        //prevent the "that isnt on menu..." dialogue being displayed
		cout << "That isnt on the menu! Try again." << endl;		//incorrectly
	}
}
while ( ord != 0 );								//continue while sentinel is not inputted

if ( burger > 0 || fries > 0 || shake > 0 || pizza > 0 )			//checks whether or not to display "not hungry..." message
{
	cout << "\nYour order:\n";
	if ( burger > 0 )							//these successive if statements will allow the program to
	{									            //only display items that were actually ordered.
		cout << burger << " krabby patties." << endl;
	}
	if ( fries > 0 )
	{
		cout << fries << " barnacle fries." << endl;
	}
	if ( shake > 0 )
	{
		cout << shake << " kelp shakes." << endl;
	}
	if ( pizza > 0 )
	{
		cout << pizza << " krusty krab pizzas." << endl;
	}
	cout << "\nYour total is $" << OrderTotal( burger, fries, shake, pizza ) << "\nEnjoy the food!\n\n" << endl;	//calls OrderTotal using
}															                                                                                  //the quantity of each item
else
{
	cout << "Guess you aren't hungry.\n" << endl;				//only cout's this in the event that 0 is inputted immediately.
}										                                  //this only happens when all of item quantities are zero


}						                                          //end of main



double OrderTotal( int kp, int bf, int ks, int kkp )	//OrderTotal definition
{
	double total;
	return total = ( ( 3.50 * kp ) + ( 1.50 * bf ) + ( 1.00 * ks ) + ( 5.00 * kkp ) );	//total is sum of item quantities times prices
}

void menu()									//menu definition, just 2 couts :)
{
	cout << "\n----------- Menu -----------\n1. Krabby Patty ...... $3.50" << endl;
	cout << "2. Barnicle Fries .... $1.50\n3. Kelp Shake ........ $1.00\n4. Krusty Krab Pizza . $5.00\n";
}
