#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct merge_sort_tree {
	vector<vector<ll>> tree;
	ll size = 0;
	merge_sort_tree(vector<ll> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p *= 2;
		}
		arr.resize(p, 0);
		tree.resize(p * 2);
		size = p;
		build(arr, 0, size, 1);
	}
	void build(vector<ll>& arr, ll l, ll r, ll v) {
		if (r - l == 1) {
			tree[v] = vector<ll>(1, arr[l]);
			return;
		}
		ll mid = (l + r) / 2;
		build(arr, l, mid, v * 2);
		build(arr, mid, r, v * 2 + 1);
		merge(tree[v * 2].begin(), tree[v * 2].end(), tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(), back_inserter(tree[v]));
	}
	ll get(ll l, ll r, ll x) {
		return get(1, 0, size, l, r, x);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			return upper_bound(tree[v].begin(), tree[v].end(), x)-tree[v].begin();
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qr, x)+get(v * 2 + 1, mid, r, ql, qr, x);
	}
};

int main() {
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort_tree st(arr);
	for (ll i = 0; i < m; i++) {
		ll x, y, l, r;
		cin >> x >> y >> l >> r;
		x--;
		cout << st.get(x, y, r) - st.get(x, y, l - 1) << '\n';
	}
}
