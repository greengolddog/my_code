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
	vector<ll> tree, m;
	ll size;
	segment_tree(ll n = 1) {
		size = 1;
		while (size < n) {
			size *= 2;
		}
		tree.resize(size * 2, 0);
		m.resize(size * 2, 0);
	}
	void push(ll v) {
		tree[v * 2] += m[v];
		tree[v * 2 + 1] += m[v];
		m[v * 2] += m[v];
		m[v * 2 + 1] += m[v];
		m[v] = 0;
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return INF64;
		}
		push(v);
		ll mid = (l + r) / 2;
		return min(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
	void change(ll l, ll r, ll x) {
		change(1, 0, size, l, r, x);
	}
	void change(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			tree[v] += x;
			m[v] += x;
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		push(v);
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, ql, qr, x);
		change(v * 2 + 1, mid, r, ql, qr, x);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
};

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n - 1, 0);
	for (ll i = 0; i < n - 1; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	segment_tree st(n);
	st.change(n - 1, n, 1);
	for (ll i = n - 2; i >= 0; i--) {
		ll now = st.get(i + 1, arr[i]) + n - arr[i];
		ans += now;
		st.change(i, i + 1, now);
		st.change(i, n, 1);
	}
	cout << ans << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
