#include <iostream>

int main() {
    // Initial size of the array
    int initialSize = 5;
    int* dynamicArray = new int[initialSize];

    // Fill the initial array with some values
    for (int i = 0; i < initialSize; ++i) {
        dynamicArray[i] = i * 10;
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    // Increase the size of the array
    int newSize = 10;
    int* newArray = new int[newSize];

    // Copy elements from the old array to the new array
    for (int i = 0; i < initialSize; ++i) {
        newArray[i] = dynamicArray[i];
    }

    // Deallocate memory for the old array
    delete[] dynamicArray;

    // Update the pointer to the new array
    dynamicArray = newArray;

    for (int i = initialSize; i < newSize; ++i) {
        dynamicArray[i] = i * 10; // Assigning some new values for demonstration
        std::cout << dynamicArray[i] << " ";
    }
    // display the new array
    std::cout << "\n\n";    
    for (int i = 0; i < newSize; ++i)
	std::cout << dynamicArray[i] << " ";

    std::cout << std::endl;

    // Deallocate memory for the new array when done using it
    delete[] dynamicArray;

    return 0;
}

