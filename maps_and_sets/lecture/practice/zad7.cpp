#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int curLine = 1;

    std::map<std::string, int> resourcesByQuantity;
    std::vector<std::string> occurances;

    std::string resource;
    int quantity;

    while(true)
    {
        if(curLine % 2 != 0)
        {
            std::cin >> resource;
            if(resource == "stop")
                break;
            occurances.push_back(resource);    
        }
        else
        {
            std::cin >> quantity;
            resourcesByQuantity[resource] += quantity;
        }
        curLine++;
    }

    // Gold -> 155 
    // Silver -> 10 
    // Copper -> 17
    for(const auto resource : occurances)
    {
        auto rec = resourcesByQuantity.find(resource);
        if(rec != resourcesByQuantity.end())
        {
        std::cout << rec->first << " -> " << rec->second << std::endl;

        resourcesByQuantity.erase(resource);
        }
    }

    return 0;

}