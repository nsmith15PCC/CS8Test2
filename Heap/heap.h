#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include "hnode.h"
#include <iostream>
#include <deque>\

using std::deque;

class heap
{
public:
    heap() {}

    size_t size() {return theheap.size();}

    bool empty() {return theheap.empty();}

    void push(const string &w, size_t p, size_t l)
    {
        theheap.emplace_back(w, p, l);
        std::push_heap(theheap.begin(), theheap.end());
    }

    const hnode &top() const
    {
        return theheap.front();
    }

    void pop()
    {
        std::pop_heap(theheap.begin(), theheap.end());
        theheap.pop_back();
    }

private:
    deque<hnode> theheap;

};

#endif // HEAP_H
