#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

int main()
{
    int number_of_students;
    std::cin >> number_of_students;
    std::cin.ignore();
    std::map<std::string, std::vector<double>> students;

    for(int i = 0; i < number_of_students; i++)
    {
        std::string line;

        std::string name;
        double grade;

        std::cin >> name >> grade;


        students[name].push_back(grade);
    }

    std::cout << std::fixed << std::setprecision(2);

    for(const std::pair<std::string, std::vector<double>> &curStrudent : students)
    {
        //John -> 5.20 3.20 (avg: 4.20)

        std::cout << curStrudent.first << " -> ";
        double gradesSum = 0;
        for(const double &curGrade : curStrudent.second)
        {
            std::cout << curGrade << " ";
            gradesSum += curGrade;
        }

        std::cout << "(avg: " << gradesSum / curStrudent.second.size() << ")" << std::endl;
    }

    return 0;
}