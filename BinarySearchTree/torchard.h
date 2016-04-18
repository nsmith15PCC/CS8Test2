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

    void insert(const string &w, size_t p, size_t l)
    {
        theorchard.at(w.front() - 'A').insert(w, p, l);
        ++words;
    }

    vector<size_t> wordsperLetter();

    tnode getMax();

    void balance();

    size_t size();

    vector<tnode> mostFrequentWords();

    size_t paragraphs, lines, syllables, words;

private:
    vector<bst> theorchard;
    vector<tnode> maxofEach;
};


#endif // TORCHARD
