//UVA 10278
//floyd
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector 
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
const ll maxn = 5e2+10;
using namespace std;
ll t,n,m,maxs,ans; //case fire station intersection
ll dist[maxn][maxn],to_fire[maxn];
vt<ll> fire; // fire station 
void init()
{
    cin>>n>>m;
    for(ll i=1,u;i<=n;i++)
    {
        cin>>u;
        fire.pb(u);
    }
    maxs=0; ans=1;
    memset(dist,INF,sizeof dist);
    memset(to_fire,INF,sizeof to_fire);
    for(ll i=1,u,v,w;i<=m;i++)
    {
        dist[i][i]=0;
        cin>>u>>v>>w;
        dist[u][v]=w; dist[v][u]=w;
    }   
}
void floyd()
{
    for(ll k=1;k<=m;k++)
        for(ll i=1;i<=m;i++)
            for(ll j=1;j<=m;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        init();
        floyd();
        for(ll i=1;i<=m;i++)
        {
            for(auto j:fire)
                to_fire[i]=min(to_fire[i],dist[i][j]);
            maxs=max(maxs,to_fire[i]);
        }
        for(ll i=1;i<=m;i++) //if i is fire station
        {
            ll tmp=0;
            for(ll j=1;j<=m;j++)
            {
                ll tmp2=min(dist[i][j],to_fire[j]);
                tmp=max(tmp,tmp2);
            }
            if(tmp<maxs)
            {
                maxs=tmp;
                ans=i;
            }
        }
        cout<<ans<<'\n';
        if(t)   cout<<'\n';
    }
    return 0;
}