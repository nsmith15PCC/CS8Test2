#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "torchard.h"

using namespace std;

class parser
{
public:
    parser();
    ~parser();

    void checkFile(ifstream &in, string &filename);
    void getText(ifstream &in, string filename, torchard& orchard);
    string contraction(string word);

};

#endif // PARSER_H
