//110403518 林晉宇
//程式設計研討專題 3
//UVA 10482 The Candyman Can
//top down 版本
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define ve vector
#define pb push_back
using namespace std;
const ll MAXN = 2e4;
ll t,n,k,sum[201],ans,coin[201];
bitset<20000> dp[20000];
vt<ll> v;
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
            dp[i+1]=((dp[i]<<coin[i])|dp[i]);
            if(i) sum[i]+=sum[i-1];
        }
        for(ll i=0;i<=sum[n-1];i++) if(dp[n][i])    v.pb(i);
        ans=sum[n-1];
        for(ll i=0;i<=ans;i++)
            for(ll j=0;j<=v.size();j++)  
            {
                ll k=sum[n-1]-2*v[j]-i
                if(k<0) break;
                
            }
        cout<<"Case "<<k-t<<": "<<ans<<'\n';
    }
    return 0;
}