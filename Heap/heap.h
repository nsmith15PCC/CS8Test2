#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include "hnode.h"
#include <iostream>
#include <vector>\

using std::vector;

class heap
{
public:
    heap() { theheap.reserve(65536); }

    size_t size() {return theheap.size();}

    bool empty() {return theheap.empty();}

    void push(const string &w, size_t p, size_t l)
    {
        hnode *ptr = new hnode(w, p, l);
        theheap.push_back(ptr);
        std::push_heap(theheap.begin(), theheap.end(), []( hnode *x, hnode *y){return x->word > y->word;}  );
    }

    const hnode &top() const
    {
        return *theheap.front();
    }

    void pop()
    {
        std::pop_heap(theheap.begin(), theheap.end(),  []( hnode *x, hnode *y){return x->word > y->word;} );
        delete theheap.back();
        theheap.pop_back();
    }

private:
    vector<hnode*> theheap;
    void reheapifyUp(size_t child_index);
    void reheapifyDown(size_t parent_index);


};

#endif // HEAP_H
