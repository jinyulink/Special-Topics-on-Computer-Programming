//UVA 10199 Tourist Guide
//找出無向圖割點 articulation point (uva 10199/315)
//dfs+back edge
/*
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
u是DFS樹的根節點，因為DFS樹，子樹之間不會相連，會相連就會屬於同一子樹，所以DFS樹的root，只要有兩個以上子樹就是articulation point
u是DFS樹的非根節點，u點的祖先與每個子孫有back edge，該點就不是articulation point，若有一子孫沒有back edge，該點就是articulation point
*/
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
const ll maxn=1e2+10; 
using namespace std;
ll n,r; // node edge
map<ll,string> city;
map<string,ll> cityy;
bool g[maxn][maxn];
void init()
{
    city.clear();
    cityy.clear();
    memset(g,0,sizeof g);
}
int main()
{
    IO;
    while(cin>>n)
    {
        if(!n)  break;
        init();
        for(ll i=0;i<n;i++)
        {
            string s; cin>>s;
            city[i]=s; cityy[s]=i;
        }
        cin>>r;
        for(ll i=0;i<r;i++)
        {
            string sa,sb; cin>>sa>>sb;
            g[cityy[sa]][cityy[sb]]=g[cityy[sb]][cityy[sa]]=true;
        }
        
    }
    return 0;
}