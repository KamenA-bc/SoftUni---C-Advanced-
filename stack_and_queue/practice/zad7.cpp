#include <stack>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    getline(std::cin, line);
    std::stack<char> openingBrackets;
    bool flag = true;

    for(char c : line)
    {
        if(line.length() % 2 != 0)
        {
            flag = false;
            break;
        }
        if(flag == false)
        {
            break;
        }
        if(c == '(' || c == '{' || c == '[')
        {
            openingBrackets.push(c);
        }
        else
        {
            switch (c)
            {
                case ')':
                    if(openingBrackets.top() != '(')
                    {
                        flag = false;   
                    }
                    else
                    {
                        openingBrackets.pop();
                    }
                    break;
                case '}':
                    if(openingBrackets.top() != '{')
                    {
                        flag = false;   
                    }
                    else
                    {
                        openingBrackets.pop();
                    }
                    break;
                case ']':
                    if(openingBrackets.top() != '[')
                    {
                        flag = false;   
                    }
                    else
                    {
                        openingBrackets.pop();
                    }
                    break;
                
                default:
                    break;
            }
        }
    }

    if(flag)
    {
        std::cout << "YES" << std::endl;
    }
    else
        std::cout << "NO" << std::endl;


    return 0;

}