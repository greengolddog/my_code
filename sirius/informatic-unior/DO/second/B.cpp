#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<ll> tree, md;
	ll size;
	segment_tree(vector<ll> arr = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < arr.size()) {
			step *= 2;
		}
		arr.resize(step, 0);
		size = step;
		tree.resize(step*2, 0);
		md.resize(step*2, -1);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l+r)/2;
		build(v*2, l, mid, arr);
		build(v*2+1, mid, r, arr);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
	void push(ll v, ll l, ll r) {
		if (md[v] == -1) {
			return;
		}
		ll mid = (l+r)/2;
		md[v*2] = md[v];
		md[v*2+1] = md[v];
		tree[v*2] = md[v]*(mid-l);
		tree[v*2+1] = md[v]*(r-mid);
		md[v] = -1;
	}
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	ll sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (qr <= l || r <= ql) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		push(v, l, r);
		ll mid = (l+r)/2;
		return sum(ql, qr, v*2, l, mid) + sum(ql, qr, v*2+1, mid, r);
	}
	void update(ll l, ll r, ll x) {
		update(l, r, 1, 0, size, x);
	}
	void update(ll ql, ll qr, ll v, ll l, ll r, ll x) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			md[v] = x;
			tree[v] = x*(r-l);
			return;
		}
		push(v, l, r);
		ll mid = (l+r)/2;
		update(ql, qr, v*2, l, mid, x);
		update(ql, qr, v*2+1, mid, r, x);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	segment_tree seg(vector<ll>(n, 0));
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		char c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == 'Q') {
			cout << seg.sum(l-1, r) << '\n';
		} else {
			ll x;
			cin >> x;
			seg.update(l-1, r, x);
		}
	}
}
