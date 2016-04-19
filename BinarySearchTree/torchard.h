#ifndef TORCHARD
#define TORCHARD

#include "bst.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::ostream;

class torchard
{
public:
    torchard() : theorchard(26) {}

    void insert(const string &w, size_t p, size_t l)
    {
        theorchard.at('Z' - w[0]).insert(w, p, l);
        ++words;
    }

    vector<size_t> wordsperLetter();

//    tnode getMax();

    void balance();

    size_t size();

    vector<tnode> mostFrequentWords(ostream &outs);

    size_t paragraphs, lines, syllables, words, sentences;

    friend
    ostream& operator<<(ostream& outs, torchard &t);

private:
    vector<bst> theorchard;
    vector<tnode> maxofEach;
};

#endif // TORCHARD
