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

struct q {
	deque<pair<ll, bool>> qu, pows;
	stack<pair<ll, pair<ll, bool>>> ot;
	bool b = false;
	ll ans = 0;
	q() {
		qu.push_back(make_pair(0, false));
		pows.push_back(make_pair(1, false));
	}
	ll get() {
		return ans;
	}
	void push_back(ll x) {
		if (x <= 0) {
			qu.push_back(make_pair(x, false));
			pows.push_back(make_pair(1, false));
			sum = (sum + x * 2 + MOD * 2) % MOD;
			ans += x * 2 + MOD * 2;
			ans %= MOD;
		} else {
			if (pows.back().second) {
				x = x * pows.back() * 2 % MOD;
				qu.back().first += x;
				qu.back().first %= MOD;
				pows.back().first *= 2;
				pows.back().first %= MOD;
				ans += x;
				ans %= MOD;
			} else {
				x = x * pows.back() * 2;
				ans += x * 2;
				ans %= MOD;
				qu.back().first += x;
				pows.back().first *= 2;
				if (qu.back().first > MOD * 2 || qu.back().second) {
					ans -= (x - x * x / MOD) + MOD;
					ans %= MOD;
					qu.back().first %= MOD;
					qu.back().second = true;
					while (qu.size() > 1) {
						x = qu.back().first;
						qu.pop_back();
						ll pw = pows.back().first;
						bool bb = pows.back().second;
						pows.pop_back();
						ans -= x;
						x *= pows.back().first;
						x %= MOD;
						ans += x + MOD * 2;
						ans %= MOD;
						pows.back().first *= pw;
						if (pows.back().first > MOD * 2 || bb || pows.back().second) {
							pows.back().first %= MOD;
							pows.back().second = true;
						}
						qu.back().first += x + MOD * 2;
						qu.back().first %= MOD;
						qu.back().second = true;
					}
				} else {<F11>
					if (
			}
		}
	}
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < m; i++) {
		q qq;
		ll l, r;
		cin >> l >> r;
		l--;
		for (ll j = l; j < r; j++) {
			qq.push_back(arr[i]);
		}
		cout << qq.get() << '\n';
	}
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
