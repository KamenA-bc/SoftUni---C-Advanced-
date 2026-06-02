#include <stack>
#include <iostream>

int max_number(std::stack<int> numbers)
{
    int max_num = numbers.top();
    numbers.pop();
    while(numbers.size() > 0)
    {
        if(numbers.top() > max_num)
            max_num = numbers.top();
        
        numbers.pop();
    }
    return max_num;
}

int min_number(std::stack<int> numbers)
{
    int min_num = numbers.top();
    numbers.pop();
    while(numbers.size() > 0)
    {
        if(numbers.top() < min_num)
            min_num = numbers.top();
        
        numbers.pop();
    }
    return min_num;
}

int main()
{
    int queries;
    std::cin >> queries;
    std::stack<int> numbers;

    while(queries--)
    {
        int command;
        std::cin >> command;

        switch (command)
        {
        case 1:
            {
                int number;
                std::cin >> number;

                numbers.push(number);
            }
            break;
        case 2:
            if(numbers.size() > 0)
                numbers.pop();
            break;
        case 3:
            if(numbers.size() > 0)
                std::cout << max_number(numbers) << std::endl;

            break;
        case 4:
            if(numbers.size() > 0)
                std::cout <<min_number(numbers) << std::endl;
            break;
        }
    }

    bool bFirst = true;

    while(numbers.size())
    {
        if(bFirst)
            bFirst = false;
        else
            std::cout << ", ";

        std::cout << numbers.top();
        numbers.pop();
    }
    std::cout << std::endl;

    return 0;
}