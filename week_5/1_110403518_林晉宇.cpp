//程式設計研討專題 week5
//01背包 UVA10664
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define vt vector
#define pb push_back
using namespace std;
const ll MAXN = 1e3+10;
ll t,m,tmp;
bool flag;
ll dp[MAXN];
int main()
{
    IO;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        tmp=0,m=0;
        vt<ll> bp;
        flag=true;
        memset(dp,0,sizeof dp);
        string s;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>tmp)
        {
            bp.pb(tmp);
            m+=tmp;
        }
        for(ll i=0;i<bp.size();i++)
            for(ll j=m/2;j>=bp[i];j--)
                dp[j]=max(dp[j],dp[j-bp[i]]+bp[i]); //滾動數組
        if(dp[m/2]!=m/2)    flag=false;
        if(m%2) flag=false;
        cout<<(flag?"YES\n":"NO\n");
    }
    return 0;
}