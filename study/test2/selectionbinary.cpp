//
// filename: selectionbinary.cpp
// concept: searching and sorting arrays
//
// this program is similar to bubblelinear.cpp, but instead utilizes
// the selection sorting algorithm, and the binary search algorithm.
// structurally, these algorithms are harder to understand and not
// as easy to implement for beginners. however, they are both more
// efficient than their counterparts and often result in faster exec.
// of the desired task.
//
// example code below:
//

#include <iostream>
using namespace std;

void fillArray ( int arr[], const int size );
void printArray ( const int arr[], const int size );
void selectionSort ( int arr[], const int size );
int binarySearch ( const int arr[], const int size, int target );
	
int main()
{

        const int SIZE = 20;
        int array[SIZE] = {0};
        int target, location;

        printArray(array, SIZE);

        cout << "Type " << SIZE << " integers to store in an array: ";
        fillArray(array, SIZE);

        printArray(array, SIZE);

        cout << "\n**SORTING ARRAY**\n";

        selectionSort(array, SIZE);

        printArray(array, SIZE);

        cout << "\nENTER THE INTEGER YOU WANT TO SEARCH FOR: ", cin >> target;

        location = binarySearch(array, SIZE, target);

        if ( location != -1 )
                cout << "\nTHE INTEGER " << target << " WAS FOUND AT INDEX " << location << endl;
        else if ( location == -1 )
                cout << "\nTHE INTEGER " << target << " WAS NOT FOUND" << endl;

}


void fillArray(int arr[], const int size)
{
        for ( int i = 0; i < size; i++ )
                cin >> arr[i];
        cout << "\nARRAY FILLED!";
}


void printArray(const int arr[], const int size)
{
        cout << "\nThe array: { ";
        for ( int i = 0; i < size - 1; i++ )
        {
                cout << arr[i] << ", ";
        }
        cout << arr[size - 1] << " }" << endl << endl;
}


void selectionSort(int arr[], const int size)
{
	for ( int i = 0; i < ( size - 1 ); i++ )
	{
		int min_ind = i;
		for ( int j = i + 1; j < size; j++ )
		{
			if ( arr[j] < arr[min_ind] )
				min_ind = j;
		}
		if ( min_ind != i )
		{
			int temp = arr[i];
			arr[i] = arr[min_ind];
			arr[min_ind] = temp;
		}
	}
}


int binarySearch( const int arr[], const int size, int target )
{
	int mid;
	int low = 0;
	int high = size - 1;
	while ( low <= high )
	{
		mid = ( low + high ) / 2;
		if ( target == arr[mid] )
			return mid;
		else if ( target > arr[mid] )
			low = mid + 1;
		else if ( target < arr[mid] )
			high = mid - 1;
	}
	return -1;
}
