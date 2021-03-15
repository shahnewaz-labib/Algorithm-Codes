/*
Name: Finding articulation points on a graph (Tarjan's algorithm)
Time Complexity:
    * O(V+E), V is number of vertices, E is number of edges
Space Complexity:
    * ???
*/

/* Resources:
    1. https://cp-algorithms.com/graph/cutpoints.html
    2. http://www.shafaetsplanet.com/?p=2504
    3. CodeNCode:
        * https://www.youtube.com/watch?v=iGGolqb6gDE
    4. Tushar Roy:
        * https://www.youtube.com/watch?v=2kREIkF9UAs
*/



#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
vector<int> adj[N];
int timer, low[N], vis[N], in[N];


void findAP(int node, int parent) {
    vis[node] = 1;
    low[node] = in[node] = timer++;
    int children = 0;
    for(int child : adj[node]) {
        if(child == parent) continue;
        if(vis[child]) {
            low[node] = min(low[node], in[child]);
        } else {
            findAP(child, node);
            low[node] = min(low[node], low[child]);
            if(low[child] >= in[node] and parent != -1) {
                printf("%d is a cut vertex\n", node);
            }
            children++;
        }
        if(parent == -1 and children > 1) {
            printf("%d is a cut vertex\n", node);
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
    findAP(1 , -1);


    return 0;
}
