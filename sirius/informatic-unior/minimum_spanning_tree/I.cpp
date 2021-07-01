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
	ll n, m, ans = 0;
	cin >> n >> m;
	DSU d(n);
	vector<tuple<ll, ll, ll>> arr;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr.push_back(make_tuple(c, a, b));
	}
	sort(arr.begin(), arr.end());
	vector<pair<ll, ll>> rb;
	for (auto[c, a, b] : arr) {
		if (d.in_one(a, b)) {
			continue;
		}
		ans += c;
		rb.push_back({a, b});
		d.unite(a, b);
	}
	cout << ans << ' ';
	ans = 30000000000;
	for (auto&[na, nb] : rb) {
		DSU d2(n);
		ll now = 0;
		for (auto[c, a, b] : arr) {
			if (a == na && b == nb) {
				continue;
			}
			if (d2.in_one(a, b)) {
				continue;
			}
			now += c;
			d2.unite(a, b);
		}
		if (d2.is_one()) {
			ans = min(ans, now);
		}
	}
	cout << ans;
}
