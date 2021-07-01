#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

template<typename T>
bool smin(T& a, const T& b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool smax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct segment_tree {
	vector<ll> treemin, treemax, md;
	ll size;
	segment_tree(vector<ll> arr = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < arr.size()) {
			step *= 2;
		}
		arr.resize(step, -1);
		size = step;
		treemin.resize(step*2, 0);
		treemax.resize(step*2, 0);
		md.resize(step*2, -1);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			treemin[v] = ((arr[l] != -1 )? arr[l] : 10000000000000ll);
			treemax[v] = arr[l];
			return;
		}
		ll mid = (l+r)/2;
		build(v*2, l, mid, arr);
		build(v*2+1, mid, r, arr);
		treemin[v] = min(treemin[v*2], treemin[v*2+1]);
		treemax[v] = max(treemax[v*2], treemax[v*2+1]);
	}
	void push(ll v) {
		if (md[v] == -1) {
			return;
		}
		smax(md[v*2], md[v]);
		smax(md[v*2+1], md[v]);
		smax(treemin[v*2], md[v]);
		smax(treemax[v*2], md[v]);
		smax(treemin[v*2+1], md[v]);
		smax(treemax[v*2+1], md[v]);
		md[v] = -1;
	}
	ll mmm(ll l, ll r) {
		pair<ll, ll> ans = rmmq(l, r, 1, 0, size);
		return ans.first - ans.second;
	}
	pair<ll, ll> rmmq(ll ql, ll qr, ll v, ll l, ll r) {
		if (qr <= l || r <= ql) {
			return {-1, 10000000000000ll};
		}
		if (ql <= l && r <= qr) {
			return {treemax[v], treemin[v]};
		}
		push(v);
		ll mid = (l+r)/2;
		pair<ll, ll> a1 = rmmq(ql, qr, v*2, l, mid), a2 = rmmq(ql, qr, v*2+1, mid, r);
		return {max(a1.first, a2.first), min(a1.second, a2.second)};
	}
	void update(ll l, ll r, ll x) {
		update(l, r, 1, 0, size, x);
	}
	void update(ll ql, ll qr, ll v, ll l, ll r, ll x) {
		if (qr <= l || r <= ql) {
			return;
		}
		if (ql <= l && r <= qr) {
			smax(md[v], x);
			smax(treemin[v], x);
			smax(treemax[v], x);
			return;
		}
		push(v);
		ll mid = (l+r)/2;
		update(ql, qr, v*2, l, mid, x);
		update(ql, qr, v*2+1, mid, r, x);
		treemin[v] = min(treemin[v*2], treemin[v*2+1]);
		treemax[v] = max(treemax[v*2], treemax[v*2+1]);
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
		string c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == "ask") {
			cout << seg.mmm(l-1, r) << '\n';
		} else {
			ll x;
			cin >> x;
			seg.update(l-1, r, x);
		}
	}
}
