#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int matrixSize;
    cin >> matrixSize;

    vector< vector<int> > matrix;

    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[row].size(); col++)
        {
            cin >> matrix[row][col];
        }
    }

    int firstDiagonalSum = 0;
    int secondDiagonalSum = 0;

    for(int i = 0; i < matrixSize; i++)
    {
        firstDiagonalSum += matrix[i][i];
        secondDiagonalSum += matrix[i][(matrixSize - 1) - i];
    }


    int absoluteDifference = abs(firstDiagonalSum - secondDiagonalSum);

    cout << absoluteDifference;

    return 0;

}