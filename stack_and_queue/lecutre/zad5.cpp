#include <queue>
#include <iostream>
#include <sstream>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::queue<int> nums;

    int num;

    while(istr >> num)
    {
        nums.push(num);
    }

    bool isFirst = true;

    while(nums.size() > 0)
    {
        if(nums.front() % 2 != 0)
        {
            nums.pop();
        }
        else
        {
            if(isFirst)
            {
                std::cout << nums.front();
                nums.pop();
                isFirst = false;
            }
            else
            {
                std::cout << ", " << nums.front();
                nums.pop();   
            }

        }
    }

    return  0;
}