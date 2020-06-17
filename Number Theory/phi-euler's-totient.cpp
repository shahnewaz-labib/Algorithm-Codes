

// UVa problem: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1120
// 


#include <iostream>

#define ll                      long long

using namespace std;

ll phi(ll n) {
    ll ans = n;
    if(n == 1) return 1;
    if(n%2 == 0) {
        ans -= ans/2;
        while(n%2 == 0)
            n /= 2;
    }
    for(int i = 3; i*i <= n; i += 2) {
        if(n%i == 0) {
            ans -= ans/i;
            while(n%i == 0)
                n /= i;
        }
    }
    if(n > 1)
        ans -= ans/n;
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ll n;
    while(scanf("%lld", &n)) {
        if(!n) return 0;
        printf("%lld\n", phi(n));
    }
}

// Even more faster I guess, but don't understand much of this :\
// blog: http://shoshikkha.com/archives/1472

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll po(ll a,ll b)
{
    ll ans=1;
    while(b--) ans*=a;
    return ans;
}
ll prime(ll a)
{
    for(int i=1; i*i<=a; i++)
    {
        if(a%i==0) return 1;
    }
    return 0;
}
 
void phi(long long int n)
{
    ll i,mul=1,holder,fre=0;
    if(prime(n)==0) mul=n-1;
    else
    {
        for(i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    holder=i;
                    fre++;
 
                }
                mul*=(po(holder,fre-1)*(holder-1));
                fre=0;
            }
        }
        if(n!=1) {
 
                mul*=(n-1);
        }
 
    }
    cout << mul << endl;
}
 
int main()
{
    long long int n;
    scanf("%lld",&n);
    phi(n);
    return 0;
}
