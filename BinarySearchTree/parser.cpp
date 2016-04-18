#include "parser.h"

parser::parser()
{

}

parser::~parser()
{

}

void parser::checkFile(ifstream &in, string filename)
{
    cout << "Enter the filename of the file you wish to open : ";
    getline(cin, filename);
    in.open(filename+".txt");
    if(in.fail())
    {
        cout << "File does not exist!\n";
        exit(0);
    }
    cout << "File open!\n";
    in.close();
}

void getText(ifstream &in, string filename, torchard& orchard)
{
    string line, word;
    int pos, paragraphs, lines;
    in.open(filename+".txt");
    stringstream ss;

    while(getline(in, line))
    {
        if(line == "")
            paragraphs++;
        else
        {
            lines++;
            while(pos = line.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!.?") < string::npos)
            {
                line.erase(pos,1);
                line.insert(pos, " ");
            }
            pos = 0;
            while(pos = line.find_first_of(".?!") < string::npos)
            {
                orchard.sentences++;
                line.erase(pos,1);
                line.insert(pos, " ");
            }
            pos = 0;

            ss << line;
            while(ss >> word)
            {
                word[0] = toupper(word[0]);

                orchard.insert(word, paragraphs, lines);
            }
        }
    }
    in.close();
}

string parser::edit(string line)
{

}

void parser::feed(torchard &orchard, string line)
{

}
