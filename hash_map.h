#ifndef HASH_MAP
#define HASH_MAP

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

//*** Unordered Map
void construct_map(std::unordered_map<char, bool> &umap)
{
    char letter = 'a';
    while (letter <= 'z')
    {
        umap[letter] = false;
        letter++;
    }
}

void print_map(const std::unordered_map<char, bool> &umap)
{
    std::cout << std::boolalpha;
    for (auto &[key, value] : umap)
    {
        std::cout << key << " -> " << value << std::endl;
    }
}

void arrange_map(std::unordered_map<char, bool> &umap, std::string pattern)
{
    for (auto c : pattern)
    {
        if (umap.find(c) != umap.end())
            umap[c] = true;
    }
}

//*** Unordered Set
void construct_set(std::unordered_set<char> &uset, std::string &pattern)
{
    for (char c : pattern)
        uset.insert(c);
}

void print_set(const std::unordered_set<char> &uset)
{
    for (auto key : uset)
    {
        std::cout << "[ " << key << " ] ";
    }

    std::cout << std::endl;
}

#endif