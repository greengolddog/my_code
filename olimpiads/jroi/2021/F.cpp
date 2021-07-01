#pragma GCC optimization("unroll-loops")
#pragma GCC optimization("no-stack-protector")
#pragma GCC optimization("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,abm,popcnt")
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_treele {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 0);
		size = now.size();
		tree.resize(size*2, 0);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (l == r-1) {
			tree[v] = (now[l] == 1 ? l : -1);
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = max(tree[v*2], tree[v*2+1]);
	}
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	ll sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return -1;
		}
		ll mid = (l+r)/2;
		return max(sum(ql, qr, v*2, l, mid), sum(ql, qr, v*2+1, mid, r));
	}
	void change(ll n, ll x) {
		ll now = size+n;
		tree[now] = (x == 1 ? n : -1);
		while (now > 1) {
			now /= 2;
			tree[now] = max(tree[now*2], tree[now*2+1]);
		}
	}
};

struct segment_treefe {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 0);
		size = now.size();
		tree.resize(size*2, 0);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (l == r-1) {
			tree[v] = (now[l] == 1 ? l : size*2);
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = min(tree[v*2], tree[v*2+1]);
	}
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	ll sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return size*2;
		}
		ll mid = (l+r)/2;
		return min(sum(ql, qr, v*2, l, mid), sum(ql, qr, v*2+1, mid, r));
	}
	void change(ll n, ll x) {
		ll now = size+n;
		tree[now] = (x == 1 ? n : size*2);
		while (now > 1) {
			now /= 2;
			tree[now] = min(tree[now*2], tree[now*2+1]);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	if (n <= 10000) {
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (ll i = 0; i < n; i++) {
			ll cb = 0, cm = 0, macb = 0, macm = 0, micb = 0, micm = 0;
			for (ll j = i+1; j < n; j++) {
				if (arr[j] >= arr[i]) {
					cb++;
				} else {
					cm++;
				}
				if ((cb - cm) > (macb - macm)) {
					macb = cb;
					macm = cm;
				}
			}
			cb = macb;
			cm = macm;
			for (ll j = i-1; j >= 0; j--) {
				if (arr[j] >= arr[i]) {
					cb++;
				} else {
					cm++;
				}
				if ((cb - cm) > (macb - macm)) {
					macb = cb;
					macm = cm;
				}
			}
			cb = 0;
			cm = 0;
			for (ll j = i+1; j < n; j++) {
				if (arr[j] > arr[i]) {
					cb++;
				} else {
					cm++;
				}
				if ((cm - cb) > (micm - micb)) {
					micb = cb;
					micm = cm;
				}
			}
			cb = micb;
			cm = micm;
			for (ll j = i-1; j >= 0; j--) {
				if (arr[j] > arr[i]) {
					cb++;
				} else {
					cm++;
				}
				if ((cm - cb) > (micm - micb)) {
					micb = cb;
					micm = cm;
				}
			}
			cout << max((macb-macm+1)/2, (micm-micb)/2) << ' ';
		}
	} else {
		vector<pair<ll, ll>> arr(n, 0), ansbo(n, -1), anssp(n, -1), ansss(n, -1), anssv(n, -1);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		sort(arr.begin(), arr.end());
		ans[0] = n/2;
		segment_treele segl(vector<ll>(n, 0));
		segment_treefe segf(vector<ll>(n, 0));
		for (ll i = 1; i < n; i++) {
			ansbo[i] = abs(n/2-i);
			ll fp = segl.sum(0, arr[i].second), lp = segf.sum(arr[i].second, n);
			if (fp != -1) {
				anssp[i] = 
	}
}
