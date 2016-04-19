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
        thetree.emplace_back(w, p, l);
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


bool bst::removeMAX (size_t& r, string &d, vector<size_t> &p, vector<size_t> &l, size_t &s)
{
    if (thetree[r].children[1])
        return removeMAX(thetree[r].children[1], d, p, l, s);
    else
    {
        d = thetree[r].word;
        p = thetree[r].paragraphs;
        l = thetree[r].lines;
        s = thetree[r].size;
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
                return removeMAX(thetree[r].children[0], thetree[r].word, thetree[r].paragraphs, thetree[r].lines, thetree[r].size);
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
    if (empty())
        return tnode();

    tnode themax= *std::max_element( thetree.begin(), thetree.end(), [](const tnode &x, const tnode &y) {return x.size < y.size;} );
    remove( themax.word );
    return themax;
}

int bst::depth (size_t r)
{
    if(r)
        return 1 + max(depth(thetree[r].children[0]), depth(thetree[r].children[1]));
    else
        return 0;
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

tnode bst::getMinWord(size_t &r)
{
    if (thetree[r].children[0])
    {
        return getMinWord(thetree[r].children[0]);
    }
    else
    {
        tnode returnval = thetree.at(r);
        size_t dlt = r;
        r = thetree[r].children[1];
        if (dlt == (thetree.size() - 1))
            thetree.pop_back();
        else
            deallocate(root(), dlt);
        if (!balanced())
            balance();
        return returnval;
    }
}
