//110403518 林晉宇
//程式設計研討專題 3
//UVA 10482 The Candyman Can
// dp knapsack
//小朋友ABC A的容量為i B的容量為j C的容量為sum-i-j
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const ll MAXN = 2e4+10;
ll t,n,k,sum,ans,coin[210];
bool dp[MAXN][MAXN];
void init()
{
    sum=0;
    memset(dp,0,sizeof dp);
    dp[0][0]=1; //代表 A拿0元 B拿0元 C拿全部
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
                for(ll k=sum;k>=0;k--)
                    if(dp[j][k])
                    {
                        dp[j+coin[i]][k]=1; //代表A拿走coin[i]
                        dp[j][k+coin[i]]=1; //代表B拿走coin[i]
                    }
        ans=INF;
        for(ll i=0;i<=sum;i++)
            for(ll j=0;j<=sum;j++)  
                if(dp[i][j])    ans=min(ans,Min(i,j,sum-i-j)); //找出容量最多的小朋友-容量最少的小朋友 的最小值
        cout<<"Case "<<k-t<<": "<<ans<<'\n';
    }
    return 0;
}