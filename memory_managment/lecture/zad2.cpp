    #include <map>
    #include <iostream>
    #include <string.h>

    #define BUF_SIZE 1024

    int main()
    {
        char buffer[BUF_SIZE] = {};
        char *nextString = buffer;

        std::map<int, const char*> companies;

        while(true)
        {
            std::string name;
            std::cin >> name;

            if(name == "end")
                break;

            int id;
            std::cin >> id;

            strcpy(nextString, name.c_str());

            companies[id] = nextString;

            nextString += name.length() + 1;

        }

        // int searchId;
        // std::cin >> searchId;

        // auto it = companies.find(searchId);
        // if(it != companies.end())
        // {
        //     std::cout << it->second << " " << it->first << std::endl;
        // }
        // else
        //     std::cout << "not found" << std::endl;

        for(auto it : companies)
        {
            std::cout << it.second << " "<< it.first <<std::endl;
        }

        return 0;
    }