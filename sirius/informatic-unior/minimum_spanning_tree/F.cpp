#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> pred, rang, sum;
	ll size;
	DSU(ll n) {
		pred.resize(n, 0);
		rang.resize(n, 1);
		sum.resize(n, 0);
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
	void unite(ll a, ll b, ll w) {
		a = get(a);
		b = get(b);
		if (a == b) {
			sum[a] += w;
			return;
		}
		if (rang[a] < rang[b]) {
			swap(a, b);
		}
		pred[b] = a;
		rang[a] += rang[b];
		sum[a] += w;
		sum[a] += sum[b];
	}
	bool in_one(ll a, ll b) {
		return get(a) == get(b);
	}
	ll get_sum(ll n) {
		return sum[get(n)];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	DSU d(n);
	for (ll i = 0; i < m; i++) {
		ll c;
		cin >> c;
		if (c == 2) {
			ll x;
			cin >> x;
			x--;
			cout << d.get_sum(x) << '\n';
		} else {
			ll a, b, w;
			cin >> a >> b >> w;
			a--;
			b--;
			d.unite(a, b, w);
		}
	}
}
