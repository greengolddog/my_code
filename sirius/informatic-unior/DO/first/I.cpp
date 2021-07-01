#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

pair<ll, ll> add(pair<ll, ll> p1, pair<ll, ll> p1) {
	return {p1.first+p2.first, p1.second+p2.second};
}

struct segment_tree {
	vector<pair<ll, ll>> tree;
	ll size, os;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		os = now.size();
		ll step = 1;
		while (step <= now.size()) {
			step *= 2;
		}
		now.resize(step, -1000000000000000000);
		size = now.size();
		tree.resize(size*2, 0);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (l == r-1) {
			tree[v] = {((l != 0) && (now[l]+1 >= now[l-1])), ((l != os-1) && (now[l]+1 >= now[l+1]))};
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = add(tree[v*2], tree[v*2+1]);
	}
	pair<ll, ll> sum(ll l, ll r) {
		pair<ll, ll> ans = sum(l, r, 1, 0, size);
		return {ans.first - tree[size+l].first, ans.second - tree[size+r-1].second};
	}
	pair<ll, ll> sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return -1000000000000000000;
		}
		ll mid = (l+r)/2;
		return add(sum(ql, qr, v*2, l, mid), sum(ql, qr, v*2+1, mid, r));
	}
	void change(ll n, ll x) {
		ll now = size+n;
		tree[now] = {((l != 0) && ((now[l]+1 >= now[l-1]))), ((l != 0) && ((now[l] >= now[l-1]+1)))};
		while (now > 1) {
			now /= 2;
			tree[now] = add(tree[now*2], tree[now*2+1]);
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	segment_tree seg(arr);
	for (ll i = 0; i < m; i++) {
		ll c;
		cin >> c;
		if (c == 1) {
			ll l, r;
			cin >> l >> r;
			if (l > r) {
				cout << ((seg.sum(r-1, l).first) ? "YES" : "NO") << '\n';
			} else {
				cout << ((seg.sum(l-1, r).second) ? "NO" : "YES") << '\n';
			}
		} else {
			ll l, r, d;
			cin >> l >> r >> d;
			seg.change
		}
	}
}
