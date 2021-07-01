#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll ans = 0, n, m, k;
	cin >> n >> m >> k;
	vector<ll> arr(m, 0);
	for (ll i = 0; i < m; i++) {
		cin >> arr[i];
	}
	ll f;
	cin >> f;
	for (auto i : arr) {
		ans += __builtin_popcountll(f^i) <= k;
	}
	cout << ans;
}
