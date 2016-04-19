#include "tnode.h"

ostream& operator<<(ostream& outs, const tnode &n)
{
    outs<<endl<<n.word<<", Frequency: "<<n.size<<endl;
    outs<<setw(10)<<std::left<<"Paragraph"<<setw(10)<<"Line"<<endl;

    for (size_t i = 0; i < n.size; ++i)
    {
        outs<<setw(10)<<n.paragraphs[i]<<setw(10)<<n.lines[i]<<endl;
    }
    outs<<std::right;
    return outs;
}
