#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;
ll t,m,sum,half,coin[110],dp[25010];
void init()
{
    sum=0;
    memset(dp,0,sizeof dp);
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {   
        init();
        cin>>m;
        for(ll i=0;i<m;i++)
        {
            cin>>coin[i];
            sum+=coin[i];
        }
        half=sum/2;

    }   
    return 0;
}