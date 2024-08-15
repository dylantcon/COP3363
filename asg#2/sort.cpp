#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3, low, mid, hi;                        //initializing the 6 variables required for my solution
	cout << "Input integer 1 : ", cin >> num1;                 //input 1
	cout << "Input integer 2 : ", cin >> num2;                 //input 2
	cout << "Input integer 3 : ", cin >> num3;                 //input 3

	if ( num1 >= num2 || num1 >= num3 )			//contains all cases where num1 is NOT LOWEST
	{
		if ( num1 >= num2 && num3 <= num2 )		//if 1 is more than 2, and 3 is less than 2...
		{
			hi = num1;
			mid = num2;
			low = num3;
		}
		if ( num1 >= num3 && num2 <= num3 )		//if 1 is more than 3, and 2 is less than 3...
		{
			hi = num1;
			mid = num3;
			low = num2;
		}
		if ( num1 >= num2 && num1 <= num3 )		//if 1 is more than 2, and 1 is less than 3...
		{
			hi = num3;
			mid = num1;
			low = num2;
		}
		if ( num1 >= num3 && num1 <= num2 )		//if 1 is more than 3, and 1 is less than 2...
		{
			hi = num2;
			mid = num1;
			low = num3;
		}
	}

	else					//contains all cases where num1 IS LOWEST
	{
		low = num1;
		if ( num2 >= num3 )
		{
			hi = num2;
			mid = num3;
		}
		else				//we already have 5 unique cases, thus we can conclude that this is the sixth (factorial)
		{
			hi = num3;
			mid = num2;
		}
	}

	cout << "\n\nSorted : " << low << " <= " << mid << " <= " << hi << endl;
	
}
	
