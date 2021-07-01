#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll nod(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return nod(max(a, b)%min(a, b), min(a, b));
}

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll>& arr) {
		ll step = 1;
		while (step < arr.size()) {
			step *= 2;
		}
		arr.resize(step, 0);
		size = step;
		tree.resize(step*2, 0);
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
		tree[v] = nod(tree[v*2], tree[v*2+1]);
	}
	ll get_nod(ll l, ll r) {
		return get_nod(1, 0, size, l, r);
	}
	ll get_nod(ll v, ll l, ll r, ll ql, ll qr) {
		if (qr <= l || r <= ql) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		ll mid = (l+r)/2;
		return nod(get_nod(v*2, l, mid, ql, qr), get_nod(v*2+1, mid, r, ql, qr));
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
		ll l, r;
		cin >> l >> r;
		cout << seg.get_nod(l-1, r) << '\n';
	}
}
