#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

using namespace std;

const int ROWS = 10;
const int COLS = 10;

void readFileIntoArray(int arr[][COLS], const char* filename);
bool findIntegerInArray(int arr[][COLS], int target, int& row, int& col);
int modifyIntegerInArray(int arr[][COLS], int row, int col, int newValue, int& oldValue);
void appendIntegerToArray(int arr[][COLS], int newValue);
void removeIntegerFromArray(int arr[][COLS], int row, int col);
void printArray(const int arr[][COLS]);

#endif // ARRAY_UTILS_H