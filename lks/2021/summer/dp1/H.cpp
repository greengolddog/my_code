#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<bool>> arr(n, vector<bool>(n));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			char c;
			cin >> c;
			arr[i][j] = c == 'Y';
		}
	}
	vector<ll> dp(1 << n, 0);
	ll ans = 0;
	for (ll i = 0; i < (1 << n); i++) {
		for (ll f = 0; f < n; f++) {
			for (ll s = 0; s < n; s++) {
				if (arr[f][s]) {
					if (!(i >> f & 1) && !(i >> s & 1)) {
					dp[i | (1 << f) | (1 << s)] = max(dp[i | (1 << f) | (1 << s)], dp[i] + 1);
					}
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans * 2;
}
