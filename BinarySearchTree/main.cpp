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
    string filename, line;
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

    block.checkFile(ifs, filename);

    block.getText(ifs, filename, theorchard);

    cout<<theorchard;

    b = clock();

    cout<<"Runtime = "<<(double)(b-a)/CLOCKS_PER_SEC<<endl;

    cout<<"Would you like to write this summary to file? ";
    getline (cin, line);
    if (toupper(line[0]) == 'Y')
    {
        cout<<"Please enter your destination filename: ";
        getline(cin, line);
        ofstream ofs (line);
        theorchard = torchard();
        block.getText(ifs, filename, theorchard);
    ofs<<theorchard;
        ofs.close();
        cout<<"Successfully written to file!"<<endl;
    }

cout<<"Goodbye!"<<endl;
    return 0;
}
