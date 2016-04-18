#include "horchard.h"

vector<size_t> horchard::wordsperLetter ()
{
    vector<size_t> counts;
    for (size_t i = 0; i < theorchard.size(); ++i)
    {
        counts.push_back(theorchard.at(i).size());
    }
    return counts;
}

vector<tnode> horchard::maxofEach()
{
    vector<tnode> theMaxes;
    while (!theorchard.empty())
    {
        tnode topWord (top().word, top().paragraph, top().line);
        pop();

        while (top().word == topWord.word)
        {
            topWord.add(top().paragraph, top().line);
            pop();
        }

        theMaxes.push_back(topWord);

        if (theMaxes.size() > 10);
            theMaxes.erase(std::min_element(theMaxes.begin(), theMaxes.end(), compareSize));
    }

    std::sort(theMaxes.begin(), theMaxes.end());
    return theMaxes;
}
