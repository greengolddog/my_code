#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct DSU {
	vector<ll> arr, rang, p;
	ll size;
	DSU(ll n = 0) {
		size = n;
		arr.resize(n, 0);
		rang.resize(n, 1);
		p.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			arr[i] = i;
		}
	}
	ll parent(ll n) {
		if (arr[n] == n) {
			return n;
		}
		arr[n] = parent(arr[n]);
		return arr[n];
	}
	void do_union(ll a, ll b) {
		a = parent(a);
		b = parent(b);
		if (a == b) {
			return;
		}
		if (rang[a] >= rang[b]) {
			arr[b] = a;
			rang[a] += rang[b];
		} else {
			arr[a] = b;
			rang[b] += rang[a];
		}
	}
	bool get(ll a, ll b) {
		return parent(a) == parent(b);
	}
	ll points(ll n) {
		return p[parent(n)];
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
		string s;
		ll a, b;
		cin >> s >> a;
		if (s == "union") {
			cin >> b;
			d.do_union(a-1, b-1);
		} else {
			cout << d.get_min(a-1)+1 << ' ' << d.get_max(a-1)+1 << ' ' << d.col(a-1) << '\n';
		}
	}
}
