#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    std::set<std::string> wordsInSentence;

    std::string word;
    while(istr >> word)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if(word.size() < 5)
        {
            wordsInSentence.insert(word);
        }
    }

    bool isFirst = true;
    for(const auto &word : wordsInSentence)
    {
        if(isFirst)
        {
            isFirst = false;
        }
        else
        {
            std::cout << ", ";
        }
        std::cout << word;
    }

    return 0;
}