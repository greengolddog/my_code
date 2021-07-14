#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<pair<ll, ll>> tree;
	vector<ll> m;
	ll size;
	segment_tree(vector<ll> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p *= 2;
		}
		arr.resize(p, 0);
		size = p;
		tree.resize(p*2, {0, 0});
		m.resize(p*2, 0);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = {arr[l], r};
			return;
		}
		ll mid = (l+r)/2;
		build(v*2, l, mid, arr);
		build(v*2+1, mid, r, arr);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	void push(ll v) {
		m[v*2] += m[v];
		m[v*2+1] += m[v];
		tree[v*2].first += m[v];
		tree[v*2+1].first += m[v];
		m[v] = 0;
	}
	pair<ll, ll> get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	pair<ll, ll> get(ll v, ll l, ll r, ll ql, ll qr) {
		if (qr <= l || r <= ql) {
			return {0, 0};
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		push(v);
		ll mid = (l+r)/2;
		return max(get(v*2, l, mid, ql, qr), get(v*2+1, mid, r, ql, qr));
	}
	void add(ll l, ll r, ll x) {
		add(1, 0, size, l, r, x);
	}
	void add(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			tree[v].first += x;
			m[v] += x;
			return;
		}
		push(v);
		ll mid = (l+r)/2;
		add(v*2, l, mid, ql, qr, x);
		add(v*2+1, mid, r, ql, qr, x);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	pair<ll, ll> all() {
		return tree[1];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll MAXN = 3;
	pair<pair<ll, ll>, ll> ans = {{0, 0}, 0};
	ll n;
	cin >> n;
	vector<tuple<ll, ll, ll, ll>> arr;
	for (ll i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += MAXN;
		x2 += MAXN;
		y1 += MAXN;
		y2 += MAXN;
		arr.push_back(make_tuple(x1, -1, y1, y2));
		arr.push_back(make_tuple(x2, 1, y1, y2));
	}
	segment_tree seg(vector<ll>(MAXN*2, 0));
	sort(arr.begin(), arr.end());
	for (auto[x, c, y1, y2] : arr) {
		seg.add(y1, y2+1, -c);
		ans = max(ans, {seg.all(), x});
	}
	cout << ans.first.first << '\n';
	cout << ans.second-MAXN << ' ' << ans.first.second-MAXN;
}
