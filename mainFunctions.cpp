#include "Header.h"
#include <iostream>
#include <fstream>
#include <stdexcept> // For exception handling

using namespace std;

void readFileIntoArray(int arr[][COLS], const char* filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open file: " << filename << endl;
        exit(1);
    }

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

bool findIntegerInArray(int arr[][COLS], int target, int& row, int& col) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == target) {
                row = i;
                col = j;
                return true;
            }
        }
    }

    // Return false if the integer is not found
    return false;
}

int modifyIntegerInArray(int arr[][COLS], int row, int col, int newValue, int& oldValue) {
    try {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            throw out_of_range("Index out of range.");
        }
        oldValue = arr[row][col];
        arr[row][col] = newValue;
        return newValue;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
        oldValue = -1;
        return -1;
    }
}

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

void removeIntegerFromArray(int arr[][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        arr[row][col] = 0;
    }
}

void printArray(const int arr[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}