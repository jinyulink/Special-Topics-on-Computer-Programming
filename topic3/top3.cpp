#include <bits/stdc++.h>
using namespace std;
//8ms

int n,sum[205];             //sum?臬?蝬游?
map<int,bool> known[205];    //瘥??潛?憟賜?蝑?
bitset<20005> dp[205];      //蝚枰????摰??臬?臭誑蝮賡?j
vector<int> candy;

bool recursive(int layer,int a,int c) {
	if(layer==-1) return true;
	if(!dp[layer+1][a] || !dp[layer+1][c]) return false;
	
	auto iter = known[layer].find(a*20000+c);
	if(iter != known[layer].end()) return iter->second; //憒?蝞?撠勗???
	int now=candy[layer],b=sum[layer]-a-c;
	
	if(now <= a && recursive(layer-1,max(a-now,b),min(a-now,c))){
		known[layer][a*20000+c] = true;
		return true;
	}
	if(now <= b && recursive(layer-1,a,min(b-now,c))){
		known[layer][a*20000+c] = true;
		return true;
	}
	if(now <= c && recursive(layer-1,a,c-now)){
		known[layer][a*20000+c] = true;
		return true;
	}
	known[layer][a*20000+c] = false;
	return false;
}

int main(){
    int cases,temp;
	cin>>cases;
	for(int i=0;i<cases;i++){
		cin>>n;
		candy.clear();
		for(int j=0;j<=n;j++){
			sum[j] = 0;
			dp[j].reset();
			known[j].clear();
		}
		for(int j=0;j<n;j++){
			cin>>temp;
			candy.push_back(temp);
		}
		sort(candy.begin(),candy.end());
		dp[0][0]=true;
		for(int j=0;j<n;j++){
			sum[j]=candy[j];
			dp[j+1] |= dp[j];
			dp[j+1] |= (dp[j]<<sum[j]);
			if(j!=0) sum[j]+=sum[j-1];
		}
		
		int ans=100;
		for(int j=0;j<ans;j++){
			for(int k=max((sum[n-1]-2*j)/3,0);k<=sum[n-1]-k*2-j;k++) {
				int a=max(k+j,sum[n-1]-k*2-j),c=min(k,sum[n-1]-k*2-j);
				if(a-c == j && recursive(n-1,a,c)) {
					ans=min(a-c,ans);
                  	if(j==ans) break;
				}
			}
		}
		cout<<"Case "<<i+1<<": "<<ans<<endl;
	}
}