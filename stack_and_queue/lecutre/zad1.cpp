#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string strLine;
    getline(std::cin, strLine);
    std::stack<char> chars;

    for(char c : strLine)
    {
        chars.push(c);
    }

    while(!chars.empty())
    {
        std::cout<< chars.top();
        chars.pop();
    }

    return 0;

}