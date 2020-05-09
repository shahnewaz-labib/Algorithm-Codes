#include <bits/stdc++.h>
using namespace std;
int  n = 10;

int tree[40];
int arr[11] = {0, 3, 6, 1, 7, 3, 8, 3, 4, 6, 10};

void init(int node, int b, int e) {
    if(b == e) {
        tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = min(tree[left], tree[right]);

}

int query(int node, int b, int e, int i, int j) {
    if(e < i or b > j) return INT_MAX;
    if(b >= i and e <= j) return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid+1, e, i, j);

    return min(q1, q2);
}

int main() {

    init(1, 1, n);

    cout << query(1, 1, n, 1, 2);

}
//
