////////////////////////////////////////////////////
// Name: Dylan T. Connolly
// Section: 6
// File: prog5.cpp
// Asg:  #5
// Date: 11/6/23
// Purpose:
//	This file, prog5.cpp, contains algorithms
//	that seek to analyze the contents of a user
//	inputted text file character by character
//	using file I/O streams, and then print the
//	applicable data to a user-specified output
//	file. All of the information in the output
//	file is expressed through an organized menu
//	format, in the following order: 1-categories,
//	2-letter analysis, and 3-number analysis.
//
/////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

void resetFilePointer( ifstream& inF );									// function that resets next character captured by .get() to beginning of file
void alphaList(ifstream& inF, int alphaNum[]);								// function that captures a tally of the occurrances of all 26 letters into an array
int alphaTotal(ifstream& inF);										// function that gets a tally of the occurrances of alphabetical characters
void storeCategories(ifstream& inF, ofstream& outF, const char inputFile[], int letterNum);		// function that records first menu item into output file, "category"
void storeLetterStats(ifstream& inF, ofstream& outF, int alphaNum[], int letterNum);			// function that records second menu item into output file, "letter statistics"
void storeNumAnalysis(ifstream& inF, ofstream& outF);							// function that records third menu item into output file, "number analysis"

int main()						// beginning of main
{

	int alphaNum[26] = {0};										// initializing / declaring necessary variables in main
	int letterNum = 0;
	char isFilename[25];
	char osFilename[25];
	ifstream inF;											// file input stream
	ofstream outF;											// file output stream

	do												// verifies validity of user entered ifstream
	{
		inF.clear();
		cout << "Please enter the name of the input file.\n";
		cout << "Filename: ", cin >> isFilename;
		inF.open(isFilename);
		if (!inF)
		{
			cout << "That is not a valid file.  Try again!\n";
		}
	} while (!inF);

	do												// verifies validity of user entered ofstream
	{
		outF.clear();
		cout << "Please enter the name of the output file.\n";
		cout << "Filename: ", cin >> osFilename;
		outF.open(osFilename);
		if (!outF)
		{
			cout << "That is not a valid file.  Try again!\n";
		}
	} while (!outF);
	
	alphaList(inF, alphaNum);									// get alphabetical occurance list into array
	letterNum = alphaTotal(inF);									// get number of alphabetical characters, store in int to be passed
	outF.setf(ios::fixed);										//
	outF.setf(ios::showpoint);									// ofstream ios formatting for 2 decimal places
	outF.precision(2);										//
	storeCategories(inF, outF, isFilename, letterNum);						// analysis complete, begin writing to output file ... 1 - categories
	storeLetterStats(inF, outF, alphaNum, letterNum);						// 2 - letter statistics
	storeNumAnalysis(inF, outF);									// 3 - number analysis

	cout << "Processing complete\n";								// confirm proper io processing, inform user then end program
	inF.close();											// close ifstream
	outF.close();											// close ofstream
}

void resetFilePointer(ifstream& inF)			// "File pointer" reset function def.
{
	inF.clear();											// clear eof() flag on ifstream, or else while(!.eof()) may break
	inF.seekg(0, ios::beg);										// set next .get() to beginning of ifstream
}
	
void alphaList(ifstream& inF, int alphaNum[])		// letter tally array function def.
{
	char ch;
	for (int i = 0; i < 26; i++)									// begin at arr[0], 'a'
	{
		while (!inF.eof())
		{
			ch = inF.get();
			if (isalpha(ch) && (tolower(ch) == ( 97 + i )))					// tolower(ch) == (97 + i) sets lowercase ascii, compares to ascii 'a' + index
			{
				alphaNum[i]++;								// if so, increment lettercounter
			}
		}
		resetFilePointer(inF);									// at eof, reset for next iteration of for loop until end
	}
}


int alphaTotal(ifstream& inF) 				// total alphabetical characters function def.
{
        int alphaTally = 0;
        while (!inF.eof())
        {
                if (isalpha(inF.get()))									// check if inF.get is letter
		{
                        alphaTally++;									// if so, increment
		}
	}
        resetFilePointer(inF);										// reset file pointer at end for next funct
	return alphaTally;										// return incremented variable
}


