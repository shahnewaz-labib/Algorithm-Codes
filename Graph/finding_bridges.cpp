/*
Name: Finding bridges on a graph
Time Complexity:
    * O(V+E), V is number of vertices, E is number of edges
Space Complexity:
    * ???
*/

/* Resources:
    1. https://cp-algorithms.com/graph/bridge-searching.html
    2. http://www.shafaetsplanet.com/?p=2504
    3. CodeNCode:
        * https://www.youtube.com/watch?v=S7fIqu1LgJw
        * https://www.youtube.com/watch?v=ECKTyseo2H8
*/

/* Problems:
    * Bertown Roads: https://codeforces.com/problemset/problem/118/E

*/


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
            // It's a back edge
            // so, updating the low time of node
            lowtime[node] = min(lowtime[node], intime[child]);
        } else {
            dfs(child, node);
            lowtime[node] = min(lowtime[child], lowtime[node]);
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