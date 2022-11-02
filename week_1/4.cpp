// 程式設計研究專題 Week 1
// UVA 10137 The Trip
// 2022/11/01
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
using namespace std;
ll n,a,b,c,s,avg,ans;
char d; //小數點
int main()
{
    IO;
    while(cin>>n&&n)
    {
        vt<ll> arr(n);
        s=avg=ans=0;
        for(auto &i:arr)
        {
            cin>>a>>d>>b;
            i=a*100+b;
            s+=i;
        }
        c=s%n; avg=s/n;
        for(auto i:arr) if(i>avg) ans+=i-avg-(c-->0);
        cout<<'$'<<fixed<<setprecision(2)<<ans/100.<<'\n';
    }
    return 0;
}