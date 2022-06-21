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
	vector<ll> arr(n, 0);
	ll x = (n + 1) / 2;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> sum(n, 0);
	sum.back() = arr.back();
	for (ll i = 0; i < x - 1; i++) {
		sum.back() += arr[i];
	}
	for (ll i = n - 2; i >= 0; i--) {
		sum[i] = sum[i + 1];
		sum[i] += arr[i];
		sum[i] -= arr[(i + x) % n];
	}
	for (ll i = 0; i < n; i++) {
		sum.push_back(sum[i]);
	}
	segment_tree st(sum);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		assign_max(ans, st.get(i, i + x));
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
