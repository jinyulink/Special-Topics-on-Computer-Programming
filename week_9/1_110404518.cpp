//程式設計研討專題 week9
//UVA 721 Invitation Cards
//原圖Dijkstra+反向圖Dijkstra
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector
#define pb push_back
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll MAXN = 1e6+10;
ll ans;
ll t,p,q,x,y,c;
ll h[MAXN],e[MAXN],ne[MAXN],idx; ll w[MAXN];
ll dist[MAXN]; bool st[MAXN];
void add(ll x,ll y,ll c) //adjacency list
{
    w[idx]=c; e[idx]=y; ne[idx]=h[x]; h[x]=idx++;
}
void dijkstra()
{
    memset(dist,0x3f,sizeof dist); dist[1]=0;
    priority_queue<pll,vt<pll>,greater<pll>> heap; //small
    heap.push({0,1}); //dist node
    while(heap.size())
    {
        pll k=heap.top();
        heap.pop();
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
void init()
{
    memset(h,-1,sizeof h); memset(e,0,sizeof e); memset(ne,0,sizeof ne); memset(w,0,sizeof w);
    idx=0;
    memset(st,0,sizeof st);
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        ans=0;
        vt<ll> xx,yy,cc;
        init();
        cin>>p>>q;
        for(ll i=0;i<q;i++)
        {
            cin>>x>>y>>c;
            xx.pb(x),yy.pb(y),cc.pb(c);
            add(x,y,c);
        }
        dijkstra();
        for(ll i=1;i<=p;i++)  ans+=dist[i];
        
        init();
        for(ll i=0;i<q;i++) add(yy[i],xx[i],cc[i]);
        dijkstra();
        for(ll i=1;i<=p;i++)  ans+=dist[i];
        cout<<ans<<'\n';
    }
    return 0;
}