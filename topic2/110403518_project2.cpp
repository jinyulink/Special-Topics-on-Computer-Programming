#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
#define pb push_back
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
ll N,t,num; char c;
vt<ll> n; //代表每個陣列有幾個有效元素，如果是0，表示該陣列為空
vt<vt<bool>> exist; //紀錄該數是否還存在
vt<vt<ll>> dbs; //dynamic_binary_search 二維vector,每個元素代表一個sorted array
pll search(ll x)
{
    pll ret={-1,-1}; //返回x所在位置，如果x不存在，return -1,-1
    for(ll i=0;i<dbs.size();i++)
    {
        if(!n[i])   continue; //代表當前遍歷到的為一空陣列 忽略 繼續迴圈
        ll l=0,r=dbs[i].size()-1; //二分搜遍例到的每個陣列
        while(l<r) 
        {
            ll mid=l+r>>1;
            if(x>dbs[i][mid])   l=mid+1;
            else r=mid;
        }
        ll pos=l;//二分搜結束
        if(dbs[i][pos]!=x)  continue; //如果找到的位置的值不是x，則略過，繼續執行
        else if(dbs[i][pos]==x&&exist[i][pos])  ret.F=i,ret.S=pos; //如果是x，且並未被刪除，則return所在位置
    }
    return ret;
}
void merge(vt<ll> &a,vt<bool> &b,ll h)
{
    if(h>=n.size()) //如果h已超過現在的深度，則在新增一層空陣列進去
    {
        ll k=pow(2,h);
        vt<ll> tmpv; vt<bool> tmpb;
        for(ll i=0;i<k;i++)
            tmpv.pb(0),tmpb.pb(0);
        dbs.pb(tmpv); exist.pb(tmpb);
        n.pb(0);
    }
    if(!n[h]) //如果h層為空
    {
        for(ll i=0;i<a.size();i++)
        {
            dbs[h][i]=a[i]; exist[h][i]=b[i];
            if(b[i])    n[h]++;
        }
        return ;
    }
    vt<ll> tmpa; vt<bool> tmpb;
    ll l=0,r=0;
    while(l<dbs[h].size()&&r<a.size())
        if(dbs[h][l]<a[r])
            tmpa.pb(dbs[h][l]),tmpb.pb(exist[h][l++]);
        else
            tmpa.pb(a[r]),tmpb.pb(b[r++]);
    while(l!=dbs[h].size())
        tmpa.pb(dbs[h][l]),tmpb.pb(exist[h][l++]);
    while(r!=a.size())
        tmpa.pb(a[r]),tmpb.pb(b[r++]);
    n[h]=0; //原本那一層的array變為空陣列
    merge(tmpa,tmpb,h+1); //繼續merge
}
bool insert(ll x)
{
    pll srch=search(x);
    if(srch.F==-1)
    {
        vt<ll> a; vt<bool> b;
        a.pb(x); b.pb(true);
        merge(a,b,0);
    }
    else if(!exist[srch.F][srch.S]) exist[srch.F][srch.S]=true,n[srch.F]++; //代表這點存在陣列裡面，但是被標記為不存在，這時只需將其改為存在即可
    else if(exist[srch.F][srch.S])   return false; //代表已經存在這一點了
    return true;
}
bool deleten(ll x)
{
    pll pos=search(x);
    if(pos.F==-1)   return false;
    if(!exist[pos.F][pos.S])    return false;
    exist[pos.F][pos.S]=false;  n[pos.F]--; //刪除該點(記一個標記)
    ll h=pos.F;
    if((n[h]*2)==pow(2,h)) //如果該層有一半的點都已經被刪除
    {
        if(!n[h-1])// 且上一層為空，則把這一半的點全部移至上一層
        {
            n[h]=0; n[h-1]=pow(2,h-1);
            ll tmp=0;
            for(ll i=0;i<dbs[h].size();i++)
            {
                if(exist[h][i])
                {
                    dbs[h-1][tmp]=dbs[h][i];
                    exist[h-1][tmp++]=exist[h][i];
                }
            }
        }
        else
        {
            vt<ll> tmpv; vt<bool> tmpb;
            for(ll i=0;i<dbs[h].size();i++)
                if(exist[h][i])
                    tmpv.pb(dbs[h][i]),tmpb.pb(exist[h][i]);
            n[h]=0;
            merge(tmpv,tmpb,h-1);
        }
    }
    return true;
}
void init()
{
    ll tmp=ceil(log2(N+1)),a=1; //先建構一個log2(N+1)層的二維陣列，裡面全部塞0
    while(tmp--)
    {
        vt<ll> tmpv; vt<bool> tmpb;
        for(ll i=0;i<a;i++)
            tmpv.pb(0),tmpb.pb(0);
        dbs.pb(tmpv); exist.pb(tmpb);
        n.pb(0);
        a*=2;
    }
}
int main()
{
    IO;
    // freopen("input.txt", "r" , stdin);
    // freopen("dynamic_binary_search.txt", "w", stdout);
    cin>>N;
    init();
    for(ll i=0,x;i<N;i++)
    {
        cin>>x;
        insert(x);
    }
    cin>>t;
    while(t--)
    {
        cin>>c>>num;
        if(c=='s')
            cout<<(search(num).F!=-1?"Found":"Not Found")<<'\n';
        else if(c=='i')
            cout<<(insert(num)?"Insert Success":"Insert Failed")<<'\n';
        else if(c=='d')
            cout<<(deleten(num)?"Delete Success":"Delete Failed")<<'\n';
    }
    // cout << "Dynamic Binary Search: " <<(double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}