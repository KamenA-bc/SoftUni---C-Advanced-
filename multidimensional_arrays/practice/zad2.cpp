#include <vector>
#include <iostream>
#include <sstream>

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

void findSpecialNumber(std::vector<std::vector <int> > &matrix, int numToSearch)
{
    bool isFound = false;

    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col<matrix[0].size(); col++)
        {
            if(matrix[row][col] == numToSearch)
            {
                std::cout << row << " " << col << std::endl;
                isFound = true;
            }
        }
    }

    if(!isFound)
        std::cout << "not found" << std::endl;
}



int main()
{
    int rows;
    int cols;
    std::cin >> rows >> cols;

    std::vector<std::vector <int> > matrix(rows,std::vector<int>(cols,0));

    readMatrix(matrix);

    int numToSearch;
    std::cin >> numToSearch;

    findSpecialNumber(matrix, numToSearch);

    return 0;

}