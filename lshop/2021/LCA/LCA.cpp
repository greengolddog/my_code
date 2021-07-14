#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> p;
	DSU(ll n = 0) {
		p.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	ll get(ll a) {
		if (p[a] == a) {
			return a;
		}
		return p[a] = get(p[a]);
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		p[b] = a;
	}
	void add() {
		p.push_back(p.size());
	}
};

struct LCA {
	vector<vector<ll>> arr, binup;
	DSU d;
	vector<ll> high;
	ll n, m;
	LCA(vector<vector<ll>> arr = vector<vector<ll>>(1, vector<ll>(0, 0))): arr(arr) {
		n = arr.size();
		m = 0;
		for (ll i = 0; i < n; i++) {
			m += arr[i].size();
			d.add();
		}
		vector<bool> used(n, false);
		binup.resize(n, vector<ll>(25, 0));
		high.resize(n, -1);
		build(0, 0, used);
	}
	void build(ll v, ll p, vector<bool>& used) {
		high[v] = high[p]+1;
		binup[v][0] = p;
		for (ll i = 1; i < 25; i++) {
			binup[v][i] = binup[binup[v][i-1]][i-1];
		}
		used[v] = true;
		for (auto u : arr[v]) {
			if (!used[u]) {
				build(u, v, used);
			}
		}
	}
	ll get(ll v, ll u) {
		if (high[v] < high[u]) {
			swap(u, v);
		}
		for (ll i = 24; i >= 0; i--) {
			if (high[binup[v][i]] >= high[u]) {
				v = binup[v][i];
			}
		}
		if (u == v) {
			return d.get(u);
		}
		for (ll i = 24; i >= 0; i--) {
			if (binup[v][i] != binup[u][i]) {
				v = binup[v][i];
				u = binup[u][i];
			}
		}
		return d.get(binup[v][0]);
	}
	void add(ll p) {
		high.push_back(high[p]+1);
		binup.push_back(vector<ll>(25, p));
		for (ll i = 1; i < 25; i++) {
			binup.back()[i] = binup[binup.back()[i-1]][i-1];
		}
		d.add();
	}
	void del(ll v) {
		d.unite(binup[v][0], v);
	}
};


int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	LCA l;
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll v;
			cin >> v;
			v--;
			l.add(v);
		}
		if (c == '-') {
			ll v;
			cin >> v;
			v--;
			l.del(v);
		}
		if (c == '?') {
			ll u, v;
			cin >> u >> v;
			u--;
			v--;
			cout << l.get(u, v)+1 << '\n';
		}
	}
}
