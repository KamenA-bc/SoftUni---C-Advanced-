#include <vector>
#include <iostream>
#include <sstream>

const int rows = 10;
const int cols = 10;

bool matricesAreEqual(int arrOne[rows][cols], int arrTwo[rows][cols], int nSizeOne, int nSizeTwo)
{
    if(nSizeOne != nSizeTwo)
        return false;

    for(int row = 0; row<nSizeOne; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            if(arrOne[row][col] != arrTwo[row][col])
                return false;
        }
    }

    return true;
}

int main()
{
    int nSizeOne;
    std::cin >> nSizeOne;
    std::cin.ignore();
    int firstMatrix[rows][cols] = {};
    int numFirst;
    int colArr1 = 0;
    for(int row = 0; row < nSizeOne; row++)
    {
        std::string line;
        std::getline(std::cin, line); 
        std::stringstream ss(line);
        while(ss >> numFirst)
        {
            firstMatrix[row][colArr1] = numFirst;
            colArr1++;
        }
    }

    int nSizeTwo;
    std::cin >> nSizeTwo;
    std::cin.ignore();
    int secondMatrix[rows][cols] = {};
    int colArr2 = 0;
    int numSecond;
    for(int row = 0; row < nSizeTwo; row++)
    {
        std::string line;
        std::getline(std::cin, line); 
        std::stringstream ss(line);

        while( ss >> numSecond)
        {
            secondMatrix[row][colArr2] = numSecond;
            colArr2++;
        }
    }

    if(matricesAreEqual(firstMatrix, secondMatrix, nSizeOne, nSizeTwo))
        std::cout << "equal";
    else
        std::cout << "not equal";

    return 0;
}