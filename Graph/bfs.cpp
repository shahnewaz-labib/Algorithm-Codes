/*
Name: Breadth First Search
Time Complexity:
    * O(V+E), V is bumber of vertices, E is number of edges
Space Complexity:
    * O(W), W is the maximum width of the tree
*/

/* Pseudocode:
procedure BFS(G,source):
    Q=queue(), level[]=infinity
    Q.enqueue(source)
    level[source]=0
    while Q is not empty
       u ← Q.pop()
       for all edges from u to v in G.adjacentEdges(v) do
           if level[v] = infinity:
                    level[v] = level[u] + 1;
                    Q.enqueue(v)
           end if
       end for
      end while
    Return distance; // for minimum distance
*/

/* Resources:
    1. https://cp-algorithms.com/graph/breadth-first-search.html
        - Shortest path
        - Path printing
    2. http://www.shafaetsplanet.com/?p=973
*/


#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6;  // Maximum possible number of nodes
vector<int> adj[N]; // Adjacency list using vector array
vector<bool> visited;   // To keep track of the visited nodes



void bfs(int v) {
    queue<int> q;
    visited[v] = true;
    // do something here
    while(!q.empty()) {
        int node = q.front();   // The next node to be visited
        q.pop();
        for(int child : adj[node]) {    // Traverse every child of node
            if(!visited[child]) {
                q.push(child);  // If child is not visited
                                // make a bfs call i.e push it into the queue
                // Do something here
            }
        }
    }
    return;
}

int main() {
    int node;   // Number of nodes
    int edge;   // Number of edges
    cin >> node >> edge;
    
    int a, b;
    // Taking input of all the edges
    for(int i = 0; i < edge; i++) {
        cin >> a >> b;  // There is an edge between a and b
        // If the graph is directed, we add b as a child of a, a.push_back(b)
        // If the graph isn't directed, we add 'b' as a child of 'a' as well as 'a' as a child of 'b', a.push_back(b) and b.push_back(a)
        a.push_back(b);
        b.push_back(a);
    }

    int v; // We will make bfs call from note v

    bfs(v);

    return 0;


}