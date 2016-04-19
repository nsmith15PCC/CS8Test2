#ifndef TNODE
#define TNODE

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ostream;
using std::endl;
using std::setw;

class tnode
{
public:
    tnode(const string &w = string(), size_t p = 0, size_t l = 0) : word(w), children {0,0}, size(1),
        paragraphs(1,p), lines(1,l) {}

    void add(size_t p, size_t l)
    {
        paragraphs.push_back(p);
        lines.push_back(l);
        ++size;
    }

    friend
    bool operator<(const tnode &x, const tnode &y)
    {
        return x.word < y.word;
    }

    friend
    bool operator==(const tnode &x, const tnode &y)
    {
        return x.word == y.word;
    }

    friend
    bool operator<(const tnode &x, const string &y)
    {
        return x.word < y;
    }

    friend
    bool operator==(const tnode &x, const string &y)
    {
        return x.word == y;
    }

    friend
    bool operator<(const string &x, const tnode &y)
    {
        return x < y.word;
    }

    friend
    bool operator==(const string &x, const tnode &y)
    {
        return x == y.word;
    }

    friend
    ostream& operator<<(ostream& outs, const tnode &n);

    friend
    bool compareSize(const tnode &x, const tnode &y)
    {
        return x.size < y.size;
    }

    // Member variables
    string word;
    size_t children[2], size;
    vector<size_t> paragraphs, lines;
};

#endif // TNODE
