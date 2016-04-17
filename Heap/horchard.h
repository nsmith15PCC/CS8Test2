#ifndef HORCHARD
#define HORCHARD

#include "heap.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;

class horchard
{
public:
    horchard() : theorchard(26) {}

    void insert(const string &w, size_t p, size_t l);

    bool empty();

    const hnode& top() const;

    void pop();

    vector<size_t> wordsperLetter();

    size_t paragraphs, lines, syllables, words;

private:
    vector<heap> theorchard;
};

void horchard::insert(const string &w, size_t p, size_t l)
{
theorchard.at(w.front() - 'A').push(w, p, l);
++words;
}

bool horchard::empty()
{
return theorchard.empty();
}

const hnode& horchard::top() const
{
return theorchard.back().top();
}

void horchard::pop()
{
    theorchard.back().pop();
    if (theorchard.back().empty())
        theorchard.pop_back();
}

vector<size_t> horchard::wordsperLetter ()
{
    vector<size_t> counts;
    for (size_t i = 0; i < theorchard.size(); ++i)
    {
        counts.push_back(theorchard.at(i).size());
    }
}


#endif // HORCHARD

