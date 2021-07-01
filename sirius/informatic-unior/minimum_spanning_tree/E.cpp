#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> pred, rang;
	ll size, col;
	DSU(ll n) {
		pred.resize(n, 0);
		rang.resize(n, 1);
		for (ll i = 0; i < n; i++) {
			pred[i] = i;
		}
		size = n;
		col = n;
	}
	ll get(ll v) {
		if (pred[v] == v) {
			return v;
		}
		return pred[v] = get(pred[v]);
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rang[a] < rang[b]) {
			swap(a, b);
		}
		pred[b] = a;
		rang[a] += rang[b];
		col--;
	}
	bool in_one(ll a, ll b) {
		return get(a) == get(b);
	}
	bool is_one() {
		return col == 1;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	DSU d(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		d.unite(a, b);
		if (d.is_one()) {
			cout << i+1;
			return 0;
		}
	}
}
