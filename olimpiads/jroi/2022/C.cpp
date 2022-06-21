#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

struct segment_tree {
	vector<pair<ll, ll>> tree;
	ll size;
	segment_tree(vector<ll> arr) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, 0);
		tree.resize(size * 2, pair(0, 0));
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = make_pair(arr[l], l);
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
	pair<ll, ll> get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	pair<ll, ll> get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return make_pair(INF32, INF32);
		}
		ll mid = (l + r) / 2;
		return min(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
};

ll rec(ll l, ll r, ll v, segment_tree& st) {
	if (r == l) {
		return 0;
	}
	if (r - l == 1) {
		return st.get(l, r).first - v;
	}
	auto[a, b] = st.get(l, r);
	a -= v;
	v += a;
	return a + rec(l, b, v, st) + rec(b + 1, r, v, st);
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	ll mn = INF32, ans = 0;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		assign_min(mn, arr[i]);
	}
	ans += abs(mn);
	for (ll i = 0; i < n; i++) {
		arr[i] -= mn;
	}
	mn = arr[0];
	ans += mn;
	for (ll i = 0; i < n; i++) {
		assign_min(mn, arr[i]);
		arr[i] -= mn;
	}
	mn = arr.back();
	ans += mn;
	for (ll i = n - 1; i >= 0; i--) {
		assign_min(mn, arr[i]);
		arr[i] -= mn;
	}
	segment_tree st(arr);
	cout << ans + rec(0, n, 0, st) * 3 << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
