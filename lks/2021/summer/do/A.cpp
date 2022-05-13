#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 1);
		size = now.size();
		tree.resize(size * 2, 0);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (r - l == 1) {
			tree[v] = now[l] == 0;
			return;
		}
		ll mid = (l + r) / 2;
		build(now, l, mid, v * 2);
		build(now, mid, r, v * 2 + 1);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	ll sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (r <= ql || qr <= l) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return sum(ql, qr, v * 2, l, mid) + sum(ql, qr, v * 2 + 1, mid, r);
	}
	void change(ll n, ll x) {
		change(n, x, 1, 0, size);
	}
	void change(ll n, ll x, ll v, ll l, ll r) {
		if (l > n || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = x == 0;
			return;
		}
		ll mid = (l + r)/2;
		change(n, x, v * 2, l, mid);
		change(n, x, v * 2 + 1, mid, r);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	ll k_th(ll l, ll r, ll k) {
		return k_th(l, r, k, 1, 0, size);
	}
	ll k_th(ll ql, ll qr, ll k, ll v, ll l, ll r) {
		if (r - l == 1) {
			return r;
		}
		ll mid = (l + r) / 2;
		ll c = sum(ql, qr, v * 2, l, mid);
		if (c >= k) {
			return k_th(ql, qr, k, v * 2, l, mid);
		} else {
			return k_th(ql, qr, k-c, v * 2 + 1, mid, r);
		}
	}
};

int main() {
    freopen("kthzero.in", "r", stdin);
    freopen("kthzero.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	segment_tree seg(arr);
	for (ll i = 0; i < k; i++) {
		char c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == 'u') {
			seg.change(l - 1, r);
		} else {
			cin >> n;
			if (seg.sum(l - 1, r) < n) {
				cout << -1 << '\n';
			} else {
				cout << seg.k_th(l - 1, r, n) << '\n';
			}
		}
	}
}
