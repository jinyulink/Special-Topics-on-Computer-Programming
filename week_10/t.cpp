#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector
#define pb push_back
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll MAXN =1e3+10;
const ll MAXM =1e5+10;
struct edge{ll to,w;};
ll n,m;
ll path[MAXN];
vt<edge> g[MAXN];
vt<ll> dag[MAXM];
ll dist[MAXN]; bool vis[MAXN];
void add(ll x,ll y,ll c){
    g[x].pb((edge){y,c});
}
void dijkstra(ll S)
{
    memset(vis,0,sizeof vis);
    memset(dist,0x3f,sizeof dist); dist[S]=0;
    priority_queue<pll,vt<pll>,greater<pll>> heap;
    heap.push({dist[S],S});
    while(heap.size())
    {
        pll k=heap.top(); heap.pop();
        ll now=k.S,d=k.F;
        if(vis[now])    continue;
        vis[now]=1;
        for(auto i:g[now]) //O(mlogn)
        {
            ll j=i.to;
            if(dist[j]>d+i.w)
            {
                dist[j]=d+i.w;
                heap.push({dist[j],j});
            }
        }
    }
}
void build_dag()
{
    for(ll i=1;i<=n;i++)
        for(auto j:g[i])
        {
            ll x=i,y=j.to;
            if(dist[x]<dist[y]) dag[y].pb(x);
        }
}
ll dfs(ll S)
{
    if(path[S]) return path[S];
    for(auto i:dag[S])  path[S]+=dfs(i);
    return path[S];
}
void init()
{
    for(auto &i:g)   i.clear();
    for(auto &i:dag)   i.clear();
    memset(path,0,sizeof path);
}
int main()
{
    IO;
    while(cin>>n&&n)
    {
        init();
        cin>>m;
        for(ll i=0,x,y,c;i<m;i++)
        {
            cin>>x>>y>>c;
            add(x,y,c); add(y,x,c); //無向圖
        }
        dijkstra(2);
        build_dag();    
        path[2]=1;
        cout<<dfs(1)<<'\n';
    }
    return 0;
}



