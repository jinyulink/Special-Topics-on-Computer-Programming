// 程式設計研討專題 week11
// 110403518 林晉宇
// UVA 10480 Sabotage
// 最大流最小割
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const ll N = 55;
const ll M = 550;
ll n,m,g[N][N],flow[N][N];
ll p[N],a[N],x[M],y[M],f;
ll maxflow()
{
    queue<ll> q;
    memset(flow,0,sizeof flow);
    f=0;
    while(true)
    {
        memset(a,0,sizeof a);
        a[1]=INF;
        q.push(1);
        while(q.size())
        {
            ll u=q.front(); q.pop();
            for(ll v=1;v<=n;v++)
                if(!a[v]&&flow[u][v]<g[u][v])
                {
                    p[v]=u;
                    a[v]=min(a[u],g[u][v]-flow[u][v]);
                    q.push(v);
                }
        }
        if(a[2]==0) break;
        for(ll u=2;u!=1;u=p[u])
        {
            flow[p[u]][u]+=a[2];
            flow[u][p[u]]-=a[2];
        }
        f+=a[2];
    }
    return f;
}
int main()
{
    IO;
    while(cin>>n>>m&&n&&m)
    {
        memset(g,0,sizeof g);
        for(ll i=0,s,e,c;i<m;i++)
        {
            cin>>s>>e>>c;
            x[i]=s, y[i]=e;
            g[s][e]=g[e][s]=c;
        }
        maxflow();
        for(ll i=0;i<m;i++)
            if( ( !a[x[i]] && a[y[i]] ) || ( a[x[i]] && !a[y[i]] ) ) 
                cout<<x[i]<<' '<<y[i]<<'\n';
        cout<<'\n';
    }
    return 0;
}