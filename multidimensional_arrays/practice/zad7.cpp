#include <iostream>
#include <sstream>
#include <vector>

std::vector< std::vector <int>> methodA(int N)
{
    std::vector<std::vector<int>> m(N, std::vector<int>(N, 0));

    int num = 1;
    for(int col = 0; col < N; col++)
    {
        for(int row = 0; row < N; row++)
        {
            m[row][col] = num;
            num++;
        }
    }

    return m;
}


std::vector< std::vector <int>> methodB(int N)
{
    std::vector<std::vector<int>> m(N, std::vector<int>(N, 0));

    int num = 1;
    for(int col = 0; col < N; col++)
    {
        if(col % 2 == 0)
        {
            for(int row = 0; row < N; row++)
            {
                m[row][col] = num;
                num++;
            }
        }
        else
        {
            for(int row = m.size() - 1; row >= 0; row--)
            {
                m[row][col] = num;
                num++;
            }
        }

    }

    return m;
}



int main()
{
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    std::string nStr;
    getline(istr, nStr, ',');

    std::istringstream nStream(nStr);
    int N;
    nStream >> N;

    char method;
    istr >> method;

    std::vector< std::vector <int> > matrix = (method == 'A' ? methodA(N) : methodB(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout <<matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}