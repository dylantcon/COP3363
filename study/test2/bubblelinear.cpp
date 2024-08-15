//
// filename: bubblelinear.cpp
// concept: sorting and searching arrays
//
// this file utilizes a sorting method called bubblesort, that will sort a user entered array
// of integers into ascending order. then, it will allow the user to search for an element
// within the array, and if found, will inform the user of the index it is located at. the
// sorting algorithm is referred to as bubble sort, where each element of the array is swapped
// with the element to the right of it, if that element is lower than the one we are reading
// currently. after enough iterations of this algorithm, the array will be fully sorted in
// ascending order of elements. finally, we will allow the user to search the array for a
// specific integer within the array. This search will be performed with the linear searching
// algorithm.

#include <iostream>
using namespace std;

void fillArray ( int arr[], const int size );
void printArray ( const int arr[], const int size );
void bubbleSort ( int arr[], int size );
int linearSearch ( const int arr[], const int size, int target );


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

	bubbleSort(array, SIZE);
	
	printArray(array, SIZE);

	cout << "\nENTER THE INTEGER YOU WANT TO SEARCH FOR: ", cin >> target;

	location = linearSearch(array, SIZE, target);	

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


void bubbleSort(int arr[], int size)
{
	int temp = 0;
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = 0; j < (size - 1); j++ )
		{
			if ( arr[j + 1] < arr[j] )
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

	
int linearSearch(const int arr[], const int size, int target)
{
	int whatindex = -1;
	for ( int i = 0; i < size; i++ )
	{
		if ( arr[i] == target )
		{
			whatindex = i;
			return whatindex;
		}
	}
	return whatindex;
}
	
