#include <map>
#include <iostream>
#include <set>


int main()
{
    size_t numOfLinesToRead;
    std::cin >> numOfLinesToRead;
    std::map<std::string, std::map<std::string, std::set<std::string>>> mapOfContinents;

    for(size_t i = 0; i< numOfLinesToRead; i++ )
    {
        std::string continent;
        std::string country;
        std::string city;

        std::cin >> continent >> country >> city;

        mapOfContinents[continent][country].insert(city);
    }

    // Asia: 
    //  China -> Beijing, Shanghai 
    //  Japan -> Tokyo 

    for(const auto &curContinent : mapOfContinents)
    {
        std::cout << curContinent.first << ":" << std::endl;

        std::map<std::string, std::set<std::string>> mapOfCountries = curContinent.second;

        for(const auto &curCountry : mapOfCountries)
        {
            std::cout << "  " << curCountry.first << " -> ";
            std::set<std::string> citiesArr = curCountry.second;

            bool isFirst = true;
            for(const auto &curCity : citiesArr)
            {
                if(!isFirst)
                {
                    std::cout << ", ";
                }
                else
                {
                    isFirst = false;
                }
                std::cout << curCity;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}