#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p = p*2;
		}
		arr.resize(p, 0);
		size = p;
		tree.resize(p*2, 0);
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
		tree[v] = tree[v*2]+tree[v*2+1];
	}
	ll sum(ll l, ll r) {
		return sum(1, 0, size, l, r);
	}
	ll sum(ll v, ll l, ll r, ll ql, ll qr) {
		if (qr <= l || r <= ql) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		ll mid = (l+r)/2;
		return sum(v*2, l, mid, ql, qr)+sum(v*2+1, mid, r, ql, qr);
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
		ll mid = (l+r)/2;
		change(v*2, l, mid, n, x);
		change(v*2+1, mid, r, n, x);
		tree[v] = tree[v*2]+tree[v*2+1];
	}
};

ll t = 0;

void dfs(ll v, ll p, vector<ll>& arr, vector<vector<ll>>& tree, vector<ll>& tin, vector<ll>& tout) {
	tin[v] = t;
	arr.push_back(v);
	t++;
	for (auto u : tree[v]) {
		if (u != p) {
			dfs(u, v, arr, tree, tin, tout);
		}
	}
	tout[v] = t;
	arr.push_back(v);
	t++;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, root = 0;
	cin >> n;
	vector<vector<ll>> tree(n, vector<ll>(0, 0));
	vector<ll> eo, tin(n, 0), tout(n, 0), color(n, 0);
	for (ll i = 0; i < n; i++) {
		ll a, c;
		cin >> a >> c;
		a--;
		color[i] = c;
		if (a == -1) {
			root = i;
		} else {
			tree[i].push_back(a);
			tree[a].push_back(i);
		}
	}
	dfs(root, -1, eo, tree, tin, tout);
	vector<ll> arr(n*2, 0);
	for (ll i = 0; i < n*2; i++) {
		arr[i] = color[eo[i]];
	}
	vector<ll> num(n, -1);
	segment_tree seg(vector<ll>(n*2, 0));
	vector<tuple<ll, ll, ll>> z(n);
	for (ll i = 0; i < n; i++) {;
		ll l = tin[i], r = tout[i];
		z[i] = make_tuple(r+1, l, i);
	}
	sort(z.begin(), z.end());
	ll last = 0;
	vector<ll> ans(n, 0);
	for (auto[r, l, j] : z) {
		for (ll i = last; i < r; i++) {
			seg.change(i, 1);
			if (num[arr[i]] != -1) {
				seg.change(num[arr[i]], 0);
			}
			num[arr[i]] = i;
		}
		last = r;
		ans[j] = seg.sum(l, r);
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}
