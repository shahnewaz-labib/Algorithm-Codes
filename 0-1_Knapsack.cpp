/*
Resource: http://www.shafaetsplanet.com/?p=3638
*/


#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dp[2010][2010];
vector<int> value, weight; // weight = {0, ...};
                           // value = {0, ...};

int ks(int n, int capacity) {
    if(dp[n][capacity] != -1) return dp[n][capacity];
    int result;
    if(!capacity or !n) result = 0;
    else if(weight[n] > capacity) result = ks(n-1, capacity);
    else {
        int profit1 = value[n] + ks(n-1, capacity-weight[n]);
        int profit2 = ks(n-1, capacity);
        result = max(profit1, profit2);
    }

    dp[n][capacity] = result;
    return dp[n][capacity];
}

int main() {
    // classic knapsack

    memset(dp, -1, sizeof(dp));
    value.push_back(0);
    weight.push_back(0);
    int capacity, n, a, b;
    cin >> capacity >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        weight.push_back(a);
        value.push_back(b);
    }

    cout << ks(n, capacity) << endl;
    return 0;
}
