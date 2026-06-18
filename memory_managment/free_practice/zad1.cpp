#include <iostream>
#include <vector>

bool tryParsePositiveNumber(const std::string &input, int &outNumber)
{
    int temp = 0;
    for(const char &c : input)
    {
        if(c >= '0' && c <= '9')
        {
            temp *= 10;
            temp += (c - '0');
        }
        else
            return false;
    }

    outNumber = temp;
    return true;
}


int main()
{
    int sum = 0;
    std::vector <std::string> invalidOutputs;
    while(true)
    {
        std::string input;
        std::cin >> input;

        if(input == "end")
            break;

        int outNumber;
        if(tryParsePositiveNumber(input, outNumber))
        {
            sum += outNumber;
        }
        else
        {
            invalidOutputs.push_back(input);
        }
    }

    for(const auto & out : invalidOutputs)
    {
        std::cout << " [ignored] " << out << " ";
    }

    std::cout << "Sum: " << sum;
    return 0;
}