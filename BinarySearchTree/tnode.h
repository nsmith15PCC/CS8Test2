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
    tnode(const string &w = string(), size_t p = 0, size_t l = 0) : word(w), size(1),
        paragraphs(1,p), lines(1,l), children {0,0} {}

    void add(size_t p, size_t l)
    {
        paragraphs.push_back(p);
        lines.push_back(l); ++size;
    }

    friend
    operator<(const tnode &x, const tnode &y)
    {
        return x.word < y.word;
    }

    friend
    operator==(const tnode &x, const tnode &y)
    {
        return x.word == y.word;
    }

    friend
    operator<(const tnode &x, const string &y)
    {
        return x.word < y;
    }

    friend
    operator==(const tnode &x, const string &y)
    {
        return x.word == y;
    }

    friend
    operator<(const string &x, const tnode &y)
    {
        return x < y.word;
    }

    friend
    operator==(const string &x, const tnode &y)
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

ostream& operator<<(ostream& outs, const tnode &n)
{
    outs<<"Frequency: "<<n.size<<endl<<n.word<<endl;
    outs<<setw(10)<<"Paragraph"<<setw(10)<<"Line"<<endl;

    for (size_t i = 0; i < n.size; ++i)
    {
        outs<<setw(10)<<n.paragraphs[i]<<setw(10)<<n.lines[i]<<endl;
    }
}

#endif // TNODE
