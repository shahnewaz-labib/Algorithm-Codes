/*
    Problem Link: https://cses.fi/problemset/task/1643
    Classic Maximum Subarray Sum problem
*/

/*
    Kadane's Algorithm
    Resource: https://cp-algorithms.com/others/maximum_average_segment.html
*/

#include "bits/stdc++.h"
#define ll long long
#define MAX(a, b) (a) > (b) ? (a) : (b)
using namespace std;

ll solve(vector<int> &v) {
    ll ans = -1e18, sum = 0;

    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
        ans = MAX(ans, sum);
        sum = MAX(sum, 0);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    cout << solve(v) << '\n';
}
