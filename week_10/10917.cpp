//UVA 10917
//Dijkstra DAG dfs
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector 
#define pb push_back
#define pll pair<ll,ll>
#define F first
#define S second
#define INF 0x3f3f3f3f3f3f3f3f
const ll maxn = 1e3+10;
using namespace std;
ll n,m;
ll dist[maxn];
bool vis[maxn];
vt<pll> g[maxn];
void dijkstra(ll s)
{
    memset(dist,INF,sizeof dist);   memset(vis,0,sizeof vis);
    dist[s]=0;
    priority_queue<pll,vt<pll>,greater<pll>> heap;  
    heap.push({dist[s],s});
    while(!heap.empty())
    {
        pll t=heap.top(); heap.pop();
        ll now=t.S,d=t.F;
        if(vis[now])    continue;
        vis[now]=1;
        for(auto i:g[now])
        {
            ll j=i.F;
            if(dist[j]>d+i.S)
            {
                dist[j]=d+i.S;
                heap.push({dist[j],j});
            }
        }
    }
}
int main()
{
    IO;
    while(cin>>n)
    {
        if(!n)  break;
        cin>>m;
        for(ll i=0,u,v,w;i<m;i++)
        {
            cin>>u>>v>>w;
            g[u].pb({v,w}); g[v].pb({v,w});
        }
        dijkstra(2);
    }
    return 0;
}