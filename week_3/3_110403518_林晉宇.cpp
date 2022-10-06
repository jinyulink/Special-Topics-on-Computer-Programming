// 程式設計研究專題 Week 3
// UVA 10679 I Love Strings!!
// KMP
// 2022/10/06
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
using namespace std;
const ll MAXN = 1e5+10;
ll t,q;
string s,qs;
ll failure[MAXN];
bool KMP(string& t, string& p)
{
    if (p.size() > t.size()) return false;
    for (ll i=1, j=failure[0]=-1; i<p.size(); ++i)
    {
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }
    bool flag=false;
    for (ll i=0, j=-1; i<t.size(); ++i)
    {
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1)
        {
            flag=true;
            j = failure[j];
        }   
    }   
    return flag;
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        cin>>s>>q;
        while(q--)
        {
            cin>>qs;
            cout<<(KMP(s,qs)?"y\n":"n\n");
        }
    }
    return 0;
}