#include <iostream>

const int rows = 100;
const int cols = 100;


int main()
{
    int n;
    std::cin >> n;

    int arr[rows][cols];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i][i];
    }

    std::cout << sum;

    return 0;

}