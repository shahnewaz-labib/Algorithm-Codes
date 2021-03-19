#include <bits/stdc++.h>
#define lesgoo		ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll			long long
#define pii 		pair<int, int>
#define MIN(x,y)	(x) < (y) ? x : y
#define MAX(x,y)	(x) > (y) ? x : y
#define TC			int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define Unique(a)   sort(all(a)),a.erase(unique(all(a)),a.end
#define yeet        return 0;
#define nl          "\n"
#define de(x)       cout << #x << " = " << x << "\n";
#define HERE        cout << "HERE\n";
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
using namespace std;

struct node {
    ll V,W;
    bool operator < (const node &a ) const{
        return a.W < W;
    }
};

const int mx = 1e5+10;
const ll inf = 1e17;
vector<node> adj[mx];
ll d[mx];
bool vis[mx];

void dijkstra(int src) {
    for(int i = 0; i < mx; i++) d[i] = inf;
    priority_queue<node> pq;
    pq.push({src, 0});
    d[src] = 0;
    while(!pq.empty()) {
        ll u = pq.top().V;
        ll w = pq.top().W;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(node child : adj[u]) {
            if(vis[child.V]) continue;
            ll newDist = w + child.W;
            ll oldDist = d[child.V];
            if(newDist < oldDist) {
                d[child.V] = newDist;
                pq.push({child.V, newDist});
            }
        }
    }
}


int main() {
    int n, m, a, b, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";





    yeet
}

