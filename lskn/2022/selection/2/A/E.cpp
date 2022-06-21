#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, MAXN = 200'001;
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
	vector<ll> sum, m, cm, sm;
	ll size;
	segment_tree(vector<ll> arr) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, INF32);
		sum.resize(size * 2, 0);
		m.resize(size * 2, INF32);
		cm.resize(size * 2, 0);
		sm.resize(size * 2, INF32);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			sum[v] = arr[l];
			m[v] = arr[l];
			cm[v] = 1;
			sm[v] = INF32;
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		upd(v);
	}
	void upd(ll v) {
		if (m[v * 2] == m[v * 2 + 1]) {
			m[v] = m[v * 2];
			cm[v] = cm[v * 2] + cm[v * 2 + 1];
			sm[v] = min(sm[v * 2], sm[v * 2 + 1]);
		} else {
			if (m[v * 2] < m[v * 2 + 1]) {
				m[v] = m[v * 2];
				cm[v] = cm[v * 2];
				sm[v] = min(m[v * 2 + 1], sm[v * 2]);
			} else {
				m[v] = m[v * 2 + 1];
				cm[v] = cm[v * 2 + 1];
				sm[v] = min(m[v * 2], sm[v * 2 + 1]);
			}
		}
		sum[v] = sum[v * 2] + sum[v * 2 + 1];
	}
	void upd(ll v, ll x) {
		if (m[v] < x) {
			sum[v] -= m[v] * cm[v];
			m[v] = x;
			sum[v] += m[v] * cm[v];
		}
	}
	void push(ll v) {
		upd(v * 2, m[v]);
		upd(v * 2 + 1, m[v]);
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return sum[v];
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		push(v);
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qr) + get(v * 2 + 1, mid, r, ql, qr);
	}
	void change(ll l, ll r, ll x) {
		change(1, 0, size, l, r, x);
	}
	void change(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr && sm[v] > x) {
			upd(v, x);
			return;
		}
		if (qr <= l || r <= ql || m[v] >= x) {
			return;
		}
		push(v);
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, ql, qr, x);
		change(v * 2 + 1, mid, r, ql, qr, x);
		upd(v);
	}
};

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ansall, ans = 0;
	vector<vector<ll>> dels(n);
	for (ll i = 0; i < n; i++) {
		for (ll j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				dels[i].push_back(j);
				if (arr[i] / j != j) {
					dels[i].push_back(arr[i] / j);
				}
			}
		}
	}
	vector<ll> be(MAXN, -1);
	vector<ll> anss(2, 0);
	for (auto i : dels.back()) {
		be[i] = n - 1;
	}
	for (ll j = n - 2; j >= 0; j--) {
		anss.push_back(anss.back());
		for (auto i : dels[j]) {
			if (be[i] != -1) {
				assign_max(anss.back(), i);
			} else {
				be[i] = j;
			}
		}
	}
	ansall = anss.back();
	reverse(anss.begin(), anss.end());
	segment_tree st(anss);
	ans += st.get(1, n + 1);
	vector<bool> nb(MAXN, false);
	for (ll i = 0; i < n - 1; i++) {
		for (auto j : dels[i]) {
			if (nb[j]) {
				st.change(0, n + 1, j);
			} else {
				st.change(0, be[j] + 1, j);
				nb[j] = true;
			}
		}
		ans += st.get(i + 1, n + 1);
		ans -= ansall;
	}
	cout << ans;
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
