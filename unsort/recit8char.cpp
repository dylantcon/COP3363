#include <iostream>
using namespace std;

int main()
{
	char emptyTest[10] = {'L'};
	cout << endl << endl;
	cout << "The contents of the incomplete array is: ";
	for (int i = 0; i < 10; i++)
	{
		cout << emptyTest[i];
	}
	cout << "\n\nWow. Very weird, computers are cool." << endl;
}
