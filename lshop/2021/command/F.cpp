#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& m) {
	dp[v] = arr[v].size()-(p == -1 ? 0 : 1);
	ll ma = 0;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, dp, m);
			dp[v] = max(dp[v], dp[i]);
			ma = max(ma, dp[i]);
			m[v] = m[i] && m[v];
		}
	}
	if (arr[v].size()-(p == -1 ? 0 : 1) > 2) {
		if (ma > 1) {
			m[v] = false;
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < n-1; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> dp(n, 0);
	vector<bool> m(n, true);
	dfs(0, -1, arr, dp, m);
	cout << (m[0] ? "YES" : "NO");
}
