#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "horchard.h"

using namespace std;

int main()
{
    ifstream ifs("warandpeace.txt");
    horchard theorchard;
    string line;
    clock_t a, b;

    a = clock();
//    while (!ifs.eof())
//    {
//        getline (ifs, line);
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

    block.getText(ifs, filename, theorchard);

    theorchard.balance();

    double avgNum = theorchard.words*1./theorchard.sentences, syllables=avgNum/3;
    int level = ((0.39*avgNum)+(11.8*syllables)-15.59);

    cout<< "The number of words = "<<theorchard.size()<<endl
        << "The number of paragraphs = "<<theorchard.paragraphs<<endl
        << "The reading level = "<< level<<endl;

cout<<theorchard;


    b = clock();

    cout<<"Runtime = "<<(double)(b-a)/CLOCKS_PER_SEC<<endl;



    return 0;
}
