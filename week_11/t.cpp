#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
 
const int N = 55;
const int M = 550;
const int INF = 100000000;
int n, m, g[N][N],flow[N][N];
int p[N], a[N], x[M], y[M], f;
int maxflow() {
    queue <int> q;
    memset( flow, 0, sizeof(flow));
    f = 0;
    while ( 1 ) {
        memset( a, 0, sizeof(a) );
        a[1] = INF;
        q.push(1);
        while ( !q.empty() ) {
            int u = q.front(); q.pop();
            for ( int v = 1; v <= n; ++v ) if ( !a[v] && flow[u][v] < g[u][v] ) {
                p[v] = u;
                a[v] = min( a[u], g[u][v] - flow[u][v] );
                q.push(v);
            }
        }
        if ( a[2] == 0 ) break;
        for ( int u = 2; u != 1; u = p[u] ) {
            flow[p[u]][u] += a[2];
            flow[u][p[u]] -= a[2];
        }
        f += a[2];
    }
    return f;
}
int main()
{
    while ( scanf("%d%d", &n, &m) != EOF && !( !m && !n ) ) {
        memset( g, 0, sizeof(g) );
        for ( int i = 0; i < m; ++i ) {
            int s, e, c;
            scanf("%d%d%d", &s, &e, &c);
            x[i] = s, y[i] = e;
            g[s][e] = g[e][s] = c;
        }
        maxflow();
        for ( int i = 0; i < m; ++i ) {
            if( ( !a[x[i]] && a[y[i]] ) || ( a[x[i]] && !a[y[i]] ) ) printf("%d %d\n", x[i], y[i]);
        }
        printf("\n");
    }
}
 