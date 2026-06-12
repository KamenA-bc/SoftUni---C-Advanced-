#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

int main()
{
    std::string line;
    getline(std::cin, line);

    std::unordered_map<double, int> values_occurences;
    std::istringstream istr(line);
    std::vector<double> num_order;

    double num;
    while(istr >> num)
    {
        if(values_occurences.find(num) != values_occurences.end())
        {
            values_occurences[num]++;
        }
        else
        {
            values_occurences.insert({num, 1});
            num_order.push_back(num);
        }
    }

    for(double i : num_order)
    {
        std::unordered_map<double, int>::iterator record = values_occurences.find(i);

        std::cout << record->first << " - " << record->second << " times" << std::endl;
    }

    return 0;
}