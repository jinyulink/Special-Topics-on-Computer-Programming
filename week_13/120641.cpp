//UVA 12064
//geometry
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
const ll maxn = 5e4+10;
using namespace std;
struct pt{
    double x,y;
}p[maxn];
pt a,b,c;
double a1,b1,c1,a2,b2,c2,X,Y,r,det;
ll n,q,t=1,tt;
int main()
{
    IO;
    while(cin>>a.x>>a.y>>b.x>>b.y>>n>>q)
    {
        if(!n&&!q)  break;
        for(ll i=1;i<=n;i++)    cin>>p[i].x>>p[i].y;
        cout<<"Case "<<t++<<":\n";
        while(q--)
        {
            cin>>tt;
            pt c=p[tt];
            double a1,a2,b1,b2,c1,c2;
            a1=-a.x+b.x;
            a2=-a.x+c.x;
            b1=-a.y+b.y;
            b2=-a.y+c.y;
            c1=(a.x*a.x+a.y*a.y-b.x*b.x-b.y*b.y)/2.00;
            c2=(a.x*a.x+a.y*a.y-c.x*c.x-c.y*c.y)/2.00;
            double det=(a1*b2-a2*b1);
            if(abs(det)<1e-9)
            {
                cout<<"Impossible\n";
                continue;
            }
            double X=(b1*c2-b2*c1)/det;
            double Y=(a2*c1-a1*c2)/det;
            r=(X-c.x)*(X-c.x)+(Y-c.y)*(Y-c.y);
            if(r-fabs(det)>1e10)
            {
                cout<<"Impossible\n";
                continue;
            }
            ll cnt=2;
            for(ll i=1;i<=n;i++)
            {
                if((X-p[i].x)*(X-p[i].x)+(Y-p[i].y)*(Y-p[i].y)<r+1e-9)  cnt++;
            }
            cout<<cnt<<'\n';
        }
    }
    return 0;
}