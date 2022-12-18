#include<bits/stdc++.h>
#define offset 100000
using namespace std;

bitset<21000> bs[205];
int candies[205], sum[205];
map<int, bool> rec[205];
vector<int> v;
bool check(int idx, int M,int m){
	if(idx < 0)return true;
	
	if(bs[idx+1][M] == 0 || bs[idx+1][m] == 0) return false;
	auto it =rec[idx].find(M*offset+m);
	if(it != rec[idx].end()){
		return it->second;
	}
	if(M >= candies[idx] && check(idx-1, max(M-candies[idx], sum[idx]-M-m), min(M-candies[idx],m))){
		rec[idx][M*offset+m] = true;
		return true;
	}
	if(m >= candies[idx] && check(idx-1, M, m-candies[idx])){
		rec[idx][M*offset+m] = 1;
		return true;
	}
	if(sum[idx]-M-m >= candies[idx] && check(idx-1, M,min(m, sum[idx]-M-m-candies[idx]))){
		rec[idx][M*offset+m] = 1;
		return true;
	}
	rec[idx][M*offset+m] = 0;
	return false;
}

int main(){

	int t;
	int cnt = 1;
	cin>>t;
	while(t--){

		int n;
		cin>>n;
		v.clear();
		for(int i=0;i<=n;i++){
			bs[i] = 0;
			rec[i].clear();
			sum[i] = 0;
		}
		bs[0] = 1;
		for(int i=0;i<n;i++){
			cin>>candies[i];
		}
		sum[0] = candies[0];
		for(int i=1;i<n;i++){
			sum[i] = sum[i-1] + candies[i];
		}
		for(int i=0;i<n;i++){
			bs[i+1] = (bs[i] << candies[i]) | bs[i];
		}

		for(int i=0;i<=sum[n-1];i++){
			if(bs[n][i])
				v.push_back(i);
		}
		
		int ans = sum[n-1];
		for(int i=0;i<ans;i++){
			for(int j=0;j<v.size();j++){
				int k = sum[n-1] - 2*v[j] - i;
				if(k < 0) break;
				if(check(n-1,max(v[j]+i,k),min(v[j],k))){
					ans = min(ans, max(v[j]+i,k)-min(v[j],k));
					if(ans == i) break;
				}
			}
		}
		cout<<"Case "<<cnt<<": "<<ans<<endl;
		cnt++;
	}
	return 0;
}