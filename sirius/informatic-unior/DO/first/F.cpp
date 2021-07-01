#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct node {
	ll ans, pref, suff, n;
	node(ll nn) {
		ans = nn == 0;
		pref = nn == 0;
		suff = nn == 0;
		n = 1;
	}
	node(ll ans, ll pref, ll suff, ll n): ans(ans), pref(pref), suff(suff), n(n) {}
	node operator+(node n1) {
		return node(max(ans, max(n1.ans, suff+n1.pref)), ((pref == n) ? pref+n1.pref : pref), ((n1.suff == n1.n) ? n1.suff + suff : n1.suff), n+n1.n);
	}
};

struct segment_tree {
	vector<node> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 1);
		size = now.size();
		tree.resize(size*2, node(0, 0, 0, 0));
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (r - l == 1) {
			tree[v] = node(now[l]);
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
	node sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	node sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (r <= ql || qr <= l) {
			return node(0, 0, 0, 0);
		}
		ll mid = (l+r)/2;
		return sum(ql, qr, v*2, l, mid) + sum(ql, qr, v*2+1, mid, r);
	}
	void change(ll n, ll x) {
		change(n, x, 1, 0, size);
	}
	void change(ll n, ll x, ll v, ll l, ll r) {
		if (l > n || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = node(x);
			return;
		}
		ll mid = (l + r)/2;
		change(n, x, v*2, l, mid);
		change(n, x, v*2+1, mid, r);
		tree[v] = tree[v*2] + tree[v*2+1];
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
	ll k;
	cin >> k;
	for (ll i = 0; i < k; i++) {
		string c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == "UPDATE") {
			seg.change(l-1, r);
		} else {
			cout << seg.sum(l-1, r).ans << '\n';
		}
	}
}
