//week7
//dp
// uva 10154
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN =6e3+10;
typedef struct node{
    ll w,m;
}d;
bool cmp(d a,d b)
{
    return a.m<b.m;
}
d data[MAXN];
ll dp[MAXN];
int main()
{
    IO;
    ll cnt=1;
    while(cin>>data[cnt].w>>data[cnt++].m)
    sort(data+1,data+cnt,cmp);
    memset(dp,0x3f,sizeof dp);
    dp[0]=0; 
    ll ans=0;
    for(ll i=1;i<cnt;i++)
        for(ll j=ans+1;j>0;j--)
            if(dp[j]>dp[j-1]+data[i].w&&data[i].m>dp[j-1]+data[i].w)
            {
                dp[j]=dp[j-1]+data[i].w;
                ans=max(ans,j);
            }
    cout<<ans<<'\n';
    return 0;
}