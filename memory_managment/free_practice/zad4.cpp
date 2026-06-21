#include <iostream>
#include <string>
#include <memory>

class Person
{
private:
    std::string strName;
    int nAge;
public:
    Person(std::string strName, int age) : strName(strName), nAge(age){};
    ~Person() = default;

    std::string getName()
    {
        return strName;
    }
};



std::unique_ptr<Person> getPerson ()
{
    Person *person = new Person("John", 20);

    std::unique_ptr<Person> p(person);

    return p;
}

int main()
{
    std::unique_ptr<Person> personPtr = getPerson();

    std::cout << personPtr->getName() << std::endl;

    return 0;
}