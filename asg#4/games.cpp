//////////////////////////////////////////////////////////////
// Name: Dylan Connolly					    //
// Section: 6						    //
// File: games.cpp					    //
// Asg:  #4						    //
// Date: 10/25/23					    //
// Purpose:						    //
//	This file contains a program that contains a few    //
//	probability-based games, using <cstdlib>'s srand()  //
//	and rand() functions to create algorithmically      //
//	generated numbers. The user can choose from a few   //
//	options on a menu, and also are able to track and   //
//	reset their win loss statistics. It uses functions  //
//	as the main structural component of the program.    // 
//							    //
//////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>					// necessary libraries; iomanip for easier menu formatting
#include <ctime>

using namespace std;

void menu();						// menu does not need to return anything.
bool guessNumber();					// games are type bool, because the only
bool highLow();						// information they need to return is win
bool collectPairs();					// or loss. if either is detected, a count
void viewStats( int& win, int& loss );			// variable is incremented. to correctly
void printRules();					// print out W/L stats outside scope of main,
							// function must utilize pass by reference
int main()
{							// beginning of main; relatively short due to function utilization
	int select, w, l;
	select = 0, w = 0, l = 0;
	srand( time(0) );				// seeding of rand() using <ctime>'s time function
	do
	{
		menu();
		cin >> select;
		while ( select < 0 || select > 6 )	// input error statement & reprompt
		{
			cout << "Enter an item on the Menu: ", cin >> select;
		}
		if ( select == 1 )			// player chooses Guess the Number
		{
			if ( !guessNumber() )		// if bool returns false, increment loss, else, increment true
				l += 1;
			else
				w += 1;
		}
		if ( select == 2 )			// player chooses High Low
		{
			if ( !highLow() )		// if bool returns ... increment appropriately (like above)
				l += 1;
			else
				w += 1;
		}
		if ( select == 3 )			// player chooses Collect Pairs
		{
			if ( !collectPairs() )		// if bool returns ... increment appropriately (like above)
				l += 1;
			else
				w += 1;
		}
		if ( select == 4 )
			viewStats( w, l );		// passes win, loss statistics to viewStats by reference
		if ( select == 5 )
		{
			l = 0;				// resets win, loss stats and informs user
			w = 0;
			cout << "Statistics Reset!" << endl;
		}
		if ( select == 6 )			// displays rules, they're important :)
			printRules();
	} while( select != 0 );				// allows user to stop playing if exit sentinel 0 is entered.
	viewStats( w, l );				// quitting then displays their stats.
	cout << "\nThanks for playing!\n" << endl;	// it is important to be nice to the user, thank them!
	return 0;

}							// end of main

void menu()						// menu function body, uses setw, setfill and a blank cstring to print out a line of length 26
{
	cout << "\nGAME MENU:" << endl;
	cout << setw(26) << setfill('-') << "" << endl;
	cout << "1: PLAY Guess the Number" << endl;
	cout << "2: PLAY High Low" << endl;
	cout << "3: PLAY Collect Pairs" << endl;
	cout << "4: VIEW Statistics" << endl;
	cout << "5: RESET Statistics" << endl;
	cout << "6: RULES" << endl;
	cout << "0: QUIT" << endl;
	cout << setw(26) << setfill('-') << "" << endl;
	cout << "> ";
}

bool guessNumber()							// Guess the Number function body		
{
	int guess;
	int secret = rand() % 100 + 1;					// rand() % 100 + 1 creates random number in range 1 - 100
	cout << "\n\nGuess the Number, 1 --> 100!" << endl;
	for ( int attempt = 1; attempt <= 6; attempt++ )		// for loop, max number of iterations is known. may be less by using return
	{
		cout << "Attempt " << attempt << "/6 : ", cin >> guess;
		if ( guess == secret )					// checks if user guessed correctly
		{
			cout << "You WIN!" << endl;
			return true;					// if so, EXIT and return true (win) !
		}
		else if ( guess > secret )				// if not, and guess is larger, HINT !
			cout << "TOO BIG." << endl;
		else if ( guess < secret )				// if not , and guess is larger, HINT!
			cout << "TOO SMALL." << endl;
	}
	cout << "Sorry, you lose. The number was " << secret << endl;	// will only happen if user exhausts all 6 attempts, returns false (lose)
	return false;
}

