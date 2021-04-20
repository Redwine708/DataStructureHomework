#include"LList.h"
#include<string>
#include<cctype>
#include<iostream>
using namespace std;
LList<char> list(1000) ;
bool judgeRev();
int main()
{
    string s;
    cin>>s;
    for(int i = 0 ;  i < s.size() ; i++)
    {
        list.insert(s[i]);
    }
    if(judgeRev())cout<<"yes";
    else cout<<"no";
}
bool judgeRev()
{
    int i = 0; int j = list.length() -1 ;
    while( i < j)
    {
        list.moveToPos(i);
        char A = list.getValue();
        list.moveToPos(j);
        char B = list.getValue();
        if(A != B)return false;
        i++; j--;
    }
    return true;
}