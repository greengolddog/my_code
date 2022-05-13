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
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll mod = 1'000'000'007;
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
	vector<vector<ll>> old_arr = arr;
	arr.clear();
	arr.resize(n);
	for (auto[a, b] : ans) {
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> color(n, -1);
	ll last = 0;
	for (ll i = 0; i < n; i++) {
		if (color[i] == -1) {
			col(i, arr, color, last);
			last++;
		}
	}
	vector<ll> cnt(last, 0);
	for (auto i : color) {
		cnt[i]++;
	}
	vector<vector<ll>> arr2(last);
	ll k = 0, c = 1;
	set<pair<ll, ll>> s;
	for (ll i = 0; i < n; i++) {
		for (auto j : old_arr[i]) {
			if (color[i] != color[j]) {
				s.insert({color[i], color[j]});
			}
		}
	}
	for (auto[a, b] : s) {
		arr2[a].push_back(b);
	}
	for (ll i = 0; i < last; i++) {
		if (arr2[i].size() < 2) {
			k++;
			c *= cnt[i];
			c = c % mod;
		}
	}
	cout << k << ' ' << c;
}
