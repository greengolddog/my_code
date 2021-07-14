#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 10000000000000000;

struct LCA {
	vector<vector<pair<ll, ll>>> arr;
	vector<vector<ll>> binup, cost;
	vector<ll> high;
	ll n, m, max_pow = 30;
	LCA(vector<vector<pair<ll, ll>>> arr): arr(arr) {
		n = arr.size();
		m = 0;
		for (ll i = 0; i < n; i++) {
			m += arr[i].size();
		}
		vector<bool> used(n, false);
		binup.resize(n, vector<ll>(max_pow, 0));
		cost.resize(n, vector<ll>(max_pow, 0));
		high.resize(n, -1);
		build(0, 0, used, 2);
	}
	void build(ll v, ll p, vector<bool>& used, ll c) {
		high[v] = high[p]+1;
		binup[v][0] = p;
		cost[v][0] = c;
		for (ll i = 1; i < max_pow; i++) {
			binup[v][i] = binup[binup[v][i-1]][i-1];
			if (cost[v][i-1] == cost[binup[v][i-1]][i-1] || cost[binup[v][i-1]][i-1] == 2) {
				cost[v][i] = cost[v][i-1];
			} else {
				cost[v][i] = -1;
			}
		}
		used[v] = true;
		for (auto[u, nc] : arr[v]) {
			if (!used[u]) {
				build(u, v, used, nc);
			}
		}
	}
	bool get_lca(ll v, ll u) {
		for (ll i = max_pow-1; i >= 0; i--) {
			if (high[binup[v][i]] >= high[u]) {
				if (cost[v][i] != 1 && cost[v][i] != 2) {
					return false;
				}
				v = binup[v][i];
			}
		}
		for (ll i = max_pow-1; i >= 0; i--) {
			if (high[binup[u][i]] >= high[v]) {
				if (cost[u][i] != 0 && cost[u][i] != 2) {
					return false;
				}
				u = binup[u][i];
			}
		}
		if (u == v) {
			return true;
		}
		for (ll i = max_pow-1; i >= 0; i--) {
			if (binup[v][i] != binup[u][i]) {
				if (cost[v][i] != 1 && cost[v][0] != 2) {
					return false;
				}
				if (cost[u][i] != 0 && cost[u][0] != 2) {
					return false;
				}
				v = binup[v][i];
				u = binup[u][i];
			}
		}
		if (cost[v][0] != 1 && cost[v][0] != 2) {
			return false;
		}
		if (cost[u][0] != 0 && cost[u][0] != 2) {
			return false;
		}
		return true;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back({b, 0});
		arr[b].push_back({a, 1});
	}
	LCA l(arr);
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << (l.get_lca(a, b) ? "Yes" : "No") << '\n';
	}
}
