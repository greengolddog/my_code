#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<stack<ll>> tree;
	vector<bool> u;
	vector<ll> arr;
	ll size = 0, last = 0;
	segment_tree(ll n) {
		ll step = 1;
		while (step < n) {
			step *= 2;
		}
		tree.resize(step*2);
		for (ll i = 1; i < step*2; i++) {
			tree[i].push(0);
		}
		size = step;
		u.resize(1, false);
		arr.resize(1, -1);
	}
	void del(ll i) {
		u[i] = true;
	}
	void push(ll v) {
		while (tree[v].size() != 1) {
			tree[v*2].push(tree[v].top());
			tree[v*2+1].push(tree[v].top());
			tree[v].pop();
		}
	}
	ll get(ll i) {
		return arr[get(i, 1, 0, size)];
	}
	ll get(ll i, ll v, ll l, ll r) {
		while (u[tree[v].top()]) {
			tree[v].pop();
		}
		if (tree[v].size() > 1) {
			return tree[v].top();
		}
		if (r - l == 1) {
			return 0;
		}
		ll mid = (l+r)/2;
		push(v);
		if (mid > i) {
			return get(i, v*2, l, mid);
		}
		return get(i, v*2+1, mid, r);
	}
	void add(ll l, ll r, ll x) {
		arr.push_back(x);
		u.push_back(false);
		last++;
		add(l, r, 1, 0, size, last);
	}
	void add(ll ql, ll qr, ll v, ll l, ll r, ll x) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			tree[v].push(x);
			return;
		}
		push(v);
		ll mid = (l+r)/2;
		add(ql, qr, v*2, l, mid, x);
		add(ql, qr, v*2+1, mid, r, x);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	segment_tree seg(n);
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		char c;
		cin >> c;
		if (c == 'A') {
			ll l, r, x;
			cin >> l >> r >> x;
			seg.add(l-1, r, x);
		}
		if (c == 'G') {
			ll x;
			cin >> x;
			cout << seg.get(x-1) << '\n';
		}
		if (c == 'R') {
			ll x;
			cin >> x;
			seg.del(x);
		}
	}
}
