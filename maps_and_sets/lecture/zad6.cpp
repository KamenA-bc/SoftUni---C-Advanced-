#include <set>
#include <iostream>

int main()
{
    int numOfLines;
    std::cin >> numOfLines;
    std::cin.ignore();

    std::set<std::string> usernames;

    while(numOfLines--)
    {
        std::string username;
        std::cin >> username;

        usernames.insert(username);
    }

    for(std::string username : usernames)
    {
        std::cout << username << std::endl;
    }

    return 0;
}