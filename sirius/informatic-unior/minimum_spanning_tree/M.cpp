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
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll col = n*m;
	DSU s(col);
	for (ll i = 0; i < col; i++) {
		ll x;
		cin >> x;
		if (x != 0) {
			if (x != 1) {
				if (i % m != m-1) {
					s.unite(i, i+1);
				}
			}
			if (x != 2) {
				if (i / m < n-1) {
					s.unite(i, i+m);
				}
			}
		}
	}
	ll ans = 0;
	vector<ll> p1, p2;
	for (ll i = 0; i < m*n-m; i++) {
		if (s.in_one(i, i+m)) {
			continue;
		}
		ans++;
		p2.push_back(i);
		s.unite(i, i+m);
	}
	for (ll i = 0; i < col; i++) {
		if (i % m == m-1) {
			continue;
		}
		if (s.in_one(i, i+1)) {
			continue;
		}
		ans += 2;
		p1.push_back(i);
		s.unite(i, i+1);
	}
	cout << p2.size()+p1.size() << ' ' << ans << '\n';
	for (auto i : p1) {
		cout << i/m+1 << ' ' << i%m+1 << ' ' << 2 << '\n';
	}
	for (auto i : p2) {
		cout << i/m+1 << ' ' << i%m+1 << ' ' << 1 << '\n';
	}
}
