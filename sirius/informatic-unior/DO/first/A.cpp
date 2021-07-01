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
		now.resize(step, 0);
		size = now.size();
		tree.resize(size*2, 0);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (l == r-1) {
			tree[v] = now[l];
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	ll sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return 0;
		}
		ll mid = (l+r)/2;
		return sum(ql, qr, v*2, l, mid) + sum(ql, qr, v*2+1, mid, r);
	}
	void change(ll n, ll x) {
		ll now = size+n;
		tree[now] = x;
		while (now > 1) {
			now /= 2;
			tree[now] = tree[now*2]+tree[now*2+1];
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	segment_tree seg(vector<ll>(n, 0));
	for (ll i = 0; i < k; i++) {
		char c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == 'A') {
			seg.change(l-1, r);
		} else {
			cout << seg.sum(l-1, r) << '\n';
		}
	}
}
