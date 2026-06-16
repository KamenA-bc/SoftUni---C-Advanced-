#include <queue>
#include <iostream>

bool can_complete_circle(std::queue<std::pair<int, int>> petrolPumpInfo)
{
    int fuel = 0;
    while(petrolPumpInfo.size() > 0)
    {
        auto rec = petrolPumpInfo.front();
        fuel += rec.first;
        
        if(fuel >= rec.second)
        {
            fuel -= rec.second;
            petrolPumpInfo.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int numOfLines;
    std::cin >> numOfLines;

    std::queue<std::pair<int, int>> petrolPumpInfo;

    int petrol;
    int distance;

    for(int i = 0; i < numOfLines; i++)
    {
        std::cin >> petrol >> distance;
        petrolPumpInfo.emplace(petrol, distance);
    }

    int idx;
    for(idx = 0; idx < numOfLines; idx++)
    {
        if(can_complete_circle(petrolPumpInfo))
            break;

        auto temp = petrolPumpInfo.front();
        petrolPumpInfo.pop();
        petrolPumpInfo.push(temp);
    }

    std::cout << idx;

    return 0;
}