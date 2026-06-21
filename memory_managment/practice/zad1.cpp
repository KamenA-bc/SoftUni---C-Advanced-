#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

bool isLexicographicallySmaller(const std::string &a, const std::string &b)
{
    return a < b;
}

std::string isLexicographicallySmallerV2(std::vector<std::string> v)
{
    sort(v.begin(), v.end());

    return v[0];
}

bool isSmaller(const std::string &a, const std::string &b)
{
    return a.length() < b.length();
}

bool isBigger(const std::string &a, const std::string &b)
{
    return a.length() > b.length();
}


int main()
{
    std::string line;
    getline(std::cin , line);
    std::istringstream istr(line);

    std::vector<std::string> words;

    while(istr >> line)
    {
        words.push_back(line);
    }

    int choice;
    std::cin >> choice;

    bool (*func)(const std::string &a, const std::string &b);
    std::string (*funcv2)(std::vector<std::string> v);

    switch (choice)
    {
    case 1:
        funcv2 = isLexicographicallySmallerV2;
        std::cout << funcv2(words);
        return 0;
        break;
    case 2:
        func = isSmaller;
        break;
    case 3:
        func = isBigger;
        break;
    }

    std::string result = words[0];

    for(int i = 0; i < words.size(); i++)
    {
        if(func(words[i], result))
        {
            result = words[i];
        }
    }

    std::cout << result;

    return 0;
}