#include "tnode.h"

ostream& operator<<(ostream& outs, const tnode &n)
{
    outs<<"Frequency: "<<n.size<<endl<<n.word<<endl;
    outs<<setw(10)<<"Paragraph"<<setw(10)<<"Line"<<endl;

    for (size_t i = 0; i < n.size; ++i)
    {
        outs<<setw(10)<<n.paragraphs[i]<<setw(10)<<n.lines[i]<<endl;
    }
}
