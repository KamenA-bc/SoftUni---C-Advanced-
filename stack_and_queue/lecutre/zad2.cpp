#include <iostream>
#include <sstream>
#include <stack>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::stack<int> nums;

    std::istringstream istr(line);


    int num;

    while(istr >> num)
    {
        nums.push(num);
    }

    while(true)
    {    
        getline(std::cin, line);

        std::istringstream istr(line);

        std::string command;
        istr >> command;

        if(command == "end")
            break;

        if(command == "add")
        {
            int n;
            int m;

            istr >> n >> m;

            nums.push(n);
            nums.push(m);

        }
        else
        {
            int n;

            istr >> n;

            if(n>nums.size())
            {
                continue;
            }

            while(n>0)
            {
                nums.pop();
                n--;
            }
        }
    }

    int sum = 0;

    while(nums.size() > 0)
    {
        sum += nums.top();
        nums.pop();
    }

    std::cout << sum;

    return 0;
}