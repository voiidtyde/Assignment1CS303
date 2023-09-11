using namespace std;

const int ROWS = 10; 
const int COLS = 10;

//Reads data from 'data.txt' and puts the numbers into a 2D array
void readFileIntoArray(int arr[][COLS], const char* filename); 

//Takes a target number and "returns" the row and col location of that target using reference
bool findIntegerInArray(int arr[][COLS], int target, int& row, int& col);

int modifyIntegerInArray(int arr[][COLS], int row, int col, int newValue, int& oldValue); //replaces a value at (row, col) with a new user entered value and returns both of them to the user after running

void appendIntegerToArray(int arr[][COLS], int newValue); //Adds a single value to the end of the array

void removeIntegerFromArray(int arr[][COLS], int row, int col); //Replaces inter at (row, col) with 0

void printArray(const int arr[][COLS]); //Prints the 2D array