bool highLow()								// High Low function body
{
	int oldnum = rand() % 1000 + 1;					// creates "old" number to compare newly generated one to
	int newnum;							// initializes user's higher or lower guess, and variable used to store new number
	char higherlower;
	cout << "\n\nHigh or Low! Stay alive for 5 rounds to win! (Numbers range from 1 to 1,000)" << endl;		// user greeting & explanation...
	for ( int round = 1; round <= 5; round++ )									// once again, for loop because iterations are known
	{
		cout << "Round " << round << " of 5. The number is " << oldnum << endl;					// shows what current or "old" number is, and asks user if "new" one will be higher or lower than it
		cout << "\t... is the next number [H]igher or [L]ower?: ", cin >> higherlower;
		while ( higherlower != 'H' && higherlower != 'h' && higherlower != 'L' && higherlower != 'l' )		// input error message and reprompt for 'H', 'h', 'L', 'l'
			cout << "\tEnter H or L: ", cin >> higherlower;
		newnum = rand() % 1000 + 1;										// generation of "hidden" or "new" number
		cout << "The next number is: " << newnum << endl;
		if ( ( ( higherlower == 'H' || higherlower == 'h' ) && newnum > oldnum ) || ( ( higherlower == 'L' || higherlower == 'l' ) && newnum < oldnum ) )	// nested boolean expression, checks for all "correct" situations
		{
			cout << "Correct!" << endl;
			oldnum = newnum;				// the "new" number is now the "old" one, so that we can prepare to create another
		}
		else
		{
			cout << "Sorry, you lose." << endl;
			return false;					// if the user is wrong at any point, they "die" and function is exited and returns false (loss)
		}
	}
	cout << "You WIN!" << endl;
	return true;							// if they exit the for loop (stay alive) they win, function returns true (win)
}

bool collectPairs()								// Collect Pairs function body	
{
	cout << "\nRolling a pair of dice 100 times for pairs!" << endl;	// user header and explanation.
	int d6_1, d6_2;								// creation (initialization) of our two dice.
	bool pair1 = false, pair2 = false, pair3 = false, pair4 = false, pair5 = false, pair6 = false;				// boolean variables used to denote whether or not a pair has been rolled.
	
	for ( int i = 0; i < 100; i++ )						// once AGAIN use for loop because we know number of iterations. loop will run 100 times
	{
		d6_1 = rand() % 6 + 1;						// each 6 sided die is assigned random number 1-6 ( rand() % 6 + 1 ), every run the two are
		d6_2 = rand() % 6 + 1;						// assigned new and unique values to ensure that probability is as real as possible
		if ( d6_1 ==  1 && d6_2 == 1 && !pair1 )
		{
			pair1 = true;
			cout << "PAIR OF ONES found" << endl;
		}
		if ( d6_1 == 2 && d6_2 == 2 && !pair2 )  			// all of the boolean selection statements above and below work on the same
                {								// exact principle, adjusted for the different sides of the dice. it first
                        pair2 = true;						// checks that each of the dice have indeed rolled the same value on each
                        cout << "PAIR OF TWOS found" << endl;			// individual roll/attempt, then it checks whether or not that pair has alr.
                }								// been observed. if it has, the !pairN boolean expression will nullify all
		if ( d6_1 == 3 && d6_2 == 3 && !pair3 )  			// of the other boolean expressions, this is to prevent the program from
                {								// showing the user that they have rolled duplicate pairs. thus, it will only
                        pair3 = true;						// notify the user when they get a pair they don't already have. */
                        cout << "PAIR OF THREES found" << endl;
                }
 		if ( d6_1 == 4 && d6_2 == 4 && !pair4 )  
                {
                        pair4 = true;
                        cout << "PAIR OF FOURS found" << endl;
                }
		if ( d6_1 == 5 && d6_2 == 5 && !pair5 )  
                {
                        pair5 = true;
                        cout << "PAIR OF FIVES found" << endl;
                }
		if ( d6_1 == 6 && d6_2 == 6 && !pair6 )  
                {
                        pair6 = true;
                        cout << "PAIR OF SIXES found" << endl;
                }
		if ( pair1 && pair2 && pair3 && pair4 && pair5 && pair6 )	// every single roll of the 100, the program checks if the user has gotten a pair of each
		{
			cout << "\nYou WIN!" << endl;
			return true;						// if so, return true (win)
		}
	}
	cout << endl << "Sorry, you lose." << endl;				// if the user exhausts all 100 rolls, they exit the loop
	return false;								// if this happens, they lose, and function returns false (loss)
}

void viewStats( int& win, int& loss )						// Statistics function
{
	double wlpercentage, numerator, denominator;				// declares 3 doubles, they are used to properly calculate and display W/L% without data loss
	numerator = win;
	denominator = win + loss;
	if ( denominator != 0 )							// checks that the denominator is not zero, to prevent NaN%
		wlpercentage = ( numerator / denominator ) * 100;
	else									// the only case where it IS zero is if the user has
		wlpercentage = 0.0;						//  1) quit without playing or 2) reset stats then quit. thus, we only need an else statement.
	cout << "\nSTATISTICS:" << endl;					// this is the statistics menu printout
	cout << setw(26) << setfill('-') << "" << endl;
	cout << "Wins: " << win << "\tLosses: " << loss << endl;
	cout.setf(ios::fixed), cout.setf(ios::showpoint), cout.precision(1);	// controls the format of how our double is displayed (in spec, 1 decimal and point is always shown)
	cout << "Total Win Percent:  " << wlpercentage << "%" << endl;
}

void printRules()								// rules function from starter file written by Prof. Myers. Thanks Prof. Myers :)
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!\nGuess Wisely!\n\n";
    cout << "High/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n";
}
