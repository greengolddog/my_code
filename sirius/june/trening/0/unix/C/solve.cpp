#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef int_fast32_t ll;
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

void solve() {
	ll m, l;
	cin >> m >> l;
	ll c = m * (m + 1) * 50;
	map<ll, deque<ll>> otr;
	for (ll i = 0; i < m; i++) {
		ll x;
		cin >> x;
		for (ll j = 0; j < x; j++) {
			otr[m - i].push_back(1);
		}
	}
	ll cz;
	cin >> cz;
	map<ll, deque<ll>> p;
	for (ll i = 1; i <= m; i++) {
		ll x;
		cin >> x;
		for (ll j = 0; j < x; j++) {
			p[i].push_back(1);
		}
	}
	for (ll i = 0; i <= c; i++) {
		sort(otr[i].begin(), otr[i].end());
		while (otr[i].size() >= 3) {
			otr[i * 2].push_back(otr[i][0] + otr[i][1]);
			otr[i].pop_front();
			otr[i].pop_front();
		}
		sort(p[i].begin(), p[i].end());
		while (p[i].size() >= 3) {
			p[i * 2].push_back(p[i][0] + p[i][1]);
			p[i].pop_front();
			p[i].pop_front();
		}
	}
	vector<ll> motr(c + 1, -INF32), mp(c + 1, -INF32);
	mp[0] = 0;
	motr[0] = 0;
	for (auto[a, b] : otr) {
		vector<ll> sp(1, 0);
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		for (auto i : b) {
			sp.push_back(sp.back() + i);
		}
		for (ll j = c - a; j >= 0; j--) {
			for (ll k = 1; k <= b.size(); k++) {
				if (j + a * k <= c) {
					assign_max(motr[j + a * k], motr[j] + sp[k]);
				} else {
					break;
				}
			}
		}
	}
	for (auto[a, b] : p) {
		vector<ll> sp(1, 0);
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		for (auto i : b) {
			sp.push_back(sp.back() + i);
		}
		for (ll j = c - a; j >= 0; j--) {
			for (ll k = 1; k <= b.size(); k++) {
				if (j + a * k <= c) {
					assign_max(mp[j + a * k], mp[j] + sp[k]);
				} else {
					break;
				}
			}
		}
	}
	ll ans = -1;
	for (ll i = 0; i <= c; i++) {
		if (l + i <= c && l + i >= 0) {
			assign_max(ans, motr[i] + mp[l + i]);
		}
	}
	cout << (ans == -1 ? "impossible" : to_string(ans + cz)) << '\n';
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
