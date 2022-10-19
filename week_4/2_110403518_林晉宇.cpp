// 程式設計研究專題 Week 4
// UVA 10127 Ones 
// 大數處理
// 2022/10/12
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN = 1e5+10;
ll n;
int main()
{
    IO;
    while(cin>>n)
    {
        ll test=0;
        for(ll i=1;i<MAXN;i++)
        {
            test=test*10+1;
            test%=n;
            // cout<<test<<'\n';
            if(!test)
            {
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}