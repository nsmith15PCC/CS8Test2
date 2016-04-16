#ifndef TEST2BSTNODE
#define TEST2BSTNODE

#include "node.h"
#include <vector>

using std::vector;

template <typename data_type>
class tnode : public node
{
public:
    tnode(const data_type &w, size_t p, size_t l): node(w)
    {
        paragraphs.push_back(p);
        lines.push_back(l);
    }

    void add (size_t p, size_t l);

    size_t count();

    template <typename D>
    friend
    std::ostream& operator<<(ostream& outs, const tnode<data_type> &n);

    vector<size_t> paragraphs, lines;
};

template <typename data_type>
tnode<data_type>::tnode(const data_type &word, size_t p, size_t l)
{
    paragraphs.push_back(p);
    lines.push_back(l);
}

template <typename data_type>
void tnode<data_type>::add (size_t p, size_t l)
{
paragraphs.push_back(p);
lines.push_back(l);
}

template <typename data_type>
size_t tnode<data_type>::count()
{
    return lines.size();
}

template <typename D>
std::ostream& operator<<(std::ostream& outs, const tnode<data_type> &n)
{
    outs<<n.data()<<", Frequency: "<<n.count()<<endl<<setw(10)<<"Paragraph"<<setw(10)<<"Line"<<endl;
    for(size_t i = 0; i < n.lines.size(); ++i)
    {
        outs<<setw(10)<<n.paragraphs[i]<<setw(10)<<n.lines[i]<<endl;
    }
}

template <typename data_type>
vector<size_t>& tnode<data_type>::paragraphs()
{
    return paragraphs;
}

template <typename data_type>
const vector<size_t>& tnode<data_type>::paragraphs() const
{
    return paragraphs;
}

template <typename data_type>
vector<size_t>& tnode<data_type>::lines();

template <typename data_type>
const vector<size_t>& tnode<data_type>::lines() const;

#endif // TEST2BSTNODE
