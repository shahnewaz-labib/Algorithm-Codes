/* Blog: https://cp-algorithms.com/string/rabin-karp.html
 * Problem: https://www.spoj.com/status/ns=27487371
 *
 * */




#include <bits/stdc++.h>
#define lesgoo		ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll			long long
#define pii 		pair<int, int>
#define MIN(x,y)	(x) < (y) ? x : y
#define MAX(x,y)	(x) > (y) ? x : y
#define TC			int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define Unique(a)   sort(all(a)),a.erase(unique(all(a)),a.end
#define yeet        return 0;
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
using namespace std;
const int p = 31;
const int m = 1e9+9;

vector<int> rabin(string s, string t) {
	int S = s.size(), T = t.size();
	
	vector<ll> p_pow(max(S, T), 0);
	p_pow[0] = 1;

	for(int i = 1; i < (int) p_pow.size(); i++) {
		p_pow[i] = p_pow[i-1] * p % m;
	}

	vector<ll> h(T+1, 0);
	
	for(int i = 0; i < T; i++) {
		h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
	}

	ll h_s = 0;

	for(int i = 0; i < S; i++) {
		h_s = (h_s + (s[i]-'a'+1) * p_pow[i] ) % m;
	}

	vector<int> occ;
	for(int i = 0; i+S-1 < T; i++) {
		ll curr = (h[i+S] - h[i] + m) % m;
		if(curr == h_s * p_pow[i] % m) {
			occ.push_back(i);
		}
	}


	return occ;
}

int main() {

	TC {
		string s, t; cin >> t >> s;
		vector<int> occ = rabin(s, t);
		if(!occ.empty()) {
			cout << occ.size() << "\n";
			for(int x : occ) cout << x+1 << " ";
			cout << "\n";
		} else cout << "Not Found\n";
		cout << "\n";
	}

    return 0;
}


