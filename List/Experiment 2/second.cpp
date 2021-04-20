#include<stack>
#include<iostream>
#include<string>
using namespace std;
stack<char>st;
int main()
{
    string s;
    cin>>s;
    int flag = 0;
    for(int i = 0  ; i<s.size();i++)
    {
        if( st.empty()&& (s[i] == ')' || s[i]==']'|| s[i] == '}' ||s[i] == '>') )
        {
            cout<<"no";
            flag = 1;
            break;
        }
        if(s[i] == '(' || s[i]=='['|| s[i] == '{' ||s[i] == '<')
        {
            st.push(s[i]);
        }
        else
        {
            if(s[i] - st.top() == 2 ||s[i] - st.top() == 1){
                st.pop();
                continue;
            }
            else 
            {
                flag = 1;
                cout<<"no";
                break;
            }
        }
    }
    if(!flag){
    if(!st.empty())
    {
        cout<<"no";
    }
    else cout<<"yes";
    }
}