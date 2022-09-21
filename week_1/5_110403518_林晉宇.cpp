// 程式設計研究專題 Week 1
// UVA 10324 Zeros and Ones
// Prefix Sum
// 2022/09/21
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
const ll MAXN= 1e7+10;
string s;
ll t,a,b,p[MAXN],cnt=1;
bool ans;
void initial() //prefix sum
{
    p[0]=0;
    for(ll i=1;i<=s.length();i++)    p[i]=p[i-1]+(s[i-1]-'0');
    cout<<"Case "<<cnt++<<":\n";
}
int main()
{
    IO;
    while(cin>>s)
    {
        initial();
        cin>>t;
        while(t--)
        {
            ans=false;
            cin>>a>>b;
            if(a>b) swap(a,b);
            if((p[b+1]-p[a])==0||(p[b+1]-p[a])==(b-a+1))    ans=true;
            if(ans) cout<<"Yes\n";
            else    cout<<"No\n";
        }
    }
    return 0;
}