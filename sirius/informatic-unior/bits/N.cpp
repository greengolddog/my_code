#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, col;
	const ll MAXN = 10000000000000000;
	cin >> n >> m >> col;
	vector<ll> cost(n, 0);
	vector<vector<ll>> arr(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (ll i = 0; i < col; i++) {
		ll x, y, c;
		cin >> x >> y >> c;
		arr[x-1][y-1] += c;
	}
	vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));
	ll maxx = 0;
	for (ll i = 0; i < n; i++) {
		dp[0][i] = cost[i];
	}
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < n; j++) {
			if (((i >> j) & 1) == 0) {
				if (__builtin_popcountll(i)+1 == m) {
					maxx = max(maxx, dp[i][j]);
				}
				for (ll k = 0; k < n; k++) {
					if (((i >> k) & 1) == 0 && k != j) {
						if (dp[i][j] + arr[j][k] + cost[k] > dp[i | (1 << j)][k]) {
							dp[i | (1 << j)][k] = dp[i][j] + arr[j][k] + cost[k];
						}
					}
				}
			}
		}
	}
	cout << maxx;
}
