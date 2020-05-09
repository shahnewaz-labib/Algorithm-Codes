
// segment tree :D
// http://lightoj.com/volume_showproblem.php?problem=1082
// 1082 - Array Queries

#pragma comment(linker, "/stack:200000000")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define N   100000
#define fastio                              ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int tree[4*N];
int arr[4*N];

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
    fastio;
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n, q, l, r;
        cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        init(1, 1, n);
        printf("Case %d:\n", tc);
        while(q--) {
            cin >> l >> r;
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    

}
//
