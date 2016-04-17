#include "bst.h"

void bst::insertHELPER (size_t &r, const string &w, size_t p, size_t l)
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
        thetree.push_back(tnode(w, p, l));
    }
}


void bst::deallocate (size_t &r,size_t index)
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


bool bst::removeMAX (size_t& r, string &d, vector<size_t> &p, vector<size_t> &l)
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



bool bst::removeHELPER (size_t& r, const string &w)
{
    if (r)
    {
        if (thetree[r] == w)
        {
            thesize -= thetree[r].size;
            if(! thetree[r].children[0])
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
            return removeHELPER(thetree[r].children[thetree[r] < w], w);
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

int bst::depth (size_t r)
{
    if(r)
        return 1 + max(depth(thetree[r].children[0]), depth(thetree[r].children[1]));
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

void bst::balance()
{
    int size = 0;
    size_t dummy = 0;
    tree_to_vine(dummy, size);
    vine_to_tree(dummy, size);
}


void bst::tree_to_vine ( size_t &root, int &size )
{
    size_t vineTail, remainder, tempPtr;
    vineTail = root;
    remainder = thetree[vineTail].children[1];
    size = 0;
    while ( remainder )
    {
        if ( !thetree[remainder].children[0] )
        {
            vineTail = remainder;
            remainder = thetree[remainder].children[1];
            size++;
        }
        else
        {
            tempPtr = thetree[remainder].children[0];
            thetree[remainder].children[0] = thetree[tempPtr].children[1];
            thetree[tempPtr].children[1] = remainder;
            remainder = tempPtr;
            thetree[vineTail].children[1] = tempPtr;
        }
    }
}

int bst::FullSize (int size)
{
    int Rtn = 1;
    while ( Rtn <= size )
        Rtn = Rtn + Rtn + 1;
    return Rtn/2;
}


void bst::vine_to_tree ( size_t &root, int size )
{
    int full_count = FullSize (size);
    compression(root, size - full_count);
    for ( size = full_count ; size > 1 ; size /= 2 )
        compression ( root, size / 2 );
}


void bst::compression ( size_t &root, int count )
{
    size_t scanner = root;

    for ( int j = 0; j < count; j++ )
    {
        size_t child = thetree[scanner].children[1];
        thetree[scanner].children[1] = thetree[child].children[1];
        scanner = thetree[scanner].children[1];
        thetree[child].children[1] = thetree[scanner].children[0];
        thetree[scanner].children[0] = child;
    }
}
