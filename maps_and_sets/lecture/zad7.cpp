#include <set>
#include <iostream>

int main()
{
    int firstSetSize;
    int secondSetSize;

    std::cin >> firstSetSize >> secondSetSize;

    std::set<int> firstSet;
    std::set<int> commonElements;

    while(firstSetSize--)
    {
        int num;
        std::cin >> num;

        firstSet.insert(num);
    }

    while(secondSetSize--)
    {
        int num;
        std::cin >> num;

        if(firstSet.find(num) != firstSet.end())
        {
            commonElements.insert(num);
        }
    }

    for(int num : commonElements)
    {
        std::cout << num << " ";
    }

    return 0;
}