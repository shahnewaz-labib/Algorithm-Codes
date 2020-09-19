#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Iterative method
long long dp[101][101];

void nCr() {
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i = 2; i <= 100; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
}


// Recursive method
long long arr[101][101];

int GETnCr(int n, int r) {
    if(arr[n][r] != 0) return arr[n][r];
    long long result;
    if(n == r) result = 1;
    else if(r == 1) result = n;
    else if(r == 0) result = 1;
    else result = GETnCr(n-1, r) + GETnCr(n-1, r-1);

    arr[n][r] = result;

    return arr[n][r];

}

int main() {
    /* Approach 1
    nCr();
    int n, r;
    while(cin >> n >> r) {
        if(!n and !r) return 0;
        printf("%d things taken %d at a time is %lld exactly.\n", n, r, dp[n][r]);
    }
    */

    // Approach 2
    cout << GETnCr(50, 3) << endl;
}
