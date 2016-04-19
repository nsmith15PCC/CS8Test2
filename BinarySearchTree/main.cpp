#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "parser.h"
#include "torchard.h"

using namespace std;

int main()
{
//    ifstream ifs("warandpeace.txt");
    ifstream ifs;
    torchard theorchard;
    string line, filename;
    clock_t a, b;
    parser block;
    a = clock();

//    while (!ifs.eof())
//    {
//        getline(ifs, line);
//        size_t pos;
//        string word;
//        stringstream ss;
//        while ((pos = line.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ")) < string::npos)
//            line[pos] = ' ';
//        for (string::iterator it = line.begin(); it!= line.end(); ++it)
//            *it = toupper(*it);
//        ss << line;
//        while (ss >> word)
//        {
//            theorchard.insert(word, 1, 1);
//        }
//    }

//    block.checkFile(ifs, filename);

    block.getText(ifs, filename, theorchard);

    theorchard.balance();

    cout<< "The Size = "<<theorchard.size()<<endl;

    vector<size_t> perletter = theorchard.wordsperLetter();

    vector<tnode> maxeach = theorchard.mostFrequentWords();

    for (size_t i = 0; i < perletter.size(); ++i)
        cout<<char('A' + i)<<" "<<perletter.at(i)<<endl;

    for (size_t i = 0; i < maxeach.size(); ++i)
        cout<<maxeach[i]<<endl;

    b = clock();

    cout<<"Runtime = "<<(double)(b-a)/CLOCKS_PER_SEC<<endl;


    return 0;
}
