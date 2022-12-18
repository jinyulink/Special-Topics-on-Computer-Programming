//劉豐萱dp
#include <iostream>
#include<algorithm>

using namespace std;

int x[205], sum, num[20000][20000];

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
            for(j=0;j<=sum;j++)num[i][j]=0;
        }num[0][0]=1;
        for(i=0;i<n;i++){
            for(j=sum;j>=0;j--){
                for(k=sum;k>=0;k--){
                	if(num[j][k]){
                		num[j+x[i]][k]=1;
                		num[j][k+x[i]]=1;
					}
				}
            }
        }
        for(i=0;i<=sum;i++){
        	for(j=0;j<=sum;j++){
        		if(num[i][j]){
        			k=cal(i,j);
        			if(ans>k)ans=k;
				}
			}
		}
        cout<<"Case "<<m<<": "<<ans<<endl;
    }
    return 0;
}