#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = 100000000000000;
	for (ll i = 0; i < (1 << n); i++) {
		ll r = 0;
		for (ll j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				r += arr[j];
			} else {
				r -= arr[j];
			}
		}
		ans = min(ans, abs(r));
	}
	cout << ans;
}
