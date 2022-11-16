#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define ll long long
using namespace std;
ll n,t,num;
char c;
set<ll> rbt;
int main()
{
    IO;
    // freopen("input.txt", "r" , stdin);
    // freopen("red_black_tree.txt", "w", stdout);
    cin>>n;
    for(ll i=0,x;i<n;i++)
    {
        cin>>x;
        rbt.insert(x);
    }
    cin>>t;
    while(t--)
    {
        cin>>c>>num;
        if(c=='s')  cout<<(rbt.count(num)?"Found":"Not Found")<<'\n';
        else if(c=='d')
        {
            cout<<(rbt.count(num)?"Delete Success":"Delete Failed")<<'\n';
            if(rbt.count(num)) rbt.erase(num);
        }
        else if(c=='i')
        {
            cout<<(rbt.count(num)?"Insert Failed":"Insert Success")<<'\n';
            if(!rbt.count(num)) rbt.insert(num);
        }
    }
    // cout << "Red Black Tree: " <<(double)clock() / CLOCKS_PER_SEC << " S";
    return 0;
}