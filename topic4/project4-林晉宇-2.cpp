//程式設計研討專題 topic 4
//110403518 林晉宇
//karger algorithm (Randomize)
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;
struct Edge{
    ll src,dest,cost;
};
struct Graph{
    ll v,e; //number of vertices / number of edges
    Edge* edge; 
};
struct subset{
    ll parent, rank;
};
struct Graph* createGraph(ll v,ll e){
    Graph* graph=new Graph;
    graph->v=v;
    graph->e=e;
    graph->edge=new Edge[e];
    return graph;
}
ll find(struct subset subsets[],ll i)
{
    if(subsets[i].parent!=i)   subsets[i].parent=find(subsets,subsets[i].parent); //path compression
    return subsets[i].parent;
}
void Union(struct subset subsets[],ll x,ll y)
{
    ll xrt=find(subsets,x);
    ll yrt=find(subsets,y);
    if(subsets[xrt].rank<subsets[yrt].rank) subsets[xrt].parent=yrt;
    else if(subsets[xrt].rank>subsets[yrt].rank)    subsets[yrt].parent=xrt;
    else
    {
        subsets[yrt].parent=xrt;
        subsets[xrt].rank++;
    }
}
ll Karger(struct Graph* graph)
{
    ll v=graph->v,e=graph->e;
    Edge* edge=graph->edge;
    struct subset *subsets=new subset[v];
    for(ll i=0;i<v;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    ll vertices=v;
    while(vertices>2)
    {
        ll i=rand()%e;
        ll subset_s=find(subsets,0);
        ll subset_t=find(subsets,1);
        ll subset1=find(subsets,edge[i].src);
        ll subset2=find(subsets,edge[i].dest);
        if(subset1==subset2)    continue;
        else if((subset_s==subset1&&subset_t==subset2)||(subset_t==subset1&&subset_s==subset2)) continue; //如果隨機選到的邊包含s跟t兩點，則忽略 重新選
        else
        {
            // cout<<edge[i].src+1<<' '<<edge[i].dest+1<<'\n';
            vertices--;
            Union(subsets,subset1,subset2);
        }
    }
    int cutedge=0;
    for(ll i=0;i<e;i++)
    {
        ll subset1=find(subsets,edge[i].src);
        ll subset2=find(subsets,edge[i].dest);
        if(subset1!=subset2)    cutedge+=edge[i].cost;
    }
    return cutedge;
}
ll n,m;
int main()
{
    IO;
    // freopen("input.txt", "r" , stdin);
    // freopen("karger.txt", "w", stdout);
    while(cin>>n>>m)
    {
        if(!n&&!m)  break;
        struct Graph* graph=createGraph(n,m);
        for(ll i=0;i<m;i++)
        {
            ll u,v,w;   cin>>u>>v>>w;
            graph->edge[i].src=u-1;
            graph->edge[i].dest=v-1;
            graph->edge[i].cost=w;
        }
        srand(time(NULL));
        ll res=Karger(graph);
        cout<<res<<'\n';
    }
    cout <<(double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}