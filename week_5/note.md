# week 5 程式設計研討專題

`01背包`
[01背包 之乎](https://www.zhihu.com/question/265168001)

## 初始化

`dp[i][j]`代表下標 `0-i`的物品任意取，放進容量為 `j`的背包的最大價值是多少。

**首先从dp[i][j]的定义出发，如果背包容量j为0的话，即dp[i][0]，无论是选取哪些物品，背包价值总和一定为0。如图：**
![](https://i.imgur.com/wMelP6j.png)

**只能取物品0的狀況下最大價值當然就是物品0的價值**
![](https://i.imgur.com/wrUYHcO.png)

## 10664 Luggage

有N個不同重量的行李，判斷是否能分出兩堆相同重量的行李放在兩台車上。
[題解](http://tnuier.blogspot.com/2018/03/uva10664-luggage.html)

```cpp=
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN = 2e2+10;
ll t;
string s;
bool dp[MAXN];
int main()
{
    IO;
    cin>>t;
    cin.ignore();
    while(t--&&getline(cin,s))
    {
        ll x,sum=0;
        memset(dp,0,sizeof dp);
        dp[0]=true;
        stringstream ss(s);
        while(ss>>x)
        {
            sum+=x;
            for(ll i=sum;i>=0;i--)  if(dp[i])   dp[i+x]=true;
        }
        cout << (sum%2 ? "NO" : (dp[sum/2] ? "YES" : "NO")) << '\n';
    }
    return 0;
}
```

## 10261 Ferry Loading

![](https://i.imgur.com/QZrCrcG.png)

![](https://i.imgur.com/qfCD5wS.png)

![](https://i.imgur.com/ZNj9zml.png)

```cpp=
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector  
#define pb push_back
using namespace std;
const ll MAXN = 1e4+10;
ll t,pl,tmp,n;
bool dp[MAXN][MAXN],where[MAXN];
ll sum[MAXN],pre[MAXN][MAXN];
vt<ll> car;
void init()
{
    cin>>pl; //車道總長度
    pl*=100;
    car.clear();
    memset(dp,0,sizeof dp);
    dp[0][0]=1; //代表前0輛車 且左邊車道為j時，放在左邊車道的狀態是否可行
    sum[0]=0;
    n=1;
    car.pb(0);
    while(cin>>tmp&&tmp)
    {
        car.pb(tmp);
        sum[n]=sum[n-1]+car[n];
        n++;
    }
    n--;
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        init();
        ll maxcar=0,maxlen;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<=pl;j++)
            {
                if(j-car[i]>=0&&dp[i-1][j-car[i]])
                {
                    dp[i][j]=1;
                    pre[i][j]=1; //放入左車道
                }
                if(sum[i]-j<=pl&&dp[i-1][j])
                {
                    dp[i][j]=1;
                    pre[i][j]=0;
                }
                if(dp[i][j])    maxcar=i,maxlen=j;
            }
            if(maxcar!=i)   break; //代表有車放不進去了，那就直接break，因為接下來的車都進不去了
        }
        cout<<maxcar<<'\n';
        ll tmp=maxcar;
        while(maxcar)
        {
            where[maxcar]=pre[maxcar][maxlen];
            if(pre[maxcar][maxlen]==1)  maxlen-=car[maxcar];
            maxcar--;
        }
        for(ll i=1;i<=tmp;i++)
            cout<<(where[i]?"starboard\n":"port\n");
        if(t)   cout<<'\n';
    }
    return 0;
}
```

## 10690 Expression Again

题意：给你n+m个数，让你分成n个和m个，求它们的和的积的最大和最小
![](https://i.imgur.com/eT2e4ur.png)
![](https://i.imgur.com/fqxZXUE.png)

思路: 动态规划，设dp[i][j]表示用i个组成j的可能性，最后在从所有的可能里求解

```cpp=
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
#define pb push_back
using namespace std;
const ll MAXN = 1e2+10;
ll n,m,sum;
vt<ll> num;
bool dp[MAXN][MAXN*MAXN];
int main()
{
    IO;
    while(cin>>n>>m)
    {   
        num.clear(); sum=0; num.pb(0); dp[0][0]=1;
        memset(dp,0,sizeof dp);
        for(ll i=1,x;i<=n+m;i++)
        {
            cin>>x;
            sum+=x;
            num.pb(x);
            num[i]+=50;
        }
        for(ll i=1;i<=n+m;i++)
            for(ll j=min(i,n);j>=1;j--)
                for(ll k=0;k<=10000;k++)    if(dp[j-1][k])  dp[j][k+num[i]]=1;
        ll Max=-5000,Min=5000;
        for(ll i=0;i<=10000;i++)
            if(dp[n][i])
            {
                ll tmp=i-50*n;
                Max=max(Max,tmp*(sum-tmp));
                Min=min(Min,tmp*(sum-tmp));
            }
        cout<<Max<<" "<<Min<<'\n';
    }
    return 0;
}
```

## 10482 The Candyman Can

题目大意：给许多硬币，分给三个人，要求输出拿钱最多者与拿钱最少者差的最小值。

解题策略：思路同Dividing Coins，定义二维数组dp[i][j]，表示第一个人拿i钱，第二个人拿j钱，第三个人呢？当然硬币总和（sum）-i-j，当前方案可施行，dp=1，否则为0，运用减唯的思想；

```cpp=
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
const ll MAXN = 650;
ll t,k,n,sum;
vt<ll> coin;
ll dp[MAXN][MAXN];
ll Min(ll a,ll b,ll c)
{
    return max({a,b,c})-min({a,b,c});
}
int main()
{
    IO;
    cin>>t; k=t;
    while(t--)
    {
        cin>>n;
        memset(dp,0,sizeof dp); sum=0; coin.clear(); coin.pb(0);
        dp[0][0]=1;
        for(ll i=1,x;i<=n;i++)
        {
            cin>>x;
            sum+=x;
            coin.pb(x);
        }
        for(ll i=1;i<=n;i++)
            for(ll j=sum;j>=0;j--)
                for(ll k=sum;k>=0;k--)
                    if(dp[j][k])
                    {
                        dp[j+coin[i]][k]=1;
                        dp[j][k+coin[i]]=1;
                    }
        ll ans=INF;
        for(ll j=0;j<=sum;j++)
            for(ll k=0;k<=sum;k++)  if(dp[j][k])    ans=min(ans,Min(j,k,sum-j-k));
        cout<<"Case "<<k-t<<": "<<ans<<'\n';

    }
    return 0;
}
```
