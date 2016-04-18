#include "torchard.h"

vector<size_t> torchard::wordsperLetter ()
{
    vector<size_t> counts;
    for (size_t i = 0; i < theorchard.size(); ++i)
    {
        counts.push_back(theorchard.at(i).size());
    }
    return counts;
}

tnode torchard::getMax()
{
    if (maxofEach.empty())
    {
        for (size_t i = 0; i < 26; ++i)
        {
            maxofEach.push_back(theorchard.at(i).getMax());
        }
    }

    tnode themax = *std::max_element(maxofEach.begin(), maxofEach.end(), [](const tnode &x, const tnode &y) {return x.size < y.size;});

    maxofEach.at(themax.word[0]) = theorchard.at(themax.word[0]).getMax();
}

void torchard::balance()
{
    for (vector<bst>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
        (*it).balance();
}

vector<tnode> torchard::mostFrequentWords()
{
    vector<tnode> mostFrequent;
    for (size_t i = 0; i < 10; ++i)
    {
        mostFrequent.push_back(getMax());
    }
    std::sort(mostFrequent.begin(), mostFrequent.end());
    return mostFrequent;
}

size_t torchard::size()
{
    size_t thesize(0);
    for (vector<bst>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
        thesize += (*it).size();
    return thesize;
}
