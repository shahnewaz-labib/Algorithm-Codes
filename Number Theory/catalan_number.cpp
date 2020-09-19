/*
Read about catalan numebrs:
1. https://brilliant.org/wiki/catalan-numbers/
2. https://www.geeksforgeeks.org/applications-of-catalan-numbers/
*/

#include <iostream>
using namespace std;

long long dp[101][101];

int nCr(int n, int r) {
    if(dp[n][r] != 0) return dp[n][r];
    long long result;
    if(n == r) result = 1;
    else if(r == 1) result = n;
    else if(r == 0) result = 1;
    else result = nCr(n-1, r) + nCr(n-1, r-1);

    dp[n][r] = result;

    return dp[n][r];

}


int main() {
    int n = 10; // n = 0,1,2,3,...
    cout << "nth catalan number is: " << nCr(2*n, n)/(n+1) << endl;

}