#include <vector>
#include <iostream>
#include <sstream>

#define SQUARE_SIZE 2

void readMatrix(std::vector<std::vector <char> > &matrix)
{
    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[0].size(); col++)
        {
            std::cin >> matrix[row][col];
        }
    }
}

bool isSquareEqual(std::vector<std::vector <char> > &matrix, int currentRow, int currentCol)
{
    char currElem = matrix[currentRow][currentCol];
    for(int row = currentRow; row < currentRow + SQUARE_SIZE; row++)
    {
        for(int col = currentCol; col < currentCol + SQUARE_SIZE; col++)
        {
            if(currElem != matrix[row][col])
                return false;
        }
    }

    return true;
}

int main()
{
    int rows;
    int cols;
    std::cin >> rows >> cols;

    std::vector<std::vector <char> > matrix(rows,std::vector<char>(cols, '\0'));

    readMatrix(matrix);

    int numOfEqualSquares = 0;
    for(int row = 0; row <= matrix.size() - SQUARE_SIZE; row++)
    {
        for(int col = 0; col <= matrix[0].size() - SQUARE_SIZE; col++)
        {
            if(isSquareEqual(matrix, row, col))
                numOfEqualSquares++;
        }
    }

    std::cout << numOfEqualSquares;

    return 0;
}