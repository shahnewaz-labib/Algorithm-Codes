/*
Segment tree
*/




#include <bits/stdc++.h>
#define MAX         11
#define nl          '\n'
using namespace std;

int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int tree[4*MAX];


// sum

void initSUM(int node, int b, int e) { // initializing for sum of range [i, j]
    if(b == e) {
        tree[node] = arr[b];
        return;
    }

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    initSUM(left, b, mid);
    initSUM(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int querySUM(int node, int b, int e, int i, int j) { // sum := [i, j] query
    if(e < i or b > j) return 0;
    else if(i <= b and e <= j) return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    int q1 = querySUM(left, b, mid, i, j);
    int q2 = querySUM(right, mid+1, e, i, j);

    return q1 + q2;
}




// min in range

void initMIN(int node, int b, int e) { // initializing for min of range [i, j]
    if(b == e) {
        tree[node] = arr[b];
        return;
    }

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    initMIN(left, b, mid);
    initMIN(right, mid+1, e);

    tree[node] = min(tree[left], tree[right]);
}

int queryMIN(int node, int b, int e, int i, int j) { // MIN := [i, j] query
    if(e < i or b > j) return INT_MAX;
    else if(i <= b and e <= j) return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    int q1 = queryMIN(left, b, mid, i, j);
    int q2 = queryMIN(right, mid+1, e, i, j);

    return min(q1, q2);
}





// max in range


void initMAX(int node, int b, int e) { // initializing for max of range [i, j]
    if(b == e) {
        tree[node] = arr[b];
        return;
    }

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    initMAX(left, b, mid);
    initMAX(right, mid+1, e);

    tree[node] = max(tree[left], tree[right]);
}

int queryMAX(int node, int b, int e, int i, int j) { // MAX := [i, j] query
    if(e < i or b > j) return (-1)*INT_MAX;
    else if(i <= b and e <= j) return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (b + e)/2;
    int q1 = queryMAX(left, b, mid, i, j);
    int q2 = queryMAX(right, mid+1, e, i, j);

    return max(q1, q2);
}


int main() {
    // initSUM(1, 1, MAX);
    // cout << querySUM(1, 1, MAX, 5, 7) << '\n';

    // initMIN(1, 1, MAX);
    // cout << queryMIN(1, 1, MAX, 4, 7) << '\n';

    initMAX(1, 1, MAX);
    cout << queryMAX(1, 1, MAX, 4, 7) << '\n';
    

}
