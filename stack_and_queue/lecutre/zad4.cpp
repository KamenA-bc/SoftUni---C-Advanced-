#include <stack>
#include <string>
#include <iostream>

int main()
{
    std::string line;

    getline(std::cin, line);

    std::stack<int> brackets;

    int pos = 0;

    for(auto c : line)
    {
        if(c == '(')
        {
            brackets.push(pos);
        }
        else if(c == ')')
        {
            std::cout << line.substr(brackets.top(), pos - brackets.top()  + 1) << std::endl;
            brackets.pop();
        }

        pos++;
    }

    return 0;
}