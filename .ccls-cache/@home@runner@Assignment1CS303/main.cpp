#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    int array[ROWS][COLS]; //2D array for organization and readability when printing
    const char* filename = "data.txt"; // Replace with your file's name

    readFileIntoArray(array, filename);

    int target;
    cout << "Enter an integer to search for: ";
    cin >> target;

    int row, col; //These integers will be passed to the findInt function to identify position
    if (findIntegerInArray(array, target, row, col)) {
        cout << "Integer " << target << " found at index (" << row << ", " << col << ")." << endl;

      printArray(array); //Print the array to show original condition
        
        int newValue, oldValue; //Creates variables to hold the old and newly entered values
        cout << "Enter a new value: ";
        try {
            cin >> newValue; //Gets newValue from user
            int modifiedValue = modifyIntegerInArray(array, row, col, newValue, oldValue); 
            if (modifiedValue != -1) { //Ensures the result of the modifyInteger function is positive and prints the results 
                cout << "Value at index (" << row << ", " << col << ") updated from " << oldValue << " to " << modifiedValue << "." << endl;
              printArray(array); // Prints the array to show the updated value 
            } else {
                cout << "Invalid index. Value not updated." << endl; //Error message
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl; //First error message 
        }
    } else {
        cout << "Integer " << target << " not found in the array." << endl; //Message for if the ORIGINALLY entered value was not found in the array
    }

  //Lines 41-47: Gets new value from user, calls the appendInteger function and prints an update message followed by the updated array.
    int newValue;
    cout << "Enter a new integer to append to the array: ";
    try {
        cin >> newValue;
        appendIntegerToArray(array, newValue);
        cout << "New integer " << newValue << " appended to the array." << endl;
      printArray(array);
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl; //Error message
    }

    int removeRow, removeCol; //Creates variables that will hold the userInput for the coordinates 
    cout << "Enter the index (row and column) to remove an integer: ";
    try {
        cin >> removeRow >> removeCol; //Collects data
        removeIntegerFromArray(array, removeRow, removeCol);
        cout << "Integer at index (" << removeRow << ", " << removeCol << ") removed from the array." << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl; //Error message 
    }

    cout << "Current array:" << endl;
    printArray(array); //Prints the final array

    return 0;
}