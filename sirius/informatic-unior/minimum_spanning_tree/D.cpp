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
	ll n, m, ans = 0;
	cin >> n >> m;
	DSU d(n);
	vector<tuple<ll, ll, ll>> arr;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		arr.push_back(make_tuple(c, a, b));
	}
	sort(arr.begin(), arr.end());
	for (auto[c, a, b] : arr) {
		if (d.in_one(a, b)) {
			continue;
		}
		ans += c;
		d.unite(a, b);
	}
	ll g = d.get(0);
	for (ll i = 1; i < n; i++) {
		if (d.get(i) != g) {
			cout << "NON-CONNECTED";
			return 0;
		}
	}
	cout << ans;
}
