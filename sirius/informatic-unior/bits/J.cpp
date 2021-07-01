#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll power(ll n, ll p, ll mod) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		ll now = power(n, p/2, mod);
		return now*now%mod;
	} else {
		return power(n, p-1, mod)*n%mod;
	}
}

ll sub(ll a, ll b, ll mod) {
	if (a - b < 0) return a-b+mod;
	return a-b;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, mod = 1000000007;
	cin >> n;
	cout << sub(power(3, n, mod), power(2, n, mod), mod);
}
