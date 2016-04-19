#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "horchard.h"

using namespace std;

class parser
{
public:
    parser();
    ~parser();

    void checkFile(ifstream &in, string &filename);
    void getText(ifstream &in, string filename, horchard& orchard);
    string contraction(string word);

};

#endif // PARSER_H
