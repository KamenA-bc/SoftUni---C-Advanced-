#include <set>
#include <iostream>
#include <sstream>
#include <functional>
#include <string>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::set<double, std::greater<int>> setOfThreeBigestNumbers;

    double num;
    while(istr >> num)
    {
        if(setOfThreeBigestNumbers.size() < 3)
        {
            setOfThreeBigestNumbers.insert(num);
        }
        else if(num > *setOfThreeBigestNumbers.rbegin() && setOfThreeBigestNumbers.find(num) == setOfThreeBigestNumbers.end())
        {
            setOfThreeBigestNumbers.erase(*setOfThreeBigestNumbers.rbegin());
            setOfThreeBigestNumbers.insert(num);
        }
        else
            continue;
    }

    for(const auto &num : setOfThreeBigestNumbers)
    {
        std::cout << num << " ";
    }

    return 0;
}