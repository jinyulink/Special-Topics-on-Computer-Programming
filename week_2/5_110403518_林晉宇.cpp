// 程式設計研究專題 Week 2
// UVA 00311 Packets
// Greedy
// 2022/09/29
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
ll num[7];
bool input()
{
    for(ll i=1;i<=6;i++)    cin>>num[i];
    return true;
}
int main()
{
    IO;
    while(input())
    {
        for(ll i=1;i<=6;i++)
        {
            if(i==6&&num[i]==0) return 0;
            if(num[i]!=0)   break;
        }
        ll ans=num[6]+num[5]+num[4];
        num[1]-=11*num[5];
        num[2]-=5*num[4];
        ans+=(num[3]/4);
        if(num[3]%4)    ans++;
        switch(num[3]%4)
        {
            case 1:
                num[2]-=5;
                num[1]-=7;
                break;
            case 2:
                num[2]-=3;
                num[1]-=6;
                break;
            case 3:
                num[2]-=1;
                num[1]-=5;
                break;
        }
        if(num[2]>0)
        {
            ans+=num[2]/9;
            if(num[2]%9)    ans++;
            num[1]-=36-(num[2]%9)*4;
        }
        else if(num[2]<0)
            num[1]-=(-num[2])*4;
        if(num[1]>0)
        {
            ans+=num[1]/36;
            if(num[1]%36)   ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}