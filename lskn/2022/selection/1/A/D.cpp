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

bool check(ll x) {
	if (x == 0 || x == 1) {
		return false;
	}
	bool b = false;
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			x /= i;
			b = true;
		}
		if (b) {
			return x == 1;
		}
	}
	return true;
}

ll solve(ll x) {
	if (x == 1) {
		return 2;
	}
	set<ll> s;
	deque<pair<ll, ll>> d;
	ll nx = x;
	for (ll i = 2; i * i <= nx; i++) {
		while (nx % i == 0) {
			if (d.size() == 0 || d.back().first != i) {
				d.push_back(make_pair(i, 1));
			}
			d.back().second *= i;
			nx /= i;
		}
	}
	if (nx != 1) {
		d.push_back(make_pair(nx, nx));
	}
	if (d.front().first == 2) {
		d.pop_front();
	}
	for (ll i = 0; i < (1 << d.size()); i++) {
		nx = x * 8;
		for (ll j = 0; j < d.size(); j++) {
			if ((i >> j) & 1) {
				nx /= d[j].second;
			}
		}
		do {
			if (((nx - 2) * nx % x == 0 && check((nx - 2) * nx / x))) {
				s.insert(nx - 1);
			}
			if (((nx + 2) * nx % x == 0 && check((nx + 2) * nx / x))) {
				s.insert(nx + 1);
			}
		} while (nx % 2 == 0 && (nx /= 2) != 0);
	}
	return s.size();
}

ll solve2(ll x) {
	if (x == 1) {
		return 2;
	}
	ll ans = 0;
	for (ll i = 2; i <= x * x; i++) {
		if ((i - 1) * (i + 1) % x == 0) {
			if (check((i - 1) * (i + 1) / x)) {
				ans++;
				//cout << i << ' ';
			}
		}
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		ll x;
		cin >> x;
		cout << solve(x) << '\n';
	}
	//for (ll i = 1; i < 100000; i++) {
	//	cout << i << endl;
	//	if (solve(i) != solve2(i)) {
	//		cout << i;
	//		break;
	//	}
	//}
}
