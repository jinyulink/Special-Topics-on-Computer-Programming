#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
// #pragma GCC optimize("O3,unroll-loops")

#define N 200
#define M 200001

using namespace std;

map<int, bool> cache[N];
bitset<M> distrb[N];
int candy[N], sum[N];

bool solve(int i, int low, int high) {

    if (i == -1) return true;

    if (!distrb[i][low] || !distrb[i][high]) return false;

    auto it = cache[i].find(low * M + high);
    if (it != cache[i].end()) return it->second;

    int mid = sum[i] - low - high;

    if (high - candy[i] >= 0 && solve(i - 1, min(low, high - candy[i]), max(mid, high - candy[i])))
        return cache[i][low * M + high] = true;
    if (mid - candy[i] >= 0 && solve(i - 1, min(low, mid - candy[i]), high))
        return cache[i][low * M + high] = true;
    if (low - candy[i] >= 0 && solve(i - 1, low - candy[i], high))
        return cache[i][low * M + high] = true;

    return cache[i][low * M + high] = false;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m;
    for (int c = 1; c <= m; c++) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> candy[i];
            cache[i].clear();
        }
        sort(candy, candy + n);

        sum[0] = candy[0];
        distrb[0][0] = true;
        distrb[0][candy[0]] = true;
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + candy[i];
            distrb[i] = distrb[i - 1] | (distrb[i - 1] << candy[i]);
        }

        int ans = sum[n - 1];
        for (int i = 0; i < ans; i++) {
            for (int it = max((sum[n - 1] - i - i) / 3, 0); it <= sum[n - 1] - i - it - it; it++) {
                int j = max(it + i, sum[n - 1] - i - it - it);
                if (solve(n - 1, it, j)) {
                    ans = min(ans, j - it);
                    if (i == ans) break;
                }
            }
        }
        cout << "Case " << c << ": " << ans << "\n";
    }
    return 0;
}