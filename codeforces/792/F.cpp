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

struct MO {
	vector<ll> col;
	vector<tuple<ll, ll, ll>> q;
	vector<ll> arr;
	ll k = 400;
	ll l = 0, r = 0, ans = 0;
	deque<ll> aa;
	MO(vector<ll> arr): arr(arr) {
		col.resize(arr.size(), 0);
	}
	void add_q(ll l, ll r) {
		q.emplace_back(l, r, q.size());
		aa.push_back(0);
	}
	void add(ll x) {
		col[x]++;
		if (col[x] == 1) {
			ans++;
		}
	}
	void del(ll x) {
		col[x]--;
		if (col[x] == 0) {
			ans--;
		}
	}
	void move_l(ll x) {
		if (x <= l) {
			for (ll i = l - 1; i >= x; i--) {
				add(arr[i]);
			}
		} else {
			for (ll i = l; i < x; i++) {
				del(arr[i]);
			}
		}
		l = x;
	}
	void move_r(ll x) {
		if (x >= r) {
			for (ll i = r; i <= x; i++) {
				add(arr[i]);
			}
		} else {
			for (ll i = r - 1; i >= x; i--) {
				del(arr[i]);
			}
		}
		r = x;
	}
	ll get(ll l, ll r) {
		move_l(l);
		move_r(r);
		return ans;
	}
	deque<ll> end() {
		vector<tuple<ll, ll, ll, ll, ll>> aaa;
		for (auto[a, b, c] : q) {
			ll xx = a / k;
			aaa.emplace_back(xx, b, a, b, c);
		}
		sort(aaa.begin(), aaa.end());
		for (auto[_, __, a, b, c] : aaa) {
			aa[c] = get(a, b);
		}
		return aa;
	}
};

void solve() {
	ll n, mm;
	cin >> n >> mm;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> lf(mm), rf(mm), rs(mm), ls(mm);
	vector<ll> ql(mm), qr(mm);
	for (ll i = 0; i < mm; i++) {
		cin >> lf[i];
		lf[i]--;
		cin >> rf[i];
		rs[i] = lf[i];
		ls[i] = rf[i];
		ql[i] = lf[i];
		qr[i] = rf[i];
	}
	ll log = 20;
	for (ll i = 0; i < log; i++) {
		MO m(arr);
		for (ll j = 0; j < mm; j++) {
			ll mid = (lf[i] + rf[i]) / 2;
			m.add_q(ql[i], mid);
			mid = (ls[i] + rs[i]) / 2;
			m.add_q(mid, qr[i]);
		}
		deque<ll> ans = m.end();
		for (ll j = 0; j < mm; j++) {
			ll mid = (lf[i] + rf[i]) / 2;
			if (ans.front() != 0) {
				rf[j] = mid;
			} else {
				lf[j] = mid;
			}
			ans.pop_front();
			mid = (ls[i] + rs[i]) / 2;
			if (ans.front() != 0) {
				ls[j] = mid;
			} else {
				rs[j] = mid;
			}
			ans.pop_front();
		}
	}
	ll f = 0, l = n + 1;
	for (ll i = 0; i < mm; i++) {
		assign_max(f, lf[i]);
		assign_min(l, rs[i]);
	}
	cout << l - f << '\n';
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
