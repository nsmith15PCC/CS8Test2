#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "torchard.h"

using namespace std;

int main()
{
    ifstream ifs("warandpeace.txt");
    torchard theorchard;
    string line;
    clock_t a, b;

    a = clock();
    while (!ifs.eof())
    {
        getline (ifs, line);
        size_t pos;
        string word;
        stringstream ss;
        while ((pos = line.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ")) < string::npos)
            line[pos] = ' ';
        for (string::iterator it = line.begin(); it!= line.end(); ++it)
            *it = toupper(*it);
        ss << line;
        while (ss >> word)
        {
            theorchard.insert(word, 1, 1);
        }
    }

    cout<< "The Size = "<<theorchard.size()<<endl;
    b = clock();

    cout<<"Time = "<<(double)(b-a)/CLOCKS_PER_SEC<<endl;


    return 0;
}
