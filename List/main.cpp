#include"LList.h"
#include"List.h"
#include"Link.h"
#include<string>
#include<iostream>
using namespace std;



int main()
{
    string a;
    cin>>a;
    LList<char>list(a);
    int num = list.calDigit();
    int alpha = list.calAlpha();
    int cnt = list.getCnt();
    cout<<alpha<<" "<<num<<" "<<cnt - alpha - cnt;
    list.removeDigit();
    cout<<list;
}