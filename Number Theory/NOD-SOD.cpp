#pragma comment(linker, "/stack:200000000")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
#define fastio                              ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define read                                freopen("input.txt", "r", stdin);
#define write                               freopen("output.txt", "w", stdout);
#define nl                                  '\n'
#define LCM(a, b)                           (a / __gcd(a, b) ) *b
#define GCD(a, b)                           __gcd(a, b)
#define mem(v, val)                         memset(v, val, sizeof(v))
#define TC                                  int t; scanf("%d", &t); for(int tc = 1; tc <= t; tc++)
#define inp(x)                              for(auto& iinput:x) cin >> iinput
#define out(x)                              for(auto& ooutput:x) cout << ooutput << ' '
#define sq(a)                               ((a) * (a))
 
#define ll                                  long long
#define vi                                  vector<int>
#define pb                                  push_back
#define vpii                                vector<pair<int, int>>
#define mp                                  make_pair
#define ff                                  first
#define ss                                  second
#define all(v)                              v.begin(), v.end()
#define rsort(v)                            sort(v.rbegin(), v.rend())
#define debug(x)                            cerr << #x << " = " << x << nl
 
using namespace std;
 
const double pi = 2*acos(0.0);
const int MAX = 2e6 + 5, MOD = 1e9 + 7  , MAXLG = log2(MAX) + 1;
const ll inf = 1e18 + 5;

vector<int> flag(1000010, true);
vector<int> primes;

void sieve() {
	flag[0] = false;
	flag[1] = false;
	for(int i = 2; i*i <= 1000010; i++)
		if(flag[i])
			for(int j = 2; i*j < 1000010; j++)
				flag[i*j] = false;

	primes.pb(2);
	for(int i = 3; i < 1000010; i += 2)
		if(flag[i])
			primes.pb(i);
	
}

int NOD(int n) {
	int total = 1;
	for(int i = 0; primes[i] * primes[i] <= n; i++)
		if(n%primes[i] == 0) {
			int count = 0;
			while(n%primes[i] == 0) {
				count++;
				n /= primes[i];
			}
			total = total * (count+1);
		}
	
	if(n != 1) total *= 2;

	return total;
}

int SOD(int n) {
	int sum = 1, p = 1, s;
	for(int i = 0; primes[i] * primes[i] <= n; i++) {
		if(n%primes[i] == 0) {
			p = 1;
			while(n%primes[i] == 0) {
				p = p * primes[i];
				n /= primes[i];
			}
			p = p * primes[i];
			s = (p - 1)/(primes[i] + 1);
			sum = sum * s;
		}
	}

	if(n != 1) {
		p = n*n;
		s = (p - 1)/(n + 1);
		sum = sum * s;
	}

	return sum;
}


pair <int , int > NODandSOD(int x) {
    int sq = sqrt(x) ;
    int div = 1 ;
    int sum = 1 ;
	l = primes.size();
    for(int i = 0 ; i < l && primes[i] <= sq ; i++) {
        if(x % prime[i] == 0) {
            int p = 0 ;
            int k = 1 ;
            int temp = 1 ;
            while(x % primes[i] == 0) {
                x /= primes[i] ;
                k *= primes[i] ;
                temp += k ;
                p++ ;
            }
            p++ ;
            div *= p ;
            sum *= temp ;
            sq = sqrt(x) ; 
        }
    }
    if(x != 1) {
        sum *= (x + 1) ;
        div *= 2 ;
    }
    return make_pair(div , sum);
}


int main() {

	sieve();

	// 	cout << NOD(13) << nl;
	cout << SOD(48) << nl;

}
