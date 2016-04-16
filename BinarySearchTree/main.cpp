#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include "bst.h"

using namespace std;

int main ()
{
    clock_t a, b;
    a = clock();
    bst<int> thetree;
    srand(time(NULL));
    cout<<"Vector!"<<endl;


    for (int i = 0; i < 100000; ++i)
    {
        thetree.insert(rand()%20000);
    }

    if (!thetree.balanced())
    {cout<<"Balancing!\n";
        thetree.balance();
    }

    b = clock();
    cout<<"Success! Runtime = "<< (double)(b-a)/CLOCKS_PER_SEC <<endl;

    return 0;
}
