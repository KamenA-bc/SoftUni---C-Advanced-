#include <iostream>
#include <sstream>
#include <stdexcept>

int main()
{
    std::string firstString;
    std::string secondString;

    std::cin >> firstString >> secondString;


    int first , second;

    try
    {
        first = stoi(firstString);
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << "[error] " << firstString << std::endl;
    }

    
    try
    {
        second = stoi(secondString);
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << "[error] " << secondString << std::endl;
    }

    std::cout << first + second;

    return 0;

}