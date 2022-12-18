#include <iostream>
#include<algorithm>
#include<bitset>

using namespace std;

bitset<25000> bs[25000];

int x[205], sum;

int Max(int a, int b, int c){
    int tmp=max(a,b);
    return max(tmp,c);
}

int Min(int a, int b, int c){
    int tmp=min(a,b);
    return min(tmp,c);
}

int cal(int i, int j){
	return Max(sum-i-j,i,j)-Min(sum-i-j,i,j);
}

int main()
{
    int t,m,n,i,j,k,ans;
    cin>>t;
    for(m=1;m<=t;m++){
        sum=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x[i];
            sum+=x[i];
        }ans=sum;
        for(i=0;i<=sum;i++){
            bs[i]=0;
        }bs[0]=1;
        for(i=0;i<n;i++){
            for(j=sum;j>=0;j--){
                bs[j+x[i]]|=bs[j];
            	bs[j]|=bs[j]<<x[i];
            }
        }
        for(i=0;i<=sum;i++){
        	for(j=0;j<=sum;j++){
        		if(bs[i][j]){
        			k=cal(i,j);
        			if(ans>k)ans=k;
				}
			}
		}
        cout<<"Case "<<m<<": "<<ans<<endl;
    }
    return 0;
}