#include<bits/stdc++.h>
// #define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
const ll maxn = 5e4+10;
using namespace std;
struct pt{
    double x,y;
}p[maxn];
int main()
{
    // IO;
    pt A,B,C;
    double a1,b1,c1,a2,b2,c2,X,Y,r,det;
    ll n,q,m,t=1;
    while(cin>>A.x>>A.y>>B.x>>B.y>>n>>q)
    {
        if(!n&&!q)  break;
        for(ll i=1;i<=n;i++)    cin>>p[i].x>>p[i].y;
        cout<<"Case "<<t++<<":\n";
        while(q--)
        {
            bool check=1;
            cin>>m;
            C.x=p[m].x; C.y=p[m].y;
            a1=-A.x+B.x;
            a2=-A.x+C.x;
            b1=-A.y+B.y;
            b2=-A.y+C.y;
            c1=(A.x*A.x+A.y*A.y-B.x*B.x-B.y*B.y)/2.00;
            c2=(A.x*A.x+A.y*A.y-C.x*C.x-C.y*C.y)/2.00;
            det=a1*b2-a2*b1;
            if(abs(det)<1e-9)   check=false;
            X=(b1*c2-b2*c1)/det;
            Y=(a2*c1-a1*c2)/det;
            r=(X-C.x)*(X-C.x)+(Y-C.y)*(Y-C.y);
            if(r-fabs(det)>1e10)    check=false;
            if(!check)  
            {
                cout<<"Impossible\n";
                continue;
            }
            ll cnt=2;
            for(ll i=1;i<=n;i++)
                if((X-p[i].x)*(X-p[i].x)+(Y-p[i].y)*(Y-p[i].y)<r+1e-9)  cnt++;
            cout<<cnt<<'\n';
        }
    }
    return 0;
}