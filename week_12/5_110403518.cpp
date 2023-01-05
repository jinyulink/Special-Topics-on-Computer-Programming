//程式設計研討專題 week 12
//leetcode 587 Erect the Fence
//凸包 Andrew
//凸包
#define ll int
#define vt vector
#define pb push_back
class Solution {
public:
    ll cross(vt<ll> &p,vt<ll> &q, vt<ll> &r){
        return (q[0]-p[0])*(r[1]-q[1])-(q[1]-p[1])*(r[0]-q[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        ll n=trees.size();
        if(n<4) return trees;
        sort(trees.begin(),trees.end());
        vt<ll> hull;
        vt<bool> used(n,false);
        hull.pb(0);
        //下凸包
        for(ll i=1;i<n;i++){
            while(hull.size()>1&&cross(trees[hull[hull.size()-2]],trees[hull[hull.size()-1]],trees[i])<0){
                used[hull.back()]=false;
                hull.pop_back();
            }
            used[i]=true;
            hull.pb(i);
        }
        //下凸包 完
        ll m=hull.size(); //一半的凸包數量
        //上凸包 
        for(ll i=n-2;i>=0;i--){
            if(!used[i]){
                while(hull.size()>m&&cross(trees[hull[hull.size()-2]],trees[hull[hull.size()-1]],trees[i])<0){
                    used[hull.back()]=false;
                    hull.pop_back();
                }
                used[i]=true;
                hull.pb(i);
            }
        }
        //上凸包 完
        hull.pop_back();
        vt<vt<int>> res;
        for(auto i:hull)    res.pb(trees[i]);
        return res;
    }
};