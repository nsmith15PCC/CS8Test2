#ifndef HNODE
#define HNODE

#include <iostream>
#include <string>
#include <iomanip>

using std::ostream;

class hnode
{
public:
    hnode(const string &w, size_t p, size_t l) : word(w), paragraph(p), line(l) {}

    friend
    bool operator<(const hnode &x, const hnode &y);

    friend
    bool operator==(const hnode &x, const hnode &y);

    friend
    bool operator<(const hnode &x, const string &y);

    friend
    bool operator==(const hnode &x, const string &y);

    friend
    bool operator<(const string &x, const hnode &y);

    friend
    bool operator==(const string &x, const hnode &y);

    friend
    bool operator<(const hnode &x, const hnode &y);

    friend
    ostream& operator<<(ostream& outs, const hnode &n);

    string word;
    size_t paragraph, line;
};

bool operator<(const hnode &x, const hnode &y)
{
    return (x.word < y.word);
}


bool operator==(const hnode &x, const hnode &y)
{
    return (x.word == y.word);
}


bool operator<(const hnode &x, const string &y)
{
    return (x.word < y);
}

bool operator==(const hnode &x, const string &y)
{
    return (x.word == y);
}


bool operator<(const string &x, const hnode &y)
{
    return (x < y.word);
}


bool operator==(const string &x, const hnode &y)
{
    return ( x == y.word);
}


ostream& operator<<(ostream& outs, const hnode &n)
{
    outs<<setw(10)<<n.paragraph<<setw(10)<<n.line
}

#endif // HNODE

