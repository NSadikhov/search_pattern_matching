#ifndef BRUTE_FORCE
#define BRUTE_FORCE

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
#include <unordered_set>

std::vector<int> search_pattern(const std::string &text, const std::string &pattern)
{
    int textLen = text.length();
    int patternLen = pattern.length();

    std::vector<int> matchedIndexArr;

    for (int i = 0; i <= textLen - patternLen; ++i)
    {
        int k = 0;
        while (k < patternLen && pattern[k] == text[i + k])
        {
            k++;
        }

        if (k == patternLen)
        {
            matchedIndexArr.push_back(i);
            i += k;
        }
    }

    return matchedIndexArr;
}

void next_found_index(const std::string &text, int text_length, int &index, const std::unordered_map<char, bool> &umap)
{
    auto is_found = umap.find(tolower(text[index]));
    if (index < text_length && (is_found == umap.end() || !is_found->second))
    {
        next_found_index(text, text_length, (++index), umap);
    }
}

void next_found_index(const std::string &text, int text_length, int &index, const std::unordered_set<char> &uset)
{
    auto is_found = uset.find(tolower(text[index]));
    if (index < text_length && (is_found == uset.end()))
    {
        next_found_index(text, text_length, (++index), uset);
    }
}

template <typename T>
std::vector<int> search_pattern(const std::string &text, const std::string &pattern, const T &hashmap)
{
    int textLen = text.length();
    int patternLen = pattern.length();

    std::vector<int> matchedIndexArr;

    for (int i = 0; i <= textLen - patternLen; ++i)
    {
        next_found_index(text, textLen, i, hashmap);

        int k = 0;
        while (k < patternLen && pattern[k] == text[i + k])
        {
            k++;
        }

        if (k == patternLen)
        {
            matchedIndexArr.push_back(i);
            i += k;
        }
    }

    return matchedIndexArr;
}

#endif