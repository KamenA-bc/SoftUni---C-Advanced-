#include <set>
#include <iostream>
#include <sstream>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    std::set<int> sortedNumbers;

    int num;
    while(istr >> num)
        sortedNumbers.insert(num);


    bool isFirst = true;
    for(const auto &num : sortedNumbers)
    {
        if(isFirst)
        {
            isFirst = false;
        }
        else
        {
            std::cout << " <= ";
        }
        std::cout << num;
    }

    return 0;
}