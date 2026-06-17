#include <vector>
#include <iostream>
#include <sstream>

#define SQUARE_SIZE 3

void readMatrix(std::vector<std::vector <int> > &matrix)
{
    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[0].size(); col++)
        {
            std::cin >> matrix[row][col];
        }
    }
}

int findSumOfSquare(std::vector<std::vector <int> > &matrix, int currentRow, int currentCol)
{
    int sum = 0;
    for(int row = currentRow; row < currentRow + SQUARE_SIZE; row++)
    {
        for(int col = currentCol; col < currentCol + SQUARE_SIZE; col++)
        {
            sum += matrix[row][col];
        }
    }

    return sum;
}

int main()
{
    int rows;
    int cols;
    std::cin >> rows >> cols;

    std::vector<std::vector <int> > matrix(rows,std::vector<int>(cols, 0));

    readMatrix(matrix);

    int biggestSum = 0;
    int startRow = 0;
    int startCol = 0;
    for(int row = 0; row <= matrix.size() - SQUARE_SIZE; row++)
    {
        for(int col = 0; col <= matrix[0].size() - SQUARE_SIZE; col++)
        {
            if(findSumOfSquare(matrix,row, col) > biggestSum)
            {
                biggestSum = findSumOfSquare(matrix,row, col);
                startRow = row;
                startCol = col;
            }
        }
    }

    std::cout << "Sum = " << biggestSum << std::endl;

    for(int i = startRow; i < startRow + SQUARE_SIZE; i++)
    {
        for(int j = startCol; j< startCol + SQUARE_SIZE; j++)
        {
            std::cout << matrix[i][j] << " "; 
        }
        std::cout << std::endl;
    }

    return 0;
}