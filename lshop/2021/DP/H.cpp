#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<pair<ll, ll>>>& arr, vector<ll>& col, vector<ll>& color, ll now, vector<ll>& len) {
	color[v] = now;
	for (auto[u, _] : arr[v]) {
		if (u != p) {
			dfs(u, v, arr, col, color, now, len);
			col[v] += col[u];
			len[v] += len[u]+col[u];
		}
	}
}

void dfs2(ll v, ll p, vector<vector<pair<ll, ll>>>& arr, vector<ll>& col, vector<ll>& color, ll now, vector<ll>& len, vector<ll>& ans) {
	ans[v] = now;
	for (auto[u, i] : arr[v]) {
		if (u != p) {
			dfs2(u, v, arr, col, color, now-col[u]*2+col[color[u]], len, ans);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	vector<pair<ll, ll>> all;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back({b, i});
		arr[b].push_back({a, i});
		all.push_back({a, b});
	}
	vector<ll> col(n, 1), len(n, 0);
	vector<ll> color(n, -1), ans(n, 0);
	for (ll i = 0; i < n; i++) {
		if (color[i] == -1) {
			dfs(i, -1, arr, col, color, i, len);
			dfs2(i, -1, arr, col, color, len[i], len, ans);
		}
	}
	ll ans1 = 0, ans2 = 0;
	for (auto i : ans) {
		ans2 += i;
	}
	for (ll i = 0; i < n; i++) {
		ans1 += col[color[i]]-1;
	}
	cout << ans1/2 << '\n' << ans2/2;
}
