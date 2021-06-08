#include<iostream>
using namespace std;

int main()
{
    int m = 0;
    int n = 0;
    cin>>m>>n;
    long long int * dp = new long long int [n + 1];
    fill(dp,dp + n + 1,1);
    for(int i = 2; i <=m ; i++)
    {
        for(int j = 2; j <= n ; j ++ )
        {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    cout<<dp[n];
}