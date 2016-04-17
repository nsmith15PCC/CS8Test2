#include "bst.h"

void bst<string>::insertHELPER (size_t &r, const string &w, size_t p, size_t l)
{
    if (r)
    {
        if (thetree[r] == w)
        {
            thetree[r].add(p, l);
        }
        else
        {
            insertHELPER( thetree[r].children[thetree[r] < w ] , w, p, l );
        }
    }
    else
    {
        r = thetree.size();
        thetree.push_back(tnode<string> (w, p, l));
    }
}


void bst<string>::deallocate (size_t &r,size_t index)
{
    if (r == thetree.size() - 1)
    {
        thetree[index] = thetree[r];
        r = index;
        thetree.pop_back();
    }
    else
    {
        deallocate(thetree[r].children[ thetree[r] < (thetree[thetree.size() - 1])], index);
    }
}


bool bst<string>::removeMAX (size_t& r, string &d, vector<size_t> &p, vector<size_t> &l)
{
    if (thetree[r].children[1])
        return removeMAX(thetree[r].children[1], d, p, l);
    else
    {
        d = thetree[r].word;
        p = thetree[r].paragraphs;
        l = thetree[r].lines;
        size_t dlt = r;
        r = thetree[r].children[0];
        if (dlt != thetree.size() -1 )
            deallocate(root(), dlt);
        else
            thetree.pop_back();
        return true;
    }
}



bool bst<string>::removeHELPER (size_t& r, const string &w)
{
    if (r)
    {
        if (thetree[r] == w)
        {
            thesize -= thetree[r].size
                    if (! thetree[r].children[0])
            {
                size_t temp = r;
                r = thetree[r].children[1];
                if (temp != thetree.size() -1)
                    deallocate(root(),temp);
                else
                    thetree.pop_back();
                return true;
            }
            else
            {
                return removeMAX(thetree[r].children[0], thetree[r].word, thetree[r].paragraphs, thetree[r].lines);
            }
        }
        else
            return removeHELPER(thetree[r].child(thetree[r] < w), w);
    }
    else
        return false;
}

tnode bst::getMax()
{
    size_t themax(0), itssize(0);

    maxIndex(root(), themax, itssize);

    tnode n = thetree[themax];

    remove(thetree[themax].word);

    return n;
}

int bst<string>::depth (size_t r)
{
    if(r)
        return 1 + max(depth(thetree[r].child(0)), depth(thetree[r].child(1)));
    else
        return 0;
}

void bst::maxIndex(size_t r, size_t &m, size_t &s)
{
    if (r)
    {
        if ( thetree[r].size > s )
        {
            m = r;
            s = thetree[r].size;
        }
        maxIndex(thetree[r].children[0], m, s);
        maxIndex(thetree[r].children[1], m, s);
    }
}

void bst<string>::balance()
{
    int size = 0;
    size_t dummy = 0;
    tree_to_vine(dummy, size);
    vine_to_tree(dummy, size);
}


void bst<string>::tree_to_vine ( size_t &root, int &size )
{
    size_t vineTail, remainder, tempPtr;
    vineTail = root;
    remainder = thetree[vineTail].child(1);
    size = 0;
    while ( remainder )
    {
        if ( !thetree[remainder].child(0) )
        {
            vineTail = remainder;
            remainder = thetree[remainder].child(1);
            size++;
        }
        else
        {
            tempPtr = thetree[remainder].child(0);
            thetree[remainder].child(0) = thetree[tempPtr].child(1);
            thetree[tempPtr].child(1) = remainder;
            remainder = tempPtr;
            thetree[vineTail].child(1) = tempPtr;
        }
    }
}

template<typename string>
int bst<string>::FullSize (int size)
{
    int Rtn = 1;
    while ( Rtn <= size )
        Rtn = Rtn + Rtn + 1;
    return Rtn/2;
}


void bst<string>::vine_to_tree ( size_t &root, int size )
{
    int full_count = FullSize (size);
    compression(root, size - full_count);
    for ( size = full_count ; size > 1 ; size /= 2 )
        compression ( root, size / 2 );
}


void bst<string>::compression ( size_t &root, int count )
{
    size_t scanner = root;

    for ( int j = 0; j < count; j++ )
    {
        size_t child = thetree[scanner].child(RIGHT);
        thetree[scanner].child(RIGHT) = thetree[child].child(RIGHT);
        scanner = thetree[scanner].child(RIGHT);
        thetree[child].child(RIGHT) = thetree[scanner].child(LEFT);
        thetree[scanner].child(LEFT) = child;
    }
}
