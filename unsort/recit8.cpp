#include <iostream>
using namespace std;

int main() {

const int empCount = 5;
int empHour[empCount] = {0};

for (int i = 0; i < empCount; i++)
{
	cout << "Please enter the hours worked by employee #" << ( i + 1 ) << ": ";
	cin >> empHour[i];
}

cout << endl << endl;

for (int i = 0; i < empCount; i++)
{
        cout << "Hours worked by employee #" << ( i + 1 ) << ": " << empHour[i] << endl;
}

}
