///////////////////////////////////////////////////////////////////
// Name: Dylan Connolly						 //
// Section: 6							 //
// File: prog7.cpp						 //
// Asg:  #7							 //
// Date: 12/6/23						 //
// Purpose:							 //
//	This file contains a program that acts as a simple	 //
//	gradebook creation utility. The user will provide	 //
//	an input data file containing: the total number of all	 //
//	students listed (on separate line at top of file), and	 //
//	for each student a dedicated line listing last name,	 //
//	first name, course enrolled, test 1, test 2, and final	 //
//	exam scores. This program reads the data found there,	 //
//	parses it into a dynamically allocated array of structs, //
//	sorts it by last name, and then stores the info inside	 //
//	an organized gradebook menu within a user specified	 //
//	output file. This is the second version of prog7.cpp,	 //
//	which I have revised to sort alphabetically as opposed	 //
//	to lexicographically.					 //
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>								// including necessary libraries
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

struct Student									// student struct definition, used in our dynamic array and sorting algo
{
	string lastName;
	string firstName;
	char course;
	int test1;
	int test2;
	int final;
	double mean;
};

string stringLower( string str );													// converts a string to all lowercase, used to
void studentParse( ifstream& in1, Student * sList, const int size );									// parses file contents, stores in array ( in order given in file )
void studentSort( Student * sList, const int size, int& English, int& History, int& Math );						// sorts array contents, first by class, then alphabetically by last name WITHIN the class
void printBook( ofstream& out1, const Student * sList, const int& English, const int& History, const int& Math );	// file output print funct

int main()									// beginning of main
{
	ifstream in1;								// file
	ofstream out1;								// I/O
	char inFileName[30];
	char outFileName[30];
	int English, History, Math;						// useful class category counter variables
	do
        {
                in1.clear();
                cout << "Please enter the name of the input file.\n";		// verifies functional input stream
                cout << "Filename: ", cin >> inFileName;			// from the filename provided by user,
                in1.open(inFileName);						// if any failures occur program will
                if (!in1)							// not proceed
                {
                        cout << "That is not a valid file.  Try again!\n";
                }
        } while (!in1);

        do
        {
                out1.clear();
                cout << "Please enter the name of the output file.\n";		// verifies functional output stream
                cout << "Filename: ", cin >> outFileName;			// from the filename provided by user,
                out1.open(outFileName);						// if any failures occur program will
                if (!out1)							// not proceed
                {
                        cout << "That is not a valid file.  Try again!\n";
                }
        } while (!out1);
	
	int size;
	in1 >> size;								// (obtain total number of students--now we can make our dynamic array)
	in1.ignore(1);								// (skip newline whitespace)
	Student * sList = new Student[size];					// (creates a dynamic array of structs, and assigns a pointer to its address)
	studentParse( in1, sList, size );					// (parse file input to array of structs)
	studentSort( sList, size, English, History, Math );			// (sort array of structs by course, then subsort each course by last name)
	printBook( out1, sList, English, History, Math );			// (print sorted array of structs to output file)
	delete [] sList;
	sList = 0;
	in1.close();
	out1.close();
	cout << "Processing Complete" << endl;
}

string stringLower( string s1 )													// stringLower function def; used to sort alphabetically 
{																// (not lexicographically) within the studentSort funct.
	int stringSize;
	char ch;
	stringSize = s1.length();
	for ( int i = 0; i < stringSize; i++ )
	{
		ch = s1[i];
		ch = tolower(ch);
		s1[i] = ch;
	}
	return s1;
}



void studentParse( ifstream& in1, Student * sList, const int size )								// studentParse function def.
{
	for ( int i = 0; i < size; i++ )					// iterate through our file n times, for each n number of students
	{
		getline( in1, sList[i].lastName, ',' );				// last name getline to string obj ( ',' delimiter )
		getline( in1, sList[i].firstName, ',' );			// first name getline to string obj ( ',' delimiter )
		in1 >> sList[i].course;						// extract course enrolled
		in1.ignore(1);
		in1 >> sList[i].test1;						// extract test 1 score
		in1.ignore(1);
		in1 >> sList[i].test2;						// extract test 2 score
		in1.ignore(1);
		in1 >> sList[i].final;						// extract final exam score
		in1.ignore(1);
		sList[i].mean = ( sList[i].test1 * 0.30 ) + ( sList[i].test2 * 0.30 ) + ( sList[i].final * 0.40 );		// calculate the nth student's mean score, using the scale given
	}
}


