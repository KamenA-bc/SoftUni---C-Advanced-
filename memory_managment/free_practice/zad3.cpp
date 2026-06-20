#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define BUFF_SIZE 1024


bool sortCompanies(const char *itemA, const char * itemB)
{
    int *priceAPtr = (int*)(itemA + strlen(itemA) + 1);
    int *quantityAPtr = (int*)((char*)priceAPtr + sizeof(int));
    int totalA = ((*priceAPtr) * (*quantityAPtr));

    int *priceBPtr = (int*)(itemB + strlen(itemB) + 1);
    int *quantityBPtr = (int*)((char*)priceBPtr + sizeof(int));
    int totalB = ((*priceBPtr) * (*quantityBPtr));

    return totalA > totalB;
}

int main()
{
    char buffer[BUFF_SIZE] = {};

    char *nextItemName = buffer;
    int *nextPrice = nullptr;
    int *nextQuantity = nullptr;

    std::vector <char*> data;

    while(true)
    {
        std::string itemName;
        std::cin >> itemName;
        if(itemName == "end")
            break;

        int itemPrice;
        std::cin >> itemPrice;
        int itemQuantity;
        std::cin >> itemQuantity;

        nextPrice = (int*)(nextItemName + itemName.size() + 1);
        nextQuantity = (int*)((char*)nextPrice + sizeof(int));

        strcpy(nextItemName, itemName.c_str());
        *nextPrice = itemPrice;
        *nextQuantity = itemQuantity;


        data.push_back(nextItemName);
        nextItemName = (char*)((char*)nextQuantity + sizeof(int));
    }

    std::sort(data.begin(), data.end(), sortCompanies);

    for(const auto &rec : data)
    {
        std::cout << rec << std::endl;
    }

    return 0;
}