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
	freopen("cutting.in", "r", stdin);
	freopen("cutting.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	DSU d(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
	}
	vector<tuple<string, ll, ll>> arr;
	vector<bool> ans;
	for (ll i = 0; i < k; i++) {
		string c;
		cin >> c;
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr.push_back(make_tuple(c, a, b));
	}
	reverse(arr.begin(), arr.end());
	for (auto&[c, a, b] : arr) {
		if (c == "cut") {
			d.unite(a, b);
		} else {
			ans.push_back(d.in_one(a, b));
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << (i ? "YES\n" : "NO\n");
	}
}
