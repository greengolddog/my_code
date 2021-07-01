#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step <= now.size()) {
			step *= 2;
		}
		now.resize(step, 1);
		size = now.size();
		tree.resize(size*2, -1);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (r - l == 1) {
			tree[v] = now[l];
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	ll get_max(ll l, ll r) {
		return get_max(l, r, 1, 0, size);
	}
	ll get_max(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (r <= ql || qr <= l) {
			return -1;
		}
		ll mid = (l+r)/2;
		return max(get_max(ql, qr, v*2, l, mid), get_max(ql, qr, v*2+1, mid, r));
	}
	void change(ll n, ll x) {
		change(n, x, 1, 0, size);
	}
	void change(ll n, ll x, ll v, ll l, ll r) {
		if (l > n || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = x;
			return;
		}
		ll mid = (l + r)/2;
		change(n, x, v*2, l, mid);
		change(n, x, v*2+1, mid, r);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	ll get(ll i, ll k) {
		return get(i, size, k, 1, 0, size);
	}
	ll get(ll ql, ll qr, ll k, ll v, ll l, ll r) {
		if (r - l == 1) {
			return r;
		}
		ll mid = (l+r)/2;
		ll c = get_max(ql, qr, v*2, l, mid);
		if (c >= k) {
			return get(ql, qr, k, v*2, l, mid);
		} else {
			return get(ql, qr, k, v*2+1, mid, r);
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	segment_tree seg(arr);
	for (ll i = 0; i < k; i++) {
		ll t;
		cin >> t;
		ll l, r;
		cin >> l >> r;
		if (t == 0) {
			seg.change(l-1, r);
		} else {
			ll ans = seg.get(l-1, r);
			if (ans > n) {
				cout << -1 << '\n';
			} else {
				cout << ans << '\n';
			}
		}
	}
}
