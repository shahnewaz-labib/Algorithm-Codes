#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, w, n, m, q;
ll adj[501][501];
ll inf = 1e15;
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> q;
    for(ll i = 0; i < 501; i++)
        for(ll j = 0; j < 501; j++) {
            adj[i][j] = inf;
        }
    for(ll i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[b][a], w);
    }
 
    for(ll i = 1; i <= n; i++) adj[i][i] = 0;
    for(ll k = 1; k <= n; k++) {
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
 
    while(q--) {
        cin >> a >> b;
        if(adj[a][b] == inf) adj[a][b] = -1;
        cout << adj[a][b] << "\n";
    }
    
 
}
