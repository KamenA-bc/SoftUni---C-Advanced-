#include <queue>
#include <iostream>
#include <sstream>

int main()
{
    std::string line;

    getline(std::cin, line);

    std::istringstream istr(line);

    std::queue<std::string> players;

    std::string player;
    while(istr >> player)
    {
        players.push(player);
    }

    int turns;
    std::cin >> turns;

    int remaningTurns = turns;

    while(players.size() > 1)
    {
        remaningTurns--;
        std::string player = players.front();
        if(remaningTurns > 0)
        {

            players.pop();
            players.push(player);
        }
        else
        {
            std::cout << "Removed " << player << std::endl;
            players.pop();
            remaningTurns = turns;
        }
    }
    std::cout << "Last is " << players.front() << std::endl;
    return 0;
}