#ifndef TORCHARD
#define TORCHARD

#include "bst.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;

class torchard
{
public:
    torchard() : theorchard(26) {}

    void insert(const string &w, size_t p, size_t l);

    vector<size_t> wordsperLetter();

    tnode getMax();

    void balance();

    vector<tnode> mostFrequentWords();

    size_t paragraphs, lines, syllables, words, sentences;

private:
    vector<bst> theorchard;
    vector<tnode> maxofEach;

    bool compareSize(const tnode &x, const tnode &y);
};

void torchard::insert(const string &w, size_t p, size_t l)
{
    theorchard.at(w.front() - 'A').insert(w, p, l);
    ++words;
}

vector<size_t> torchard::wordsperLetter ()
{
    vector<size_t> counts;
    for (size_t i = 0; i < theorchard.size(); ++i)
    {
        counts.push_back(theorchard.at(i).size());
    }
    return counts;
}

tnode torchard::getMax()
{
    if (maxofEach.empty())
    {
        for (size_t i = 0; i < 26; ++i)
        {
            maxofEach.push_back(theorchard.at(i).getMax());
        }
    }

    tnode themax = *std::max_element(maxofEach.begin(), maxofEach.end(), compareSize);

    maxofEach.at(themax.word[0]) = theorchard.at(themax.word[0]).getMax();
}

void torchard::balance()
{
    for (vector<bst>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
        (*it).balance();
}

vector<tnode> torchard::mostFrequentWords()
{
    vector<tnode> mostFrequent;
    for (size_t i = 0; i < 10; ++i)
    {
        mostFrequent.push_back(getMax());
    }
    std::sort(mostFrequent.begin(), mostFrequent.end());
    return mostFrequent;
}

bool torchard::compareSize(const tnode &x, const tnode &y)
{
    return x.size < y.size;
}

#endif // TORCHARD
