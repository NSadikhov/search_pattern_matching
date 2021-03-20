#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "brute_force.h"
#include "hash_map.h"
#include "alphabet.h"

int main()
{
    std::string text_1 = "I have a book and I also would like to have a pencil.";
    std::string pattern_1 = "have";

    std::vector<int> search_result_1 = search_pattern(text_1, pattern_1);
    if (!search_result_1.empty())
    {
        for (auto i : search_result_1)
        {
            std::cout << "\nIndex [" << i << "]";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "\nNo match\n";
    }

    std::cout << " ------------------------------------------------------- \n";

    const int size = 26;
    alphabet alphabet_1[size];
    construct_alp(alphabet_1, size);
    arrange_alp(alphabet_1, size, pattern_1);
    print_alp(alphabet_1, size);

    std::cout << " ------------------------------------------------------- \n";

    std::unordered_map<char, bool> alphabet_2;
    construct_map(alphabet_2);
    arrange_map(alphabet_2, pattern_1);
    print_map(alphabet_2);

    std::vector<int> search_result_2 = search_pattern(text_1, pattern_1, alphabet_2);
    if (!search_result_2.empty())
    {
        for (auto i : search_result_2)
        {
            std::cout << "\nIndex [" << i << "]";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "\nNo match\n";
    }

    std::cout << " ------------------------------------------------------- \n";

    std::string text_2 = "Two things are infinite: the universe and human stupidity; and I'm not sure about the universe.";
    std::string pattern_2 = "universe";

    std::unordered_set<char> letters_only;
    construct_set(letters_only, pattern_2);
    print_set(letters_only);

    std::vector<int> search_result_3 = search_pattern(text_2, pattern_2, letters_only);
    if (!search_result_3.empty())
    {
        for (auto i : search_result_3)
        {
            std::cout << "\nIndex [" << i << "]";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "\nNo match\n";
    }

    return 0;
}