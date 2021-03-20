#ifndef ALPHABET
#define ALPHABET

#include <iostream>
#include <string>

struct alphabet
{
    char key;
    bool value;
};

void construct_alp(alphabet *arr, int size)
{
    char first_letter = 'a';
    int counter = 0;
    while (first_letter <= 'z' && counter < size)
    {
        arr[counter].key = first_letter;
        arr[counter].value = false;
        first_letter++;
        counter++;
    }
}

void print_alp(alphabet *arr, int size)
{
    std::cout << std::boolalpha;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i].key << " -> " << arr[i].value << std::endl;
    }
}

void arrange_alp(alphabet *arr, int size, std::string pattern)
{
    for (auto c : pattern)
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i].key == c)
                arr[i].value = true;
        }
    }
}

#endif