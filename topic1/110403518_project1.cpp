//程式設計研討專題一
//線段樹O(nlogn)+離散化
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
#define pb push_back
using namespace std;
const ll MAXN = 1e6+10;
struct point{
    ll x,y,z;
}p[MAXN];
ll n;
ll tree[(MAXN<<1)+10];
bool check[MAXN];
vt<ll> discrete; //y座標離散化
bool cmp(point a, point b){
    if(a.x==b.x)
    {
        if(a.y==b.y)    return a.z>b.z;
        return a.y>b.y;
    }
    return a.x>b.x;
}
ll find_index_y(ll y) //二分搜查找y座標對應的下標
{
    ll l=0,r=discrete.size()-1;
    while(l<r)
    {
        ll mid=l+r>>1;
        if(discrete[mid]>=y)    r=mid;
        else    l=mid+1;
    }
    return r+1;
}
void pushup(ll now)
{
    tree[now]=max(tree[now<<1],tree[now<<1|1]);
}
void build_tree(ll l,ll r,ll now)
{
    if(l==r)
    {
        tree[now]=INT_MIN;
        return;
    }
    ll mid=l+r>>1;
    build_tree(l,mid,now<<1);
    build_tree(mid+1,r,now<<1|1);
    pushup(now);
}
void update(ll pos,ll val,ll l,ll r,ll now)
{
    if(l==r)
    {
        tree[now]=val;
        return ;
    }
    ll mid=l+r>>1;
    if(pos<=mid)    update(pos,val,l,mid,now<<1);
    else    update(pos,val,mid+1,r,now<<1|1);
    pushup(now);
}
ll query(ll L,ll R,ll l,ll r,ll now)
{
    if(L<=l&&r<=R)
    {
        return tree[now];
    }
    ll mid=l+r>>1;
    ll ret=INT_MIN;
    if(L<=mid)  ret=max(ret,query(L,R,l,mid,now<<1));
    if(R>mid) ret=max(ret,query(L,R,mid+1,r,now<<1|1));
    return ret;
}
void init()
{
    cin>>n;
    for(ll i=0;i<n;i++) //輸入
    {
        cin>>p[i].x>>p[i].y>>p[i].z;
        check[i]=true;
        discrete.pb(p[i].y);
    }
}
void solve()
{
    build_tree(1,n,1);
    for(ll i=0;i<n;i++) 
    {
        if(query(find_index_y(p[i].y),discrete.size(),1,n,1)>=p[i].z)
        {
            check[i]=false;
        }
        update(find_index_y(p[i].y),p[i].z,1,n,1);
    }
}
int main()
{
    IO;
    // freopen("input.txt", "r" , stdin);
    // freopen("segment_tree.txt", "w", stdout);
    init(); //初始化 輸入點座標
    sort(p,p+n,cmp); //先排序x座標
    sort(discrete.begin(),discrete.end()); //將y座標離散化
    discrete.erase(unique(discrete.begin(),discrete.end()),discrete.end()); //將y座標離散化
    solve(); //建樹 遍歷每個點做搜尋
    for(ll i=0;i<n;i++) if(check[i])    cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].z<<'\n';
    // cout << "Segment Tree: " <<(double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}