//UVA 10278
//floyd 多源自短路徑
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const ll maxn=5e2+10;
ll t,n,m; //n=fire station m=edge
ll dist[maxn][maxn];
vt<ll> fire;
void init()
{
    memset(dist,INF,sizeof dist);
    for(ll i=0;i<maxn;i++)  dist[i][i]=0;
    cin>>n>>m;
    for(ll i=0,j;i<n;i++)
    {
        cin>>j;
        fire.pb(j);
    }
    for(ll i=0,u,v,w;i<m;i++)
    {
        cin>>u>>v>>w;
        dist[u][v]=w;   dist[v][u]=w;
    }
}
void floyd()
{
    for(ll i=0;i<m;i++)
        for(ll j=0;j<m;j++)
            for(ll k=0;k<m;k++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        init(); //floyd initial
        floyd();

    }
    return 0;
}