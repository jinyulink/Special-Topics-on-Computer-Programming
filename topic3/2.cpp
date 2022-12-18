//110403518 林晉宇
//程式設計研討專題 3
//UVA 10482 The Candyman Can
//bit operation 版本
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;
const ll MAXN = 2e4;
ll t,n,k,sum,ans,coin[201];
bitset<20000> dp[20000];
void init()
{
    sum=0;
    memset(dp,0,sizeof dp);
    dp[0]=1;
}
ll Min(ll a,ll b,ll c)
{
    return max({a,b,c})-min({a,b,c});
}
int main()
{
    IO;
    cin>>t; k=t;
    while(t--)
    {
        init();
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>coin[i];
            sum+=coin[i];
        }
        for(ll i=0;i<n;i++)
            for(ll j=sum;j>=0;j--)
            {
                dp[j+coin[i]]|=dp[j];
                dp[j]|=dp[j]<<coin[i];
            }
        ans=sum;
        for(ll i=0;i<=sum;i++)
            for(ll j=0;j<=sum;j++)  
                if(dp[i][j])    ans=min(ans,Min(i,j,sum-i-j));
        cout<<"Case "<<k-t<<": "<<ans<<'\n';
    }
    return 0;
}