#pragma GCC optimization("unroll-loops")
#pragma GCC optimization("no-stack-protector")
#pragma GCC optimization("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,abm,popcnt")
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, minus1 = -1;
	cin >> n >> m;
	vector<ll> zap(n + 1, 0);
	vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(m + 1, false)));
	dp[0][0][0] = true;
	vector<vector<vector<pair<ll, ll>>>> pred(n + 1, vector<vector<pair<ll, ll>>>(m + 1, vector<pair<ll, ll>>(m + 1, {-1, -1})));
	for (ll i = 1; i <= n; i++) {
		ll k, a, b, c, d;
		cin >> k >> a >> b >> c >> d;
		zap[i] = k;
		for (ll f = 0; f <= m; f++) {
			for (ll s = 0; s <= m; s++) {
				if (f == k) {
					if ((k >= a) && (k <= b) && (s >= c) && (s <= d)) {
						for (ll j = 0; j <= m; j++) {
							if (dp[i-1][j][s]) {
								pred[i][f][s] = {j, s};
							}
							dp[i][f][s] = dp[i][f][s] || dp[i-1][j][s];
						}
					}
				}
				if (s == k) {
					if ((f >= a) && (f <= b) && (k >= c) && (k <= d)) {
						for (ll j = 0; j <= m; j++) {
							if (dp[i-1][f][j]) {
								pred[i][f][s] = {f, j};
							}
							dp[i][f][s] = dp[i][f][s] || dp[i-1][f][j];
						}
					}
				}
			}
		}
	}
	bool a = false;
	pair<ll, ll> start = {-1, -1};
	for (ll f = 0; f <= m; f++) {
		for (ll s = 0; s <= m; s++) {
			if (dp[n][f][s]) {
				start = {f, s};
			}
			a = a || dp[n][f][s];
		}
	}
	cout << (a ? "Yes\n" : "No");
	if (a) {
		vector<bool> ans;
		while (pred[n][start.first][start.second] != make_pair(minus1, minus1)) {
			if (zap[n] != start.second) {
				ans.push_back(false);
			} else {
				if (zap[n] != start.first) {
					ans.push_back(true);
				} else {
					if (pred[n][start.first][start.second].first != start.first) {
						ans.push_back(false);
					} else {
						if (pred[n][start.first][start.second].second != start.second) {
							ans.push_back(true);
						} else {
							ans.push_back(false);
						}
					}
				}
			}
			start = pred[n][start.first][start.second];
			n--;
		}
		reverse(ans.begin(), ans.end());
		for (auto i : ans) {
			cout << i << ' ';
		}
	}
}
