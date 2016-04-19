#include "horchard.h"

vector<size_t> horchard::wordsperLetter ()
{
    vector<size_t> counts;
    for (size_t i = 0; i < theorchard.size(); ++i)
    {
        counts.push_back(theorchard.at(25 - i).size());
    }
    return counts;
}

vector<tnode> horchard::maxofEach(ostream &outs)
{
    vector<tnode> theMaxes;
    while (!theorchard.empty())
    {
        tnode topWord (top().word, top().paragraph, top().line);
        pop();

        while (!theorchard.empty() && top().word == topWord.word)
        {
            topWord.add(top().paragraph, top().line);
            pop();
        }

        theMaxes.push_back(topWord);
        if (theMaxes.size() > 10)
        {
            theMaxes.erase(std::min_element(theMaxes.begin(), theMaxes.end(), [](const tnode &x, const tnode &y) {return x.size < y.size;}));
        }

        outs<<topWord<<endl;
    }

    std::sort(theMaxes.begin(), theMaxes.end(), [](const tnode &x, const tnode &y){return y.size < x.size;});
    return theMaxes;
}

ostream& operator<<(ostream& outs, horchard &h)
{
    size_t theSize = h.size();

    vector<size_t> perletter = h.wordsperLetter();

    vector<tnode> maxeach = h.maxofEach(outs);

    outs<<endl<<endl<<"SUMMARY"<<endl;

    outs<<"Word count: "<<theSize<<", Paragraphs: "<<h.paragraphs<<", Reading Level: "<<endl
       <<"Words beginning with each letter:"<<endl;

    for (size_t i = 0; i < perletter.size(); ++i)
        outs<<char('A' + i)<<" "<<perletter.at(i)<<endl;

    outs<<endl<<"Most Frequent Words:"<<endl<<setw(16)<<std::left<<"Word"<<setw(7)<<"Frequency"<<endl;
    for (size_t i = 0; i < maxeach.size(); ++i)
        outs<<setw(16)<<maxeach.at(i).word<<setw(7)<<maxeach.at(i).size<<endl;
    return outs;
}
