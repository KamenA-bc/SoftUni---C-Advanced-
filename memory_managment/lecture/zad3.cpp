#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define BUF_SIZE 1024

bool

int main()
{
    char buf[BUF_SIZE] = {};
    int *nextInt = (int*)buf;
    char *nextName = (char*)nextInt + 1;

    std::vector < std::pair <int *, const char*> > companies;

    while(true)
    {
            std::string name;
            std::cin >> name;

            if(name == "end")
                break;

            int id;
            std::cin >> id;

            *nextInt = id;
            strcpy(nextName, name.c_str());
            
            companies.emplace_back(nextInt, nextName);

            nextInt = (int*)((char*)nextInt + sizeof(int) + name.size() + 1);
            nextName = (char*)(nextInt + 1);
    }

    sort(companies.begin(), companies.end());

    for(const auto &company : companies)
    {
        std::cout << company.second << " " << *company.first << std::endl;
    }

    return 0;
}