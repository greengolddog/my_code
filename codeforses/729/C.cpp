#include <bits/stdc++.h>
typedef __int128 ll;

using namespace std;

ll gcd(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return gcd(max(a, b)%min(a, b), min(a, b));
}

ll noc(ll a, ll b) {
	return a*b/gcd(a, b);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	int t;
	cin >> t;
	ll mod = 1000000007;
	for (ll _ = 0; _ < t; _++) {
		long long nc;
		cin >> nc;
		ll n = nc, fact = 1;
		ll ans = n;
		for (ll i = 2; i < 50; i++) {
			fact = noc(fact, i)*i;
			ans = (ans+n/fact)%mod;
		}
		cout << (long long)ans << '\n';
	}
}
