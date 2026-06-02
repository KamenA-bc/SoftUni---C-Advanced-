    #include <stack>
    #include <iostream>
    #include <sstream>
    #include <climits>

    void stacky (int n, int s, int x)
    {
        std::string line;
        getline(std::cin, line);

        std::stack<int> numbers;

        std::istringstream istr(line);

        int num;

        while(istr >> num)
        {
            numbers.push(num);
        }

        for(int i = 0; i < s; i++)
        {
            numbers.pop();
        }

        if(numbers.size() == 0)
        {
            std::cout << 0;
            return;
        }

        int smallest = INT_MAX;

        while(numbers.size() > 0)
        {
            if(numbers.top() == x)
            {
                std::cout << "true" << std::endl;   
                return;
            }
            else
            {
                if(numbers.top() < smallest)
                {
                    smallest = numbers.top();
                    numbers.pop();
                }
                else
                {
                    numbers.pop();
                }
            }
        }

        std::cout << smallest << std::endl;
    }

    int main()
    {
        std::string line;
        getline(std::cin, line);

        std::istringstream istr(line);

        int n;
        int s;
        int x;

        istr >> n >> s >> x;
        stacky(n, s, x);
        
        return 0;   
    }