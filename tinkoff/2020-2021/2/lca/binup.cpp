#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

ll t = 0;
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
	return ((tin[v] < tin[u]) && (tout[v] > tout[u]));
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
