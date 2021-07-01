#include <bits/stdc++.h>
typedef unsigned long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll x;
	cin >> x;
	if (x == 0) {
		cout << 0;
		return 0;
	}
	ll col = 64-__builtin_clzll(x);
	ll ans = x;
	for (ll i = 0; i < 64; i++) {
		x = (x >> 1) + (x & 1) * (1 << (col-1));
		ans = max(ans, x);
	}
	cout << ans;
}
