#include <map>
#include <iostream>
#include <sstream>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::map<double, int> mapOfNumbers;

    double num;
    while(istr >> num)
    {
        mapOfNumbers[num]++;
    }

    //2.5 -> 3 
    for(const std::pair<double, int> &num : mapOfNumbers)
    {
        std::cout << num.first << " -> " << num.second << std::endl;
    }

    return 0;
}