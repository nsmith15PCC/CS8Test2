#ifndef HORCHARD
#define HORCHARD

#include "heap.h"
#include "tnode.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;

class horchard
{
public:
    horchard() : theorchard(26) {}

    void insert(const string &w, size_t p, size_t l)
    {
        theorchard.at(w.front() - 'A').push(w, p, l);
        ++words;
    }

    bool empty()
    {
        return theorchard.empty();
    }

    const hnode& top() const
    {
        return theorchard.back().top();
    }

    void pop()
    {
        theorchard.back().pop();
        if (theorchard.back().empty())
            theorchard.pop_back();
    }

    size_t size()
    {
        size_t thesize = 0;
        for (vector<heap>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
            thesize += (*it).size();
        return thesize;
    }

    vector<size_t> wordsperLetter();

    vector<tnode> maxofEach();

    size_t paragraphs, lines, syllables, words;

private:
    vector<heap> theorchard;
};

#endif // HORCHARD
