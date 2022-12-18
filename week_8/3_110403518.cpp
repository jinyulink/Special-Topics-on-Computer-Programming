// 程式設計研究專題 Week 8
//主題: MST DSU
//UVA 10158 War
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN = 1e4+10;
ll n,t,a,b;
ll p[2*MAXN];
void init()
{
    for(ll i=0;i<2*n;i++)   p[i]=i;
}
ll find(ll x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void setFriends(ll a,ll b)
{
    p[find(a)]=find(b);
    p[find(a+n)]=find(b+n);
}
void setEnemies(ll a,ll b)
{
    p[find(a)]=find(b+n);
    p[find(a+n)]=find(b);
}
bool areFriends(ll a,ll b)
{
    if(find(a)==find(b))    return true;
    return false;
}
bool areEnemies(ll a,ll b)
{
    if(find(a)==find(b+n))  return true;
    return false;
}
int main()
{
    IO;
    cin>>n;
    init(); //並查集初始化，把每個點的父親設成自己
    while(cin>>t>>a>>b)
    {
        if(t+a+b==0)    break;
        if(t==1)
        {
            if(areEnemies(a,b)) cout<<"-1\n";
            else    setFriends(a,b);
        }
        else if(t==2)
        {
            if(areFriends(a,b)) cout<<"-1\n";
            else    setEnemies(a,b);
        }
        else if(t==3)
        {
            if(areFriends(a,b)) cout<<"1\n";
            else    cout<<"0\n";
        }
        else if(t==4)
        {
            if(areEnemies(a,b)) cout<<"1\n";
            else    cout<<"0\n";
        }
    }
    return 0;
}