void studentSort( Student * sList, const int size, int& English, int& History, int& Math )					// studentSort function def.
{
	Student temp;													// temporary Student type, for bubble sort
	string strTemp1, strTemp2;
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = 0; j < size - 1; j++ )
		{
			if ( sList[j + 1].course < sList[j].course )		// bubblesort by ascii value of course enrolled, knowing that they will be arranged in E, H, M
			{
				temp = sList[j + 1];
				sList[j + 1] = sList[j];
				sList[j] = temp;
			}
		}
	}

	English = 0; History = 0; Math = 0;					// count the number of students in each class
	for ( int i = 0; i < size; i++ )
	{
		if ( sList[i].course == 'E' )
			English++;
		else if ( sList[i].course == 'H' )
			History++;
		else if ( sList[i].course == 'M' )
			Math++;
	}								// (english : i = 0; i < English; i++) (history : i = English; i < History + English) (math : i = History + English; i < size;)

	for ( int i = 0; i < English; i++ )
	{
		for ( int j = 0; j < English - 1; j++ )
		{
			strTemp2 = stringLower( sList[j + 1].lastName );
			strTemp1 = stringLower( sList[j].lastName );
			if ( strTemp2.compare( strTemp1 ) < 0 )		// subsort last names within the english class ( index i = 0 to i < English ), using bubble method
			{
				temp = sList[j + 1];
                                sList[j + 1] = sList[j];
                                sList[j] = temp;
			}
		}
	}

	for ( int i = English; i < English + History; i++ )
        {        
                for ( int j = English; j < English + History - 1; j++ )
                {
			strTemp2 = stringLower( sList[j + 1].lastName );
			strTemp1 = stringLower( sList[j].lastName );
                        if ( strTemp2.compare( strTemp1 ) < 0 )  	// subsort last names within the history class ( index i = English to i < English + History ), using bubble method
                        {
                                temp = sList[j + 1];
                                sList[j + 1] = sList[j];
                                sList[j] = temp;
                        }
                }
        }

	for ( int i = English + History; i < size; i++ )
        {
                for ( int j = English + History; j < size - 1; j++ )
                {
                        strTemp2 = stringLower( sList[j + 1].lastName );
                        strTemp1 = stringLower( sList[j].lastName );
                        if ( strTemp2.compare( strTemp1 ) < 0 )		// subsort last names within the math class ( index i = English + History to i < size ), using bubble method
                        {
                                temp = sList[j + 1];
                                sList[j + 1] = sList[j];
                                sList[j] = temp;
                        }
                }
        }

}

void printBook( ofstream& out1, const Student * sList, const int& English, const int& History, const int& Math )			// printBook function def.
{
	out1.setf(ios::fixed);														// set flags for averages ( 2 decimal places )
	out1.setf(ios::showpoint);
	out1.precision(2);
	char letter;															// placeholder variable that is used in determining letter grade
	int i = 0;
	string fullName;														// string var used to hold a student's full name, for field width formatting
	double gradeSum;														// sum of all average grades var, used to calculate class avg
	string classTitle[3] = { "ENGLISH CLASS", "HISTORY CLASS", "MATH CLASS" };							// array of strings, used for easier coding of menu printout by iteration
	int totals[3] = { English, History, Math };											// array of ints, used to account for each case's total students (corresponds with outer for loop)
	out1 << "\nStudent Grade Summary\n---------------------\n" << endl;								// header
	for ( int count = 0; count < 3; count++ )											// for loop, 3 iterations for each 3 categories
	{
		out1 << classTitle[count] << endl << endl << setw(25) << left << "Student Name" << setw(25) << right << "Test Avg" << endl;	// title of class and categories printout
		out1 << setw(65) << setfill('-') << "" << endl << setfill(' ');
		gradeSum = 0;
		for ( int foo = 0; foo < totals[count]; foo++ )										// for loop, iterates for each student in each class
		{
			fullName = sList[i].firstName + " ";										//    makes the students
			fullName = fullName + sList[i].lastName;									// full name a single string
			if ( sList[i].mean >= 90.00 )											
				letter = 'A';												// successive if statements determine
			else if ( sList[i].mean >= 80.00 && sList[i].mean <= 89.99 )							//    the student's letter grade
				letter = 'B';
			else if ( sList[i].mean >= 70.00 && sList[i].mean <= 79.99 )
				letter = 'C';
			else if ( sList[i].mean >= 60.00 && sList[i].mean <= 69.99 )
				letter = 'D';
			else if ( sList[i].mean <= 59.99 )
				letter = 'F';
			out1 << setw(25) << left << fullName << setw(25) << right << sList[i].mean << setw(5) << letter << endl;	// print data assoc. with student number n
			gradeSum += sList[i].mean;
			i++;														// incrementer variable that tracks the index at which student n's data is stored. (cannot exceed size)
		}
		if ( totals[count] != 0 )												// if statement to prevent NaN class average (if any class is empty)
			out1 << endl << setw(35) << "Class Average" << setw(15) << ( gradeSum / ( 1.0 * totals[count] ) ) << endl;
		out1 << setw(65) << setfill('-') << "" << setfill(' ') << endl << endl << endl;						// end of course summary ( footer with class average and menu formatting )
	}
}
