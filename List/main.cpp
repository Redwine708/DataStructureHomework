#include"LList.h"
#include<string>
#include<cctype>
#include<iostream>
using namespace std;
LList<char> list(1000) ;
int calAlpha()
{
    int count = 0;
    list.moveToStart();
    while(list.currPos() != list.length() )
    {
        if(isalpha(list.getValue()))count++;
        list.next();
    }
    return count;
}
int calDigit()
{
    int count = 0;
    list.moveToStart();
    while(list.currPos() != list.length() )
    {
        if(isdigit(list.getValue()))
        {
            count++;
        }
        list.next();
        
    }
    return count;
}
void removeDigit()
{
    list.moveToStart();
    while(list.currPos() != list.length() )
    {
        if( isdigit( list.getValue() ) )
        {
            list.remove();
            continue;
        }
        list.next();
    }
}
int main()
{
    string s;
    cin>>s;
    for(int i = 0; i < s.size() ; i++)
    {
        list.insert(s[i]);
    }
    int al = calAlpha();
    int num = calDigit();
    cout<<al<<" "<<num<<" "<<s.size() - al - num<<endl;
   
    removeDigit();
    
    for(int i = list.length() - 1 ; i >= 0  ; i--)
    {
        list.moveToPos(i);
        cout<<list.getValue();
    }
}
