#include "torchard.h"

vector<size_t> torchard::wordsperLetter ()
{
    vector<size_t> counts;
    for (int i = theorchard.size() - 1; i >= 0; --i)
    {
        counts.push_back(theorchard.at(i).size());
    }
    return counts;
}

//tnode torchard::getMax()
//{
//    if (maxofEach.empty())
//    {
//        for (vector<bst>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
//        {
//            maxofEach.push_back((*it).getMax());
//        }
//    }

//    tnode themax = *std::max_element(maxofEach.begin(), maxofEach.end(), [](const tnode &x, const tnode &y) {return x.size < y.size;});

//    maxofEach.at(themax.word[0] - 'A') = theorchard.at(themax.word[0]- 'A').getMax();
//    return themax;
//}

void torchard::balance()
{
    for (vector<bst>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
        (*it).balance();
}

vector<tnode> torchard::mostFrequentWords(std::ostream &outs)
{
    vector<tnode> theMaxes;
    while (!theorchard.empty())
    {
        tnode topWord = theorchard.back().getMinWord(theorchard.back().root());
        theMaxes.push_back(topWord );
        if (theorchard.back().empty())
            theorchard.pop_back();
        outs << topWord;
        if (theMaxes.size() > 10)
            theMaxes.erase(std::min_element(theMaxes.begin(), theMaxes.end(), [](const tnode &x, const tnode &y){return x.size < y.size;}));
    }
    std::sort(theMaxes.begin(), theMaxes.end(), [](const tnode &x, const tnode &y){return y.size < x.size;});

    return theMaxes;
}

size_t torchard::size()
{
    size_t thesize(0);
    for (vector<bst>::iterator it = theorchard.begin(); it != theorchard.end(); ++it)
        thesize += (*it).size();
    return thesize;
}

ostream &operator<<(ostream &outs, torchard &t)
{
    size_t theSize = t.size();

    vector<size_t> perletter = t.wordsperLetter();

    vector<tnode> maxeach = t.mostFrequentWords(outs);

    outs<<endl<<endl<<"SUMMARY"<<endl;

    outs<<"Word count: "<<theSize<<", Paragraphs: "<<t.paragraphs<<", Reading Level: "<<endl
       <<"Words beginning with each letter:"<<endl;

    for (size_t i = 0; i < perletter.size(); ++i)
        outs<<char('A' + i)<<" "<<perletter.at(i)<<endl;

    outs<<endl<<"Most Frequent Words:"<<endl<<setw(16)<<std::left<<"Word"<<setw(7)<<"Frequency"<<endl;
    for (size_t i = 0; i < maxeach.size(); ++i)
        outs<<setw(16)<<maxeach.at(i).word<<setw(7)<<maxeach.at(i).size<<endl;
    return outs;
}
