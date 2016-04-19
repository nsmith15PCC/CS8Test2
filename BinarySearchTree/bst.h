#ifndef BST
#define BST

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "tnode.h"

using std::cout;
using std::swap;
using std::max;
using std::vector;
using std::ostream;
using std::istream;

enum BSTERRORS {EMPTY};

class bst
{
public:
    bst() : thetree(1), thesize(0) {thetree.reserve(2048);}

    size_t &root()
    {
        return thetree[0].children[1];
    }

    const size_t& root () const
    {
        return thetree[0].children[1];
    }

    bool empty()
    {
        return thetree.empty();
    }

    size_t size()
    {
        return thesize;
    }

    void clear()
    {
        thetree.clear();
        thetree.push_back(tnode());
    }

    bool balanced()
    {
        return (abs(depth(thetree[root()].children[0]) - depth(thetree[root()].children[1])) <= 1);
    }

    void balance();

    void insert(const string &w, size_t p, size_t l)
    {
        ++thesize;
        insertHELPER(thetree[0].children[1], w, p, l);
        if (!balanced())
        balance();
    }

    bool remove(const string &w)
    {
        bool returnval = removeHELPER(thetree[0].children[1], w);
        if (!balanced())
        balance();
        return returnval;
    }


    size_t find (const string &d);

    tnode getMax();

private:
    vector<tnode> thetree;

    size_t thesize;

    void insertHELPER (size_t &r, const string &w, size_t p, size_t l);
    bool removeHELPER (size_t& r, const string &w);
    bool removeMAX (size_t& r, string &d, vector<size_t> &p, vector<size_t> &l, size_t &s);

    void deallocate (size_t &r, size_t index);

    int depth(size_t r);

    void tree_to_vine (size_t &root, int &size );
    void vine_to_tree ( size_t &root, int size );
    int FullSize ( int size );
    void compression ( size_t &root, int count );

};

#endif // BST
