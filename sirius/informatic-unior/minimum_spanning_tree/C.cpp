#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> pred, rang;
	ll size;
	DSU(ll n) {
		pred.resize(n, 0);
		rang.resize(n, 1);
		for (ll i = 0; i < n; i++) {
			pred[i] = i;
		}
		size = n;
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
	}
	bool in_one(ll a, ll b) {
		return get(a) == get(b);
	}
	void clear(ll n) {
		pred.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			pred[i] = i;
		}
		rang.clear();
		rang.resize(n, 1);
		size = n;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	DSU d(0);
	while (cin >> s) {
		if (s == "RESET") {
			ll n;
			cin >> n;
			d.clear(n);
			cout << "RESET DONE\n";
		} else {
			ll i, j;
			cin >> i >> j;
			if (s == "CHECK") {
				cout << (d.in_one(i, j) ? "YES\n" : "NO\n");
			} else {
				if (d.in_one(i, j)) {
					cout << "ALREADY " << i << ' ' << j << '\n';
				} else {
					d.unite(i, j);
				}
			}
		}
	}
}
