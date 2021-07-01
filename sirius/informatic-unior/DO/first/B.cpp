#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<pair<ll, ll>> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 0);
		size = now.size();
		tree.resize(size*2, {0, 0});
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (l == r-1) {
			tree[v] = {now[l], r};
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	ll get_max(ll l, ll r) {
		return get_max(l, r, 1, 0, size).second;
	}
	pair<ll, ll> get_max(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return {0, 0};
		}
		ll mid = (l+r)/2;
		return max(get_max(ql, qr, v*2, l, mid), get_max(ql, qr, v*2+1, mid, r));
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	segment_tree seg(arr);
	cin >> k;
	for (ll i = 0; i < k; i++) {
		ll l, r;
		cin >> l >> r;
		cout << seg.get_max(l-1, r) << '\n';
	}
}
