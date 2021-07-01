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
		arr.resize(step, -1);
		size = step;
		tree.resize(step*2, 0);
		md.resize(step*2, 0);
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
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	void push(ll v) {
		md[v*2] += md[v];
		md[v*2+1] += md[v];
		tree[v*2] += md[v];
		tree[v*2+1] += md[v];
		md[v] = 0;
	}
	ll rmq(ll l, ll r) {
		return rmq(l, r, 1, 0, size);
	}
	ll rmq(ll ql, ll qr, ll v, ll l, ll r) {
		if (qr <= l || r <= ql) {
			return -1;
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		push(v);
		ll mid = (l+r)/2;
		return max(rmq(ql, qr, v*2, l, mid), rmq(ql, qr, v*2+1, mid, r));
	}
	void update(ll l, ll r, ll x) {
		update(l, r, 1, 0, size, x);
	}
	void update(ll ql, ll qr, ll v, ll l, ll r, ll x) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			md[v] += x;
			tree[v] += x;
			return;
		}
		push(v);
		ll mid = (l+r)/2;
		update(ql, qr, v*2, l, mid, x);
		update(ql, qr, v*2+1, mid, r, x);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	segment_tree seg(arr);
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		char c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == 'm') {
			cout << seg.rmq(l-1, r) << '\n';
		} else {
			ll x;
			cin >> x;
			seg.update(l-1, r, x);
		}
	}
}
