#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		ll col;
		cin >> col;
		for (ll j = 0; j < col; j++) {
			ll now;
			cin >> now;
			arr[i] = arr[i] | (1 << (now - 1));
		}
	}
	ll ans = n+1;
	vector<ll> a;
	for (ll i = 0; i < (1 << n); i++) {
		ll now = 0, col = 0;
		vector<ll> na;
		for (ll j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				col++;
				now = now | arr[j];
				na.push_back(j);;
			}
		}
		if (now == ((1 << k) - 1)) {
			if (col < ans) {
				a = na;
			}
			ans = min(ans, col);
		}
	}
	cout << ans << '\n';
	for (auto i : a) {
		cout << i+1 << ' ';
	}
}
