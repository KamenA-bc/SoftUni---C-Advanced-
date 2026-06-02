#include <iostream>
#include <stack>
#include <sstream>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::stack<int> nums;
    std::stack<char> operations;

    int number;


    while(istr >> number)
    {
        nums.push(number);

        char operation;

        if(istr >> operation)
        {
            operations.push(operation);
        }
        else
        {
            break;
        }
    }

    int sum = 0;

    while(nums.size() > 0)
    {
        int num = nums.top();
        nums.pop();

        char operation;
        if(operations.size() > 0)
        {
            operation = operations.top();
            operations.pop();
        }
        else
        {
            operation = 'x';
        }

        switch (operation)
        {
        case '+':
            sum += num;
            break;

        case '-':
            sum -= num;
            break;

        default:
            sum += num;
            break;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}