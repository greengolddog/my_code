#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<pair<ll, ll>>& dp, ll& ans) {
	dp[v] = {0, 0};
	pair<ll, ll> now = {0, 0};
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, dp, ans);
			dp[v].second = max(dp[v].second, dp[i].second+1);
			if (now.first < dp[i].second+1) {
				now.second = now.first;
				now.first = dp[i].second+1;
			} else {
				if (now.second < dp[i].second+1) {
					now.second = dp[i].second+1;
				}
			}
		}
	}
	dp[v].first = now.first+now.second;
	ans = max(ans, dp[v].first);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, ans = 0;
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
	vector<pair<ll, ll>> dp(n, {-1, -1});
	dfs(0, -1, arr, dp, ans);
	cout << ans;
}
