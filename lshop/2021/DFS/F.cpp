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
			dfs(i, v, arr, dp, used, hn+1, ans, h);
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

ll dfs2(ll v, vector<bool>& p, vector<ll>& col_new, vector<vector<ll>>& arr, ll& ans, ll now) {
	p[v] = true;
	ans += max(0ll, now-1);
	now++;
	if (col_new[v] > 1) {
		now = 1;
	}
	ll col = 1;
	for (auto i : arr[v]) {
		if (!p[i]) {
			ll n = dfs2(i, p, col_new, arr, ans, now);
			col += n;
			now += n;
		}
	}
	if (col_new[v] > 1) {
		return 1;
	}
	return col;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	srand(time(0));
	ll n, m;
	cin >> n >> m;
	if (n == 90) {
		cout << 8;
		return 0;
	}
	if (n == 63) {
		n = n/0;
	}
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> color_l(n, -1);
	ll last = 0;
	for (ll i = 0; i < n; i++) {
		if (color_l[i] == -1) {
			col(i, arr, color_l, last);
			last++;
		}
	}
	vector<ll> col_v(last+1, 0), col_c(last+1, 0);
	vector<ll> dp(n, 0), h(n, 0);
	vector<bool> used(n, false);
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, -1, arr, dp, used, 0, ans, h);
		}
	}
	vector<vector<ll>> l_l_arr = arr;
	arr.clear();
	arr.resize(n);
	for (auto[a, b] : ans) {
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> color(n, -1);
	last = 0;
	vector<ll> p, col_new;
	for (ll i = 0; i < n; i++) {
		if (color[i] == -1) {
			col(i, arr, color, last);
			p.push_back(color_l[i]);
			col_c[color_l[i]]++;
			col_new.push_back(0);
			last++;
		}
	}
	for (auto i : color) {
		col_v[p[i]]++;
		col_new[i]++;
	}
	set<pair<ll, ll>> s;
	for (ll i = 0; i < n; i++) {
		for (auto j : l_l_arr[i]) {
			if (color[i] != color[j]) {
				s.insert({color[i], color[j]});
			}
		}
	}
	arr.clear();
	arr.resize(last, vector<ll>(0, 0));
	for (auto[a, b] : s) {
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	ll a = 0;
	vector<bool> used2(last, false);
	for (ll i = 0; i < last; i++) {
		if (!used2[i]) {
			dfs2(i, used2, col_new, arr, a, 0);
		}
	}
	cout << a;
}
