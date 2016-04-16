#ifndef TORCHARD
#define TORCHARD

#include <iomanip>
#include <vector>
#include <string>
#include "bst.h"
#include "tnode.h"

class torchard
{
public:
torchard();

void insert(const string &w, size_t p, size_t l);

tnode<string> getMax();

const vector<size_t>& wordsperLetter () const;

size_t totalWords();

size_t paragraphs, syllables, sentences;

private:
vector<bst<string> > theorchard;
vector<size_t> sizeofeach;
size_t totalSize;

};

#endif // TORCHARD

