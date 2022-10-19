//程式設計研討專題一
//暴力 O(n^2)
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
#define pb push_back
using namespace std;
const ll MAXN = 1e6+10;
struct point{
    ll x,y,z;
};
bool cmp(point a, point b){
    if(a.x==b.x)
    {
        if(a.y==b.y)    return a.z>b.z;
        return a.y>b.y;
    }
    return a.x>b.x;
}
ll n;
point p[MAXN];
bool check[MAXN];
vt<point> ans;
int main()
{
    IO;
    freopen("input.txt", "r" , stdin);
    freopen("brute_force.txt","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++) 
    {
        cin>>p[i].x>>p[i].y>>p[i].z;
        check[i]=true;
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(p[i].x<=p[j].x&&p[i].y<=p[j].y&&p[i].z<=p[j].z&&i!=j)
                check[i]=false;
        }
    }
    for(ll i=0;i<n;i++) if(check[i])    ans.pb(p[i]);
    sort(ans.begin(),ans.end(),cmp);
    // for(auto i:ans) cout<<i.x<<" "<<i.y<<" "<<i.z<<'\n';
    cout << "Brute Force: " <<(double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}