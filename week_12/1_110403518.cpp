//程式設計研討專題week 12
//UVA 191 Intersection (Geometry)
//110403518 林晉宇
//給一線段及矩形，問兩者是否相交
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;
typedef struct point{
    ll x;
    ll y;
}pt;
ll t;
pt l1,l2,s1,s2;
bool solve()
{
    
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        cin>>l1.x>>l1.y>>l2.x>>l2.y>>s1.x>>s1.y>>s2.x>>s2.y;
        cout<<(solve()?'T':'F')<<'\n';
    }
    return 0;
}