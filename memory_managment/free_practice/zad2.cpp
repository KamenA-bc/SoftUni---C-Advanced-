#include <iostream>

void removeVowels(char *text)
{
    char *read = text;
    char *write = text;
    while(*read != '\0')
    {
        if(*read != 'a' && *read != 'e' && *read != 'i' && *read != 'o' && *read != 'u')
        {
            *write = *read;
            write++;
        }
        read ++;
    }
    *write = '\0';
}

int main()
{
    char word[100] = {};

    std::cin >> word;

    removeVowels(word);

    std::cout << word;

    return 0;
}