void storeCategories(ifstream& inF, ofstream& outF, const char inputFile[], int letterNum)		// first ofstream print (categories) function def.
{
	double percent = 0;										// initialize percent to zero--defaults if NaN is possible
	int whtSpc = 0;											//
	int digits = 0;											// initializing category counters
	int other = 0;											// -----------------------------
	int charTotal = 0;										// -----------------------------
	char takenChar;											//
	while (!inF.eof())
	{
		takenChar = inF.get();
		if (isspace(takenChar))									// if .get() is whtspc, increment
		{
			whtSpc++;
		}
		if (isdigit(takenChar))									// if .get() is digit, increment
		{
			digits++;
		}
		if (ispunct(takenChar))									// if .get() is punctuation (other), increment
		{
			other++;
		}
	}
	charTotal = letterNum + whtSpc + digits + other;						// total characters is sum of all types


	outF << "Statistics for file: " << inputFile << endl << setw(70) << setfill('-') << "" << endl;
	outF << endl << setw(31) << setfill(' ') << left << "Total # of characters in file:"; outF << setw(9) << right << charTotal << endl;
	outF << endl << setw(20) << left << "Category" << setw(20) << right << "How many in file"; outF << setw(22) << "% of file" << endl;
	outF << setw(70) << setfill('-') << "" << endl;
													// above is ofstream for menu header formatting
	for (int i = 0; i < 4; i++)
	{
		outF << setw(20) << setfill(' ') << left;
		if ( i == 0 )
		{
			outF << "Letters";								// first entry
			outF << setw(20) << right << letterNum;

			percent = ( 100.0 * letterNum ) / ( charTotal );
			outF << setw(22) << percent << " %" << endl;
		}
		if ( i == 1 )
		{
			outF << "White space";								// second entry
			outF << setw(20) << right << whtSpc;

                        percent = (( 100.0 * whtSpc ) / charTotal );
                        outF << setw(22) << percent << " %" << endl;

		}
		if ( i == 2 )
		{
			outF << "Digits";								// third entry
			outF << setw(20) << right << digits;

                        percent = (( 100.0 * digits ) / charTotal );
                        outF << setw(22) << percent << " %" << endl;

		}
		if ( i == 3 )
		{
			outF << "Other characters";							// fourth entry
			outF << setw(20) << right << other;

                        percent = (( 100.0 * other ) / charTotal );   
                        outF << setw(22) << percent << " %" << endl;
		}
	}
	resetFilePointer(inF);										// reset next .get() location and clear eof flag
	outF << endl << endl;										// indentation for next ofstream entry
	outF.setf(ios::left);										// reset ios flag to left ( default )
}
				
void storeLetterStats(ifstream& inF, ofstream& outF, int alphaNum[], int letterNum)			// second ofstream print (letter statistics) function def.
{
	double percent = 0;										// initialize percent to zero--defaults if NaN is possible
	int upperNum = 0; int lowerNum = 0;
	char ch;
	while(!inF.eof())
	{
		ch = inF.get();
		if (isupper(ch))									// gets tally of total uppercase
			upperNum++;
		if (islower(ch))
			lowerNum++;									// gets tally of total lowercase
	}		
	outF << "LETTER STATISTICS\n\n";
	outF << setw(20) << left << "Category" << setw(20) << right << "How many in file", outF << setw(22) << "% of all letters" << endl;
	outF << setw(70) << setfill('-') << "" << endl;
													// above is ofstream for menu header formatting
	if ( letterNum != 0 )										// checks if NaN will happen
	{
		percent = (( upperNum * 100.0 ) / letterNum );
	}
	outF << setw(20) << setfill(' ') << left << "Uppercase"; outF << setw(20) << right << upperNum; outF << setw(22) << right << percent << " %" << endl;

	if ( letterNum != 0 )
	{
        	percent = (( lowerNum * 100.0 ) / letterNum );
	}
        outF << setw(20) << setfill(' ') << left << "Lowercase"; outF << setw(20) << right << lowerNum; outF << setw(22) << right << percent << " %" << endl;
	char displayLetter;
	for (int i = 0; i < 26; i++)									// all 26 letters are printed using the array and for loop
	{
		displayLetter = ( 'a' + i );								// letter displayed is 'a' + index, index starts at zero
		if ( letterNum != 0 )									// checks if NaN will happen
		{
			percent = (( alphaNum[i] * 100.0 ) / letterNum ); 
		}
		outF << setw(20) << left << displayLetter << setw(20) << right << alphaNum[i], outF << setw(22) << percent << " %" << endl;
	}
													// above prints display letter and percentage in menu format to file
	resetFilePointer(inF);										// clear eof() flag and reset .get() location to beginning
	outF << left << endl;										// fixes changes to ios flags and indents for next menu item
}	

void storeNumAnalysis(ifstream& inF, ofstream& outF)	// third and final ofstream print (number analysis) function def.
{
	int currentNum = 0; int numSum = 0, numTally = 0;						// initializing necessary placeholder/counter int variables
	double numMean = 0;										// percent initialized to zero--defaults if NaN is possible
	char ch, chPrev;										// 2 char variables, one to store current .get(), the other stores previous
	chPrev = '\0';											
	while (!inF.eof())
	{
		ch = inF.get();
		if ( ch >= '0' && ch <= '9' )								// if .get is digit
		{
			currentNum = currentNum * 10 + ( ch - '0' );					// creates running int total of consecutive digits
		}
		else if ( !isdigit(ch) && isdigit(chPrev) )						// if .get() is not digit, and last .get() is, confirmed end of number, sum
		{
			numTally++;
			numSum += currentNum;
			currentNum = 0;
		}
		chPrev = ch;										// assigning .get() as last .get() when loop iterates
	}
	if ( numTally != 0 )										// check if NaN is possible
		numMean = ( numSum * 1.0 / numTally );							// if not, compute mean and multiply by 1.0 first to prevent int / int

	outF << "\nNUMBER ANALYSIS\n" << endl;								// print menu to ofstream
	outF << setw(35) << left << "Number of integers in the file:"; outF << numTally << endl;
	outF << setw(35) << left <<  "Their sum:"; outF << numSum << endl;
	outF << setw(35) << left << "Their average:"; outF << numMean << endl;
}
