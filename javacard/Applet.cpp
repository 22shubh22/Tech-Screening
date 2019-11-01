#include "Applet.h"

#include<iostream>
#include<climits>

using namespace std;

int Applet::case2()
{
    if(if_stored)
    {
        if_stored = false;
        return store;
    }
    else
    {
        cout << "Data not found\n";
        return INT_MAX;
    }
}

void Applet::case3(int s)
{
    store = s;
    if_stored = true;
}