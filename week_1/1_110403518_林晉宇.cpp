// 程式設計研究專題 Week 1
// UVA 459 Graph Connectivity
// Disjoint Set Union
// 2022/09/21
// 跟dfs比 空間只要O(n) n為點數
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;
const ll MAXN = 30;
ll t,sz,p[MAXN];
string s;
set<ll> ans;
bool blank_line;
void initial()
{
    ans.clear();
    for(ll i=0;i<sz;i++)    p[i]=i;
}
ll find(ll x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void union_set(char a,char b)
{
    p[find(a-'A')]=find(b-'A');
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        if(blank_line)  cout<<'\n';
        blank_line=true;
        cin>>s;
        sz=s[0]-'A'+1;
        initial();
        cin.ignore();
        while(getline(cin,s)&&!s.empty())
            union_set(s[0],s[1]);
        for(ll i=0;i<sz;i++)    ans.insert(find(p[i]));
        cout<<ans.size()<<'\n';
    }
    return 0;
}
