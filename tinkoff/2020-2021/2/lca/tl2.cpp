#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

ll t = 0, root = 0;
const ll MAXLG = 25;
vector<vector<ll>> tree;
vector<ll> used;
vector<vector<ll>> binup;
vector<ll> tin;
vector<ll> tout;

void dfs(ll v, ll p) {
	binup[v][0] = p;
	for (ll i = 1; i < MAXLG; i++) {
		binup[v][i] = binup[binup[v][i-1]][i-1];
	}
	used[v] = 1;
	tin[v] = t;
	t++;
	for (ll i = 0; i < tree[v].size(); i++) {
		if (!used[tree[v][i]]) {
			dfs(tree[v][i], v);
		}
	}
	tout[v] = t;
	t++;
}

bool is_p(ll v, ll u) {
	return ((tin[v] <= tin[u]) && (tout[v] >= tout[u]));
}

ll lca(ll v, ll u) {
	if (is_p(v, u)) return v;
	if (is_p(u, v)) return u;
	for (ll i = (MAXLG - 1); i >= 0; i--) {
		ll to_v = binup[v][i];
		if (!is_p(to_v, u)) v = to_v;
	}
	return binup[v][0];
}

ll lower(ll v, ll u) {
	return (is_p(v, u) ? u : v);
}

ll get_lca(ll v, ll u) {
	ll l = lca(v, u), lv = lca(root, v), lu = lca(root, u);
	return lower(lower(lv, lu), l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n;
	while (n != 0) {
		root = 0;
		tree.resize(n, vector<ll>(0, 0));
		used.resize(n, 0);
		binup.resize(n, vector<ll>(MAXLG, 0));
		tin.resize(n, 0);
		tout.resize(n, 0);
		for (ll i = 1; i < n; i++) {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		dfs(0, 0);
		cin >> m;
		for (ll i = 0; i < m; i++) {
			char com;
			cin >> com;
			if (com == '?') {
				ll u, v;
				cin >> u >> v;
				cout << get_lca(u - 1, v - 1) + 1 << endl;
			} else {
				ll u;
				cin >> u;
				root = u - 1;
			}
		}
		cin >> n;
	}
}
