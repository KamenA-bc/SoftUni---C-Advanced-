#include <queue>
#include <sstream>
#include <iostream>

int max_number(std::queue<int> orders)
{
    int max_num = orders.front();
    orders.pop();
    while(orders.size() > 0)
    {
        if(orders.front() > max_num)
            max_num = orders.front();
        
        orders.pop();
    }
    return max_num;
}

int main()
{
    int dailyQuantity;
    std::cin >> dailyQuantity;
    std::cin.ignore();

    std::string line;
    getline(std::cin, line);
    std::istringstream istr(line);

    std::queue<int> orders;

    int order;
    while(istr >> order)
        orders.push(order);

    std::cout << max_number(orders) << std::endl;


    while(orders.size())
    {
        if(orders.front() < dailyQuantity)
        {
            dailyQuantity -= orders.front();
            orders.pop();
        }
        else
            break;
    }

    if(orders.size() == 0)
        std::cout << "Orders complete";
    else
    {
        std::cout << "Orders left: ";
        while(orders.size())
        {
            std::cout << orders.front() << " ";
            orders.pop();
        }
    }
    
    return 0;
}