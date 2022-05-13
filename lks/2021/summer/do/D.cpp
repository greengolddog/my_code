#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<ll> tree;
	ll size = 0;
	segment_tree(vector<ll> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p *= 2;
		}
		arr.resize(p, 0);
		size = p;
		tree.resize(p * 2, 0);
		build(arr, 1, 0, size);
	}
	void build(vector<ll>& arr, ll v, ll l, ll r) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(arr, v * 2, l, mid);
		build(arr, v * 2 + 1, mid, r);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qr)+get(v * 2 + 1, mid, r,  ql, qr);
	}
	void change(ll n, ll x) {
		change(1, 0, size, n, x);
	}
	void change(ll v, ll l, ll r, ll n, ll x) {
		if (n < l || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = x;
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, n, x);
		change(v * 2 + 1, mid, r, n, x);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
};

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, p;
	cin >> n >> p;
	segment_tree st(vector<ll>(n, 1));
	ll now = n, last = 0;
	while (now > 1) {
		ll ost = (p - 1) % now + 1;
		if (st.get(last, n) < ost) {
			ost -= st.get(last, n);
			last = 0;
		}
		ll l = last-1, r = n-1;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (st.get(last, mid+1) < ost) {
				l = mid;
			} else {
				r = mid;
			}
		}
		st.change(r, 0);
		last = r+1;
		now--;
	}
	for (ll i = 0; i < n; i++) {
		if (st.get(i, i+1)) {
			cout << i+1;
			break;
		}
	}
}
