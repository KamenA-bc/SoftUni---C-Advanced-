#include <stack>
#include <sstream>
#include <iostream>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::stack<int> clothes;

    int num;
    while(istr >> num)
        clothes.push(num);

    int rackCapacity;
    std::cin >> rackCapacity;

    int numberOfRacks = 1;

    int capacity = rackCapacity;
    while(clothes.size())
    {
        if(capacity >= clothes.top())
        {
            capacity -= clothes.top();
            clothes.pop();
        }
        else
        {
            numberOfRacks++;
            capacity = rackCapacity;
        }
    }

    std::cout << numberOfRacks;

    return 0;
}