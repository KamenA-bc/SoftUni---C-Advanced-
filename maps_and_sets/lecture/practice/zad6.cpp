#include <iostream>
#include <set>
#include <sstream>
#include <cmath>

int main()
{
    std::string line;
    getline(std::cin , line);

    std::istringstream istr(line);

    std::multiset<int, std::greater<int>> squareNumbers;

    int num;
    bool isSqareRoot;
    while(istr >> num)
    {
        int roundedSquareRoot = round(sqrt(num));

        isSqareRoot = (roundedSquareRoot * roundedSquareRoot == num) ? true : false;

        if(isSqareRoot)
        {
            squareNumbers.insert(num);
        }
    }

    for(const auto &num : squareNumbers)
    {
        std::cout << num << " ";
    }

    return 0;
}