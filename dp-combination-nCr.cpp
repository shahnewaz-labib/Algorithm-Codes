#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

long long dp[101][101];

void lmao() {
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i = 2; i <= 100; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
}

int main() {
    lmao();
    int n, r;
    while(cin >> n >> r) {
        if(!n and !r) return 0;
        printf("%d things taken %d at a time is %lld exactly.\n", n, r, dp[n][r]);
    }
}
