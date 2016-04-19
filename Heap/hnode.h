#ifndef HNODE
#define HNODE

#include <iostream>
#include <string>
#include <iomanip>

using std::ostream;
using std::string;
using std::setw;

class hnode
{
public:
    hnode(const string &w, size_t p, size_t l) : word(w), paragraph(p), line(l) {}

    friend
    bool operator<(const hnode &x, const hnode &y)
    {
        return (x.word < y.word);
    }

    friend
    bool operator==(const hnode &x, const hnode &y)
    {
        return (x.word == y.word);
    }

    friend
    bool operator<(const hnode &x, const string &y)
    {
        return (x.word < y);
    }

    friend
    bool operator==(const hnode &x, const string &y)
    {
        return (x.word == y);
    }

    friend
    bool operator<(const string &x, const hnode &y)
    {
        return (x < y.word);
    }


    friend
    bool operator==(const string &x, const hnode &y)
    {
        return ( x == y.word);
    }


    friend
    ostream& operator<<(ostream& outs, const hnode &n)
    {
        outs<<setw(10)<<n.paragraph<<setw(10)<<n.line;
        return outs;
    }

    string word;
    size_t paragraph, line;
};

#endif // HNODE

