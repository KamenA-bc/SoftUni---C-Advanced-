#include <set>
#include <iostream>

int main()
{
    std::set<std::string> carPlates;
    while(true)
    {
        std::string command;
        std::cin >> command;

        if(command == "END")
        {
            break;
        }

        std::string carPlate;
        std::cin >> carPlate;

        if(command == "IN,")
        {
            carPlates.insert(carPlate);
        }
        else
        {
            carPlates.erase(carPlate);
        }
    }

    if(carPlates.size() == 0)
    {
        std::cout << "Parking Lot is Empty" << std::endl;
    }

    for(const std::string &plates : carPlates)
    {
        std::cout << plates << std::endl;
    }

    return 0;
}