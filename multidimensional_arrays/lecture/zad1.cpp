#include <iostream>

const int maxRows = 100;
const int maxCols = 100;

int main()
{
    int arr[maxRows][maxCols];

    int rows, cols;

    std::cin >> rows >> cols;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            std::cin >> arr[i][j];
        }
    }


    for(int i = 0; i < cols; i++)
    {
        int sum = 0;
        for(int j = 0; j < rows; j++)
        {
            sum += arr[j][i];
        }
        std::cout << sum << std::endl;
    }

    return 0;
}