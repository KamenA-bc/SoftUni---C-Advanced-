#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <string.h>

char* fillCompanies(const int &id, const std::string &name, std::vector<char*> &v)
{
    size_t buf_size = sizeof(int) + name.length() + 1;
    char *buffer = new char[buf_size];

    int *idPtr = reinterpret_cast<int*>(buffer);
    char *namePtr = buffer + sizeof(int);

    *idPtr = id;
    strcpy(namePtr, name.c_str());

    v.push_back(buffer);
    return buffer;
}


bool isComapnyValid(char* cmpPtr)
{
    int* idPtr = reinterpret_cast<int*>(cmpPtr);

    return (*idPtr) >= 0;
}

void removeInvalidCompanies(std::vector<char*> &v)
{
    size_t idx = 0;
    while(idx < v.size())
    {
        char* companyPtr = v[idx];
        if(!isComapnyValid(companyPtr))
        {
            v.erase(v.begin() + idx);
            delete [] companyPtr;
        }
        else
        {
            idx++;
        }
    }
}

void printComapnies(const std::vector<char*> &v)
{
    char *companyPtr = nullptr;
    int *idPtr = nullptr;
    for(auto company : v)
    {
        idPtr = reinterpret_cast<int*>(company);
        companyPtr = company + sizeof(int);

        std::cout << *idPtr << " " << companyPtr << std::endl;
    }
}

void freeComapies(std::vector<char*> &v)
{
    for(auto comapny : v)
    {
        delete [] comapny;
    }

    v.clear();
}

int main()
{
    std::string line;

    std::vector<char *> companies;

    while(true)
    {
        getline(std::cin, line);
        std::istringstream istr(line);

        if(line == "end")
        {
            break;
        }

        int id;
        istr >> id;

        std::string name;
        istr >> name;

        fillCompanies(id, name, companies);
    }

    removeInvalidCompanies(companies);

    printComapnies(companies);

    freeComapies(companies);

    return 0;
}