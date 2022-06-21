#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> arr) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, INF32);
		tree.resize(size * 2, 0);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return INF32;
		}
		ll mid = (l + r) / 2;
		return min(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
};

void solve() {
	ll n;
	cin >> n;
	cout << n << ' ' << n * 2 - 3 << '\n';
	for (ll i = 1; i < n; i++) {
		cout << i << ' ' << (i + 1) << '\n';
	}
	for (ll i = 3; i <= n; i++) {
		cout << 1 << ' ' << i << '\n';
	}
	for (ll i = 1; i < n; i++) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
