#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& used, ll hn, vector<ll>& ans, vector<ll>& h) {
	used[v] = true;
	dp[v] = hn;
	h[v] = hn;
	bool f = true;
	ll cnt = 0;
	for (auto i : arr[v]) {
		if (i == p) continue;
		if (used[i]) {
			dp[v] = min(dp[v], h[i]);
		} else {
			dfs(i, v, arr, dp, used, hn+1, ans, h);
			if (dp[i] >= h[v]) {
				f = false;
			}
			cnt++;
			dp[v] = min(dp[v], dp[i]);
		}
	}
	if (p == -1) {
		if (cnt > 1) {
			ans.push_back(v);
		}
	} else {
		if (!f) {
			ans.push_back(v);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> dp(n, 0), h(n, 0);
	vector<bool> used(n, false);
	vector<ll> ans;
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, -1, arr, dp, used, 0, ans, h);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i+1 << ' ';
	}
}
