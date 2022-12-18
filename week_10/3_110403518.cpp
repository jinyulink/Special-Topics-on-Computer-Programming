//程式設計研討專題 ｗeek 10
//UVA 10917 Walk Through the Forest 
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll MAXN = 1e5+10;
ll n,m;
ll path[MAXN];
ll h[MAXN],e[MAXN],ne[MAXN],idx; ll w[MAXN];
ll dist[MAXN]; bool st[MAXN];
void add(ll x,ll y,ll c) //adjacency list
{
    w[idx]=c; e[idx]=y; ne[idx]=h[x]; h[x]=idx++;
}
void dijkstra(ll S)
{
    memset(dist,0x3f,sizeof dist); dist[S]=0;
    priority_queue<pll,vt<pll>,greater<pll>> heap; //小根堆
    heap.push({dist[S],S});
    while(heap.size())
    {
        pll k=heap.top(); heap.pop();
        ll now=k.S,d=k.F;
        if(st[now]) continue;
        st[now]=1;
        for(ll i=h[now];i!=-1;i=ne[i])
        {
            ll j=e[i];
            if(dist[j]>d+w[i])
            {
                dist[j]=d+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}
ll dfs(ll S) //記憶化搜尋 
{
    if(path[S])   return path[S];
    if(S==2)    return 1; //到達2，路徑數＋1
    for(ll i=h[S];i!=-1;i=ne[i]) //遍歷所有與S相連的邊
    {
        ll j=e[i];
        if(dist[j]<dist[S])  path[S]+=dfs(j); //如果 j點到2的距離 < S點到2的距離，則 S到2的路徑數+=j到2的路徑數
    }
    return path[S];
}
void init()
{
    memset(h,-1,sizeof h); memset(e,0,sizeof e); memset(ne,0,sizeof ne); memset(w,0,sizeof w);
    idx=0;
    memset(st,0,sizeof st); memset(path,0,sizeof path);
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
        dijkstra(2); //以2為源點跑Dijkstra
        init();
        
        cout<<dfs(1)<<'\n';
    }
    return 0;
}