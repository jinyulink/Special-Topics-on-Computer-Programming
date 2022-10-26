//程式設計研討專題 week 6
//UVA 10721 Bar Codes
//DP 組合 ，建表 直接從表格拿答案
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN = 55;
ll nn,kk,mm;
ll dp[MAXN][MAXN][MAXN];
int main()
{
    IO;
    memset(dp,0,sizeof dp);
    for(ll i=0;i<51;i++)    dp[0][0][i]=1;
    for(ll i=1;i<51;i++)
        for(ll j=1;j<51;j++)
            for(ll k=1;k<51;k++)
                for(ll p=1;p<=min(i,k);p++)
                    dp[i][j][k]+=dp[i-p][j-1][k];
    //轉移式 Sigma(1~min(n,m)) dp[n-z][k-1][m]
    while(cin>>nn>>kk>>mm)
        cout<<dp[nn][kk][mm]<<'\n';
    return 0;
}