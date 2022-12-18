#include<iostream>
#include<bitset>
#include<map>
#include<vector>
#define MX 50000
#pragma GCC optimize("O3")

using namespace std;

bitset<25000> y[205];

map<int,bool> keep[205];

vector<int> v;

int x[205],sum[205];

bool cal(int x1,int Max,int Min){
	if(x1==-1){
		return 1;
	}else if(!y[x1+1][Max] || !y[x1+1][Min]){
		return 0;
	}else{
        auto it=keep[x1].find(Max*MX+Min);
        if(it!=keep[x1].end()){
            return it->second;
        }
        else{
            if(Max>=x[x1] && cal(x1-1, max(Max-x[x1], sum[x1]-Max-Min), min(Max-x[x1], Min))){
                keep[x1][Max*MX+Min]=1;
                return 1;
            }
            if(Min>=x[x1] && cal(x1-1, Max, Min-x[x1])){
                keep[x1][Max*MX+Min]=1;
                return 1;
            }
            if(sum[x1]-Max-Min>=x[x1] && cal(x1-1, Max, min(Min, sum[x1]-Max-Min-x[x1]))){
                keep[x1][Max*MX+Min]=1;
                return 1;
            }
            keep[x1][Max*MX+Min]=0;
            return 0;
        }
	}
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int t,m,n,i,ans,j,k,a,c;
	cin>>t;
	for(m=1;m<=t;m++){
		cin>>n;
		v.clear();
		for(i=0;i<=n;i++){
			y[i]=0;
			keep[i].clear();
			sum[i]=0;
		}
		y[0]=1;
		for(i=0;i<n;i++){
			cin>>x[i];
			sum[i]=x[i];
			y[i+1]=((y[i]<<x[i]) | y[i]);
			if(i>0)sum[i]+=sum[i-1];
		}
		for(i=0;i<=sum[n-1];i++)if(y[n][i])v.push_back(i);
		ans=sum[n-1];
		for(i=0;i<ans;i++){
			for(j=0;j<v.size();j++){
				k=sum[n-1]-2*v[j]-i;
				if(k<0)break;
				a=max(v[j]+i,k);c=min(v[j],k);
				if(cal(n-1,a,c)){
					ans=min(ans,a-c);
					if(ans==i)break;
				}
			}
		}cout<<"Case "<<m<<": "<<ans<<"\n";
	}
}