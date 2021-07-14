#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct LCA {
	vector<vector<ll>> arr, binup;
	vector<ll> high;
	ll n, m;
	LCA(vector<vector<ll>> arr): arr(arr) {
		n = arr.size();
		m = 0;
		for (ll i = 0; i < n; i++) {
			m += arr[i].size();
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
	ll get_lca(ll v, ll u) {
		if (high[v] < high[u]) {
			swap(u, v);
		}
		for (ll i = 24; i >= 0; i--) {
			if (high[binup[v][i]] >= high[u]) {
				v = binup[v][i];
			}
		}
		if (u == v) {
			return u;
		}
		for (ll i = 24; i >= 0; i--) {
			if (binup[v][i] != binup[u][i]) {
				v = binup[v][i];
				u = binup[u][i];
			}
		}
		return binup[v][0];
	}
};


int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 1; i < n; i++) {
		ll p;
		cin >> p;
		p--;
		arr[i].push_back(p);
		arr[p].push_back(i);
	}
	LCA l(arr);
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << l.get_lca(a, b)+1 << '\n';
	}
}
