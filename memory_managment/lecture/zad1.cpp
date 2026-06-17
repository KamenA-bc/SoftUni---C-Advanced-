#include <iostream>


bool cast(const char *text, int &result)
{
    result = 0;
    while(*text != '\0')
    {
        if(*text >= '0' && *text <= '9')
        {
            result *=10;
            result += (*text - '0');
        }
        else
            return false;
        text++;
    }

    return true;
}

int main()
{
    std::string firstString;
    std::string secondString;

    std::cin >> firstString >> secondString;

    int first,second;
    bool castedFirst = cast(firstString.c_str(), first);
    bool castedSecond = cast(secondString.c_str(), second);


    if(castedFirst && castedSecond)
    {
        std::cout << first + second << std::endl;
    }
    else
    {
        if(!castedFirst)
            std::cout << "[error] ";
        std::cout << firstString << std::endl;

        if(!castedSecond)
            std::cout << "[error] ";
        std::cout << secondString << std::endl;
    }

    return 0;

}