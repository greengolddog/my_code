#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<vector<ll>>& dp) {
	dp[1][v] = 1;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, dp);
			dp[1][v] += dp[0][i];
			dp[0][v] += max(dp[0][i], dp[1][i]);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	ll root = -1;
	for (ll i = 0; i < n; i++) {
		ll p;
		cin >> p;
		p--;
		if (p == -1) {
			root = i;
			continue;
		}
		arr[p].push_back(i);
		arr[i].push_back(p);
	}
	vector<vector<ll>> dp(2, vector<ll>(n, 0));
	dfs(root, -1, arr, dp);
	cout << max(dp[0][root], dp[1][root]);
}
