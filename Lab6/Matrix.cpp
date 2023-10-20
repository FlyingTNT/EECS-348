#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;
const int NUM_WIDTH = 3;

void makeMatrix(int***, int);
void readMatricies(string, int***, int***, int*);
void printMatrix(int**, int);
int** add(int**, int**, int);
int** multiply(int**, int**, int);
int** subtract(int**, int**, int);

int main()
{
    int** matrix1;
    int** matrix2;
    int size;

    //cout << "1";

    readMatricies("matrix_input.txt", &matrix1, &matrix2, &size);

    //cout << "2";

    //cout << matrix1[0][0];

    cout << "C. Cooper" << endl << "Lab #6 Matrix Manipulation" << endl << endl;

    cout << "Matrix A: " << endl;

    printMatrix(matrix1, size);
    
    cout << endl <<  "Matrix B: " << endl;

    printMatrix(matrix2, size);

    cout << endl <<  "Matrix Sum (A+B): " << endl;

    printMatrix(add(matrix1, matrix2, size), size);

    cout << endl << "Matrix Product (A*B): " << endl;

    printMatrix(multiply(matrix1, matrix2, size), size);

    cout << endl << "Matrix Difference (A-B): " << endl;

    printMatrix(subtract(matrix1, matrix2, size), size);

    return 0;
}

void readMatricies(string fileName, int*** matrix1, int*** matrix2, int* size)
{
    ifstream inFile(fileName);

    string line;

    //cout << "a";

    getline(inFile, line);

    *size = stoi(line);

    //cout << "b";

    makeMatrix(matrix1, *size);
    makeMatrix(matrix2, *size);

    //cout << "c";

    for(int i = 0; i < *size; i++)
    {
        for(int j = 0; j < *size; j++)
        {
            inFile >> (*matrix1)[i][j];
        }
    }

    //cout << "d";

    for(int i = 0; i < *size; i++)
    {
        for(int j = 0; j < *size; j++)
        {
            inFile >> (*matrix2)[i][j];
        }
    }

    //cout << "e";
}

void printMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "[";
        for(int j = 0; j < size; j++)
        {
            cout << " " << setw(NUM_WIDTH) << matrix[i][j] << setw(1) << " ";
        }
        cout << "]" << endl;
    }
}

void makeMatrix(int*** matrix, int size)
{
    *matrix = (new int*[size]);

    for(int i = 0; i < size; i ++)
    {
        (*matrix)[i] = new int[size];
    }
}

int** add(int** matrix1, int** matrix2, int size)
{
    int** out;
    makeMatrix(&out, size);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            out[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return out;
}

int** multiply(int** matrix1, int** matrix2, int size)
{
    int** out;
    makeMatrix(&out, size);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            out[i][j] = 0;
            for(int k = 0; k < size; k++)
            {
                out[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return out;
}

int** subtract(int** matrix1, int** matrix2, int size)
{
    int** out;
    makeMatrix(&out, size);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            out[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return out;
}