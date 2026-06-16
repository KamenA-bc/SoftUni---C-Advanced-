#include <iostream>
#include <vector>
#include <set>
#include <string>

int main()
{
    int numOfLines;
    std::cin >> numOfLines;
    std::cin.ignore();

    std::set<std::string> names;
    std::vector<std::string> nameOrder;

    while(numOfLines--)
    {
        std::string name;
        getline(std::cin, name);

        if(names.find(name) == names.end())
        {
            names.insert(name);
            nameOrder.push_back(name);
        }
    }

    for(std::string name : nameOrder)
    {
        std::cout<< name << std::endl;
    }

    return 0;
}