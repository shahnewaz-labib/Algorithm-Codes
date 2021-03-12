#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
vector<int> adj[N];
bool visited[N];
int intime[N], lowtime[N];
int timer = 0;

void dfs(int node, int parent) {
    visited[node] = true;
    intime[node] = lowtime[node] = timer;
    timer++;
    for(int child : adj[node]) {
        if(child == parent) continue;
        if(visited[child]) {
            lowtime[child] = min(lowtime[child], lowtime[node]);
        } else {
            dfs(child, node);
            lowtime[child] = min(lowtime[child], lowtime[node]);
            if(lowtime[child] > intime[node]) {
                // There is no other way to 'child' except 'node'
                // So this edge is a bridge
                printf("Edge %d to %d is a bridge\n", node, child);
            }
        }
    }
}

int main() {
    int nodes, edges, a, b;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
}