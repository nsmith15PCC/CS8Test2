#include "heap.h"

void heap::reheapifyUp(size_t child_index)
{
    if (child_index == 0)
        return;
    size_t parent_index = (child_index-1)/2;
    if (theheap[parent_index] < theheap[child_index])
    {
        std::swap(theheap[parent_index], theheap[child_index]);
        reheapifyUp(parent_index);
    }
}

void heap::reheapifyDown(size_t parent_index)
{
    size_t child_index = parent_index*2+1;
    if (child_index < theheap.size())
    {
        if (child_index + 1 < theheap.size() && theheap[child_index] < theheap[child_index+1])
            child_index+=1;
        if (theheap[parent_index] < theheap[child_index])
        {
            std::swap(theheap[parent_index],theheap[child_index]);
            reheapifyDown(child_index);
        }
    }
    else
        return;
}
