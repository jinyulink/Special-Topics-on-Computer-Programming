//程式設計研討專題 topic 4
//110403518 林晉宇
//UVA 10480 Sabotage
//flow dinic + 當前弧優化
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f 
using namespace std;
const ll maxn=55, maxm=510;
struct node{ ll u,v,flow,nxt; }edge[maxm*8]; //不知道為啥乘8;
ll n,m,s=1,t=2,cnt,f,d; //點 邊 源點 匯點 
ll head[maxm],dis[maxm],pre[maxm],cur[maxm],vis[maxm];
void init()
{
    cnt=0;
    memset(head,-1,sizeof head);
    memset(vis,0,sizeof vis);
}
void addedge(ll u,ll v,ll flow)
{
    edge[cnt].u=u,edge[cnt].v=v,edge[cnt].flow=flow;
    edge[cnt].nxt=head[u],head[u]=cnt++;
} 
ll bfs() //find level graph
{
    memset(dis,-1,sizeof dis);
    queue<ll> q; dis[s]=0; q.push(s);
    while(!q.empty())
    {
        ll u=q.front(); q.pop();
        for(ll i=head[u];i!=-1;i=edge[i].nxt)
        {
            ll v=edge[i].v;
            if(dis[v]==-1&&edge[i].flow)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]!=-1; //如果等於-1代表 就沒有augmenting path 可以直接終止循環
}
ll dfs(ll u,ll flow) //find augmenting path
{
    if(u==t)    return flow;
    for(int i=cur[u];i!=-1;i=edge[i].nxt)
    {
        ll v=edge[i].v;
        if(dis[v]==dis[u]+1&&edge[i].flow)
        {
            ll d=dfs(v,min(edge[i].flow,flow));
            if(d>0)
            {
                edge[i].flow-=d;
                edge[i^1].flow+=d;
                return d;
            }
        }
    }
    return 0;
}
ll dinic()
{
    ll ans=0;
    while(bfs())
    {
        for(ll i=0;i<=n;i++)    cur[i]=head[i];
        while(d=dfs(s,inf)) ans+=d;
    }
    return ans;
}
void find(ll k)
{
    vis[k]=1;
    for(ll i=head[k];i!=-1;i=edge[i].nxt)
    {
        ll v=edge[i].v;
        if(vis[v]||edge[i].flow<=0)    continue;
        find(v);
    }
}
int main()
{
    IO;
    // freopen("input.txt", "r" , stdin);
    // freopen("flow.txt", "w", stdout);
    while(cin>>n>>m)
    {
        if(!n&&!m)  break;
        init();
        for(ll i=0,u,v,w;i<m;i++)
        {
            cin>>u>>v>>w;
            addedge(u,v,w); addedge(v,u,w);
        }
        // cout<<dinic()<<'\n';
        dinic();
        find(s);
        for(ll i=0;i<cnt;i+=2)
        {
            ll u=edge[i].u,v=edge[i].v;
            if(vis[u]&&!vis[v]||!vis[u]&&vis[v])    cout<<u<<' '<<v<<'\n';
        }
        cout<<'\n';
    }
    // cout <<(double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}