#include <iostream>
#include <vector>
#include <string>


void readMatrixWithSnake(std::vector<std::vector <char> > &matrix, std::string &snake)
{
    int idx = 0;

    for(int row = 0; row < matrix.size(); row++)
    {
        if(row % 2 == 0)
        {
            for(int col = 0; col < matrix[0].size(); col++)
            {
                matrix[row][col] = snake[idx];
                idx++;
                if(idx >= snake.size())
                {
                    idx = 0;
                }
            }
        }
        else
        {
            for(int col = matrix[0].size() - 1; col >= 0; col--)
            {
                matrix[row][col] = snake[idx];
                idx++;
                if(idx >= snake.size())
                {
                    idx = 0;
                }
            }
        }
    }
}

int main()
{
    int rows, cols;
    std::cin >> rows >> cols;

    std::string snake;
    std::cin >> snake;

    std::vector< std::vector <char> > matrix(rows, std::vector<char>(cols, '\0'));

    readMatrixWithSnake(matrix, snake);


    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[0].size(); col++)
        {
            std::cout << matrix[row][col];
        }
        std::cout << std::endl;
    }

    return 0;
}