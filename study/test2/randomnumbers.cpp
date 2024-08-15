//
// Concept category: Library functions
// Concept: Random number generation, seeding, and getting numbers in a range
//
// If a programmer wants to incorporate randomly generated numbers into their program,
// they must #include <cstdlib> so that they can use the srand() and rand() functions.
// Calling srand() seeds the random number generator, one must use some number or value
// to seed the generating algorithm properly. If the algorithm is seeded using the same
// value every time, it will produce the same series of "random" numbers. Therefore, it
// is quite common to also #include <ctime>, as this allows the coder to get a value
// based off of the system's internal clock. In this case, there is no risk of the random
// numbers being identical because srand() will be seeded using a different number every
// time. 
// IMPORTANT NOTE: rand() FUNCTION GENERATES A RANDOM INTEGER WITH NO SPECIFIC RANGE, MOST
// 		   RANDOM NUMBERS WILL BE VERY BIG. TO GET A NUMBER WITHIN A CERTAIN RANGE,
//		   USE THE MODULUS OPERATOR ( % ). FOR EXAMPLE, RANDOM # 1-6 WOULD BE DONE
//		   USING THIS CODE: randNum = rand() % 6 + 1;
//
// Example code below:

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	srand(time(0));							// seeding random number generating algorithm with current time in seconds since unix epoch ( jan 1 1970, 12:00am )
	int randomTen = rand() % 10 + 1;
	int randomHundred = rand() % 100 + 1;
	int randomThousand = rand() % 1000 + 1;
	
	cout << "\nYour random number in range 1-10 is: " << randomTen << endl;
	cout << "Your random number in range 1-100 is: " << randomHundred << endl;
	cout << "Your random number in range 1-1000 is: " << randomThousand << endl;
	
}
