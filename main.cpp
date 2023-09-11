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

      printArray(array);
        
        int newValue, oldValue;
        cout << "Enter a new value: ";
        try {
            cin >> newValue;
            int modifiedValue = modifyIntegerInArray(array, row, col, newValue, oldValue);
            if (modifiedValue != -1) {
                cout << "Value at index (" << row << ", " << col << ") updated from " << oldValue << " to " << modifiedValue << "." << endl;
              printArray(array);
            } else {
                cout << "Invalid index. Value not updated." << endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } else {
        cout << "Integer " << target << " not found in the array." << endl;
    }

    int newValue;
    cout << "Enter a new integer to append to the array: ";
    try {
        cin >> newValue;
        appendIntegerToArray(array, newValue);
        cout << "New integer " << newValue << " appended to the array." << endl;
      printArray(array);
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    int removeRow, removeCol;
    cout << "Enter the index (row and column) to remove an integer: ";
    try {
        cin >> removeRow >> removeCol;
        removeIntegerFromArray(array, removeRow, removeCol);
        cout << "Integer at index (" << removeRow << ", " << removeCol << ") removed from the array." << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Current array:" << endl;
    printArray(array);

    return 0;
}