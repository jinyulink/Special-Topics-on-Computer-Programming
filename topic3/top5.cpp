#include <bits/stdc++.h>
using namespace std;

bitset<20001> w[20001];
//vector<int> candy;

int main ()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t, n, c, s;
    cin >> t;
    for (int cases=1; cases<=t; cases++) {
        //candy.clear();
        s = 0; w[0][0] = 1;
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> c;
            for (int k=s; k>=0; k--) {
                w[k+c] |= w[k];
                w[k] |= w[k] << c;
            }
            s += c;
        }
        //sort(candy.begin(), candy.end());

        int ans = s;
        for (int c1=0; c1<s; c1++) {
            for (int c2=0; c2<s; c2++) {
                if (w[c1][c2]) {
                    ans = min(ans, max(max(c1, c2), s - c1 - c2) - min(min(c1, c2), s - c1 - c2));
                }
            }
        }

        cout << "Case " << cases << ": " << ans << "\n";
        //printf("Case %d: %d\n", cases, ans);
        for (int i=0; i<=s; i++) {
            w[i].reset();
        }
    }

    return 0;
}