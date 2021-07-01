#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<pair<ll, ll>> tree;
	vector<ll> md;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 0);
		size = now.size();
		tree.resize(size*2, {0, 0});
		md.resize(size*2, 0);
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
	void push(ll v, ll l, ll r) {
		ll mid = (l+r)/2;
		md[v*2] += md[v];
		md[v*2+1] += md[v];
		tree[v*2].first += md[v];
		tree[v*2+1].first += md[v];
		md[v] = 0;
	}
	pair<ll, ll> get_max() {
		return get_max(0, size, 1, 0, size);
	}
	pair<ll, ll> get_max(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return {0, 0};
		}
		push(v, l, r);
		ll mid = (l+r)/2;
		return max(get_max(ql, qr, v*2, l, mid), get_max(ql, qr, v*2+1, mid, r));
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
			tree[v].first += x;
			return;
		}
		push(v, l, r);
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
	tuple<ll, ll, ll> ans = make_tuple(-1, 0, 0);
	segment_tree seg(vector<ll>(2222222, 0));
	vector<tuple<ll, ll, ll, ll, ll>> arr;
	for (ll i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr.push_back({y1, 0, x1, x2, 1});
		arr.push_back({y2, 1, x1, x2, -1});
	}
	sort(arr.begin(), arr.end());
	for (auto&[y, _, x1, x2, i] : arr) {
		seg.update(x1+1000000, x2+1000001, i);
		pair<ll, ll> ans_now = seg.get_max();
		ans = max(ans, make_tuple(ans_now.first, ans_now.second-1000001, y));
	}
	auto[a, x, y] = ans;
	cout << a << '\n' << x << ' ' << y;
}
