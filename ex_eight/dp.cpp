#include<iostream>
using namespace std;
const int maxn = 1000;
int dp[maxn][maxn];

void count(int , int);

int main()
{
    int a ,b;
    cin>>a>>b;
    count(a,b);
    cout<<dp[a][b];
}

void count(int m,int n)
{
    for(int i = 1 ; i <= m ; i ++)
    {
        dp[i][1] = 1;
    }
    for(int i = 1 ; i <= n ; i ++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2 ; i <= m ; i ++)
    {
        for(int j = 2 ; j <= n ; j ++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

}