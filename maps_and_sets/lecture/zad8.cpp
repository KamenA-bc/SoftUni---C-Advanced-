#include <unordered_map>
#include <iostream>

int main()
{
    int numOfLines;
    std::cin >> numOfLines;
    std::unordered_map<int, int> mapOfOccurences;
    
    int num;
    while(numOfLines--)
    {
        std::cin >> num;
        mapOfOccurences[num]++;
    }

    for(const auto &num : mapOfOccurences)
    {
        if(num.second % 2 == 0)
        {
            std::cout << num.first ;
        }
    }

    return 0;
}