/*
Name: Depth First Search
Time Complexity:
    * O(V+E), V is bumber of vertices, E is number of edges
Space Complexity:
    * O(H), H is the maximum height of the tree
*/


/* Resources:
    1. https://cp-algorithms.com/graph/depth-first-search.html
    2. http://www.shafaetsplanet.com/?p=973
*/



#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6;  // Maximum possible number of nodes
vector<int> adj[N]; // Adjacency list using vector array
vector<bool> visited;   // To keep track of the visited nodes

void dfs(int node) {
    visited[node] true; // Mark the node as visited
    for(int child : adj[node]) {    // Access every child of node
        if(!visited[child]) {
            dfs(child); // If the child isn't visited yet,
                        // make a dfs call to that child
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

    int v; // We will start dfs from node v
    
    dfs(v);

    return 0;


}