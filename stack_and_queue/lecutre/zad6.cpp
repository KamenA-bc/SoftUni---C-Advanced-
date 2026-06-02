#include <queue>
#include <iostream>
#include <string>

int main()
{

    std::queue<std::string> people;

    while(true)
    {
        std::string line;
        getline(std::cin, line);

        if(line == "End")
        {
            break;
        }
        else if(line == "Paid")
        {
            while(people.size() > 0)
            {
                std::cout << people.front() << std::endl;
                people.pop();
            }
        }
        else
        {
            people.push(line);
        }
    }

    std::cout << people.size() << " people remaining." << std::endl;
    return 0;
}