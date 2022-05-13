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
vector<ll> tin;
vector<ll> tout;

void dfs(ll v) {
	used[v] = 1;
	tin[v] = t;
	t++;
	for (ll i = 0; i < tree[v].size(); i++) {
		if (!used[tree[v][i]]) {
			dfs(tree[v][i]);
		}
	}
	tout[v] = t;
	t++;
}

bool is_p(ll v, ll u) {
	return ((tin[v] < tin[u]) && (tout[v] > tout[u]));
}

int main() {
	freopen("ancestor.in", "r", stdin);
	freopen("ancestor.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, c = 0;
	cin >> n;
	tree.resize(n);
	used.resize(n, 0);
	tin.resize(n, 0);
	tout.resize(n, 0);
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (a == 0) {
			c = i;
		} else {
			a--;
			tree[i].push_back(a);
			tree[a].push_back(i);
		}
	}
	dfs(c);
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		cout << is_p(u - 1, v - 1) << endl;
	
