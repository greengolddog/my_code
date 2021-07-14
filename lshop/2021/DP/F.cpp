#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& col, vector<ll>& color, ll now) {
	color[v] = now;
	for (auto u : arr[v]) {
		if (u != p) {
			dfs(u, v, arr, col, color, now);
			col[v] += col[u];
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
	vector<pair<ll, ll>> all;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
		all.push_back({a, b});
	}
	vector<ll> col(n, 1);
	vector<ll> color(n, -1);
	for (ll i = 0; i < n; i++) {
		if (color[i] == -1) {
			dfs(i, -1, arr, col, color, i);
		}
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll j;
		cin >> j;
		j--;
		auto[a, b] = all[j];
		if (col[a] < col[b]) {
			swap(a, b);
		}
		cout << (col[color[a]]-col[b])*col[b] << ' ';
	}
}
