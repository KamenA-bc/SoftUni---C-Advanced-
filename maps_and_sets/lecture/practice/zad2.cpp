#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::map<std::string, int> mapOfWords;
    std::vector<std::string> appearance;

    std::string word;
    while(istr >> word)
    {
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){return std::tolower(c);});
        if(mapOfWords.find(word) == mapOfWords.end())
        {
            mapOfWords[word]++;
            appearance.push_back(word);
        }
        else
            mapOfWords[word]++;

    }

    bool isFirst = true;
    for(const auto &word : appearance)
    { 
        if(mapOfWords[word] % 2 != 0)
        {
            if(isFirst)
            {
                std::cout << word;
                isFirst = false;
            }
            else
                std::cout << ", " << word;
        }
    }

    return 0;
}