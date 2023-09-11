#include "Header.h"
#include <iostream>
#include <fstream>
#include <stdexcept> // For exception handling

using namespace std;

void readFileIntoArray(int arr[][COLS], const char* filename) {
    ifstream inputFile(filename);
    //open file and ensure it was opened properly
    if (!inputFile) {
        cerr << "Error: Unable to open file: " << filename << endl;
        exit(1);
    }
    //Loads the data from data.txt into the array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (!(inputFile >> arr[i][j])) {
                cerr << "Error: Could not read data from file." << endl;
                exit(1);
            }
        }
    }

    inputFile.close();
}
//Loops through the rows checking each integer in the array for the target
bool findIntegerInArray(int arr[][COLS], int target, int& row, int& col) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == target) {
                row = i; //sets row and col to the coordinates of the target to be displayed in the main file
                col = j;
                return true;
            }
        }
    }

    // Return false if the integer is not found
    return false;
}

int modifyIntegerInArray(int arr[][COLS], int row, int col, int newValue, int& oldValue) {
    try { //Checks to ensure the row and col variables are not negative and that they are within the allowed ranges for this 2D array.
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            throw out_of_range("Index out of range.");
        }
        oldValue = arr[row][col]; //swaps the old value 
        arr[row][col] = newValue; //with the new value
        return newValue;
    } catch (const out_of_range& e) {  //If an error was found on the previous if check, catch and print error message
        cerr << "Error: " << e.what() << endl;
        oldValue = -1;
        return -1;
    }
}

//Searches the array for '0' (end of the array) and replaces that 0 with the given value
void appendIntegerToArray(int arr[][COLS], int newValue) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == 0) {
                arr[i][j] = newValue;
                return;
            }
        }
    }
}

//Checks to make sure the row and col values are positive, in the correct range, then replaces the value at the given coordinates with 0
void removeIntegerFromArray(int arr[][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        arr[row][col] = 0;
    }
}

//Loops through the array and prints each value in an organized way.
void printArray(const int arr[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}