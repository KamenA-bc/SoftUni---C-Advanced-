#include <iostream>
#include <vector>


std::pair<int, int> findSymbolOccurance(const std::vector< std::vector<char>> &matrix, char charToSearch)
{

    for(int row = 0; row < matrix.size(); row++)
    {
        for(int col = 0; col < matrix[row].size(); col++)
        {
            if(matrix[row][col] == charToSearch)
                return std::pair<int,int>(row, col);
        }
    }

    return std::pair<int, int>(matrix.size(), matrix[0].size());
}

int main()
{
    size_t nSize;
    std::cin >> nSize;

    std::vector< std::vector<char>> matrix(nSize, std::vector<char>(nSize, '\0'));

    for(int row = 0; row < nSize; row++)
    {
        for(int col = 0; col < nSize; col++)
        {
            std::cin >> matrix[row][col];
        }
    }

    char charToSearch;
    std::cin >> charToSearch;

    std::pair<int, int> result = findSymbolOccurance(matrix, charToSearch);

    if(result.first < matrix.size())
    {
        std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;
    }
    else
    {
        std::cout << charToSearch << " does not occur in the matrix" << std::endl;
    }

    return 0;
}