#ifndef _ASSERT_
#define _ASSERT_
#include<iostream>
#include<string>
using namespace std;
void Assert(bool t , string a)
{
    if(t)return;
    else 
    {
        cout<<a;    
        exit(-1);
    }
}
#endif