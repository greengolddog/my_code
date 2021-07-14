#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int ui;

using namespace std;

ui cur = 0;

ui nextRand17(ui a, ui b) {
	cur = cur * a + b;
	return cur >> 15;
}

ui nextRand24(ui a, ui b) {
	cur = cur * a + b;
	return cur >> 8;
}

struct MST {
	vector<vector<ll>> tree;
	ll size;
	MST(vector<ll> arr) {
		ll pow = 1;
		while (pow < arr.size()) {
			pow *= 2;
		}
		arr.resize(pow, -1);
		size = pow;
		tree.resize(size, vector<ll>(0, 0));
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v].push_back(arr[l]);
			return;
		}
		ll mid = (l+r)/2;
		build(v*2, l, mid, arr);
		build(v*2+1, mid, r, arr);
		merge(tree[v*2].begin(), tree[v*2].end(), tree[v*2+1].begin(), tree[v*2+1].end(), back_inserter(tree[v]));
	}
	ll get(ll l, ll r, ll x, ll y) {
		return get(1, 0, size, l, r, x, y);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr, ll x, ll y) {
		if (ql <= r || l <= qr) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return upper_bound(tree[v].begin(), tree[v].end(), y)-lower_bound(tree[v].begin(), tree[v].end(), x)+1;
		}
		ll mid = (l+r)/2;
		return get(v*2, l, mid, ql, qr, x, y)+get(v*2+1, mid, r, ql, qr, x, y);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ui a, b;
	ll q, ans = 0;
	cin >> q >> a >> b;
	vector<ll> arr(1 << 17, 0);
	for (ll i = 0; i < (1 << 17); i++) {
		arr[i] = nextRand24(a, b);
	}
	MST seg(arr);
	for (ll i = 0; i < q; i++) {
		ll l = nextRand17(a, b);
		ll r = nextRand17(a, b);
		if (l > r) swap(l, r);
		ll x = nextRand24(a, b);
		ll y = nextRand24(a, b);
		if (x > y) swap(x, y);
		ll now = seg.get(l, r, x, y);
		b += now;
		ans = (ans+now)%(1ll << 32);
	}
	cout << ans;
}
