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
        theheap.emplace_back(w, p, l);
        std::push_heap(theheap.begin(), theheap.end(), [](const hnode &x, const hnode &y){return x.word > y.word;}  );
    }

    const hnode &top() const
    {
        return theheap.front();
    }

    void pop()
    {
        std::pop_heap(theheap.begin(), theheap.end(), [](const hnode &x, const hnode &y){return x.word > y.word; } );
        theheap.pop_back();
    }

private:
    vector<hnode> theheap;
    void reheapifyUp(size_t child_index);
    void reheapifyDown(size_t parent_index);


};

#endif // HEAP_H
