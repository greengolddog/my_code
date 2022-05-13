#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp) {
	for (auto i : arr[v]) {
		if (i != p) {
			dp[v] += dfs(i, v, arr, dp);
		}
	}
	return dp[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 1; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		arr[x].push_back(i);
		arr[i].push_back(x);
	}
	vector<ll> dp(n, 1);
	dfs(0, 0, arr, dp);
	for (auto i : dp) {
		cout << i << ' ';
	}
}
