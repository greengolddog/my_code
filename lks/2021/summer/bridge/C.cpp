#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& used, ll hn, vector<pair<ll, ll>>& ans, vector<ll>& h) {
	used[v] = true;
	dp[v] = hn;
	h[v] = hn;
	for (auto i : arr[v]) {
		if (i == p) continue;
		if (used[i]) {
			dp[v] = min(dp[v], h[i]);
			ans.push_back({v, i});
		} else {
			dfs(i, v, arr, dp, used, hn + 1, ans, h);
			if (dp[i] <= h[v]) {
				ans.push_back({v, i});
			}
			dp[v] = min(dp[v], dp[i]);
		}
	}
}

void col(ll v, vector<vector<ll>>& arr, vector<ll>& color, ll now) {
	color[v] = now;
	for (auto i : arr[v]) {
		if (color[i] == -1) {
			col(i, arr, color, now);
		}
	}
}

int main() {
	freopen("bicone.in", "r", stdin);
	freopen("bicone.out", "w", stdout);
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
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, -1, arr, dp, used, 0, ans, h);
		}
	}
	arr.clear();
	arr.resize(n);
	for (auto[a, b] : ans) {
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> color(n, -1);
	ll last = 1;
	for (ll i = 0; i < n; i++) {
		if (color[i] == -1) {
			col(i, arr, color, last);
			last++;
		}
	}
	cout << last - 1 << '\n';
	for (auto i : color) {
		cout << i << ' ';
	}
}
