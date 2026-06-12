#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    size_t numberOfLinesToRead;
    std::cin >> numberOfLinesToRead;
    std::vector<std::string> names;

    while(numberOfLinesToRead--)
    {
        std::string name;
        std:: cin >> name;

        if(find(names.begin(), names.end(), name) == names.end())
        {
            names.push_back(name);
        }
    }

    for(auto name : names)
    {
        std::cout << name << std::endl;
    }
    
    return 0;
}