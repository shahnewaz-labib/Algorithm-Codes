// problem link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=310

#include <iostream>
#define ll long long
using namespace std;

// iterative
ll BigMod(ll x, ll y, ll m) {
    ll ans = 1, tmp = x;
    while(y) {
        if(y&1) {
            ans = ans * tmp;
            ans = ans % m;
        }
        y = y >> 1;
        tmp = tmp * tmp;
        tmp = tmp % m;
    }
    return ans;
}

// recursive
int mod(int a, int b, int c)
{
    if(b==0) return 1;
    
    if(b%2==0)
    {
        int x=mod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * mod(a,b-1,c))%c;
}


int main() {
    int B, P, M;
    while(scanf("%d %d %d", &B, &P, &M) == 3)
        printf("%lld\n", BigMod(B, P, M));
    return 0;
}
