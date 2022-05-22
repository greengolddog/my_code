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

void solve() {
	ll n = 312;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	ll ans = 0;
	vector<bool> used(n, false);
	vector<vector<ll>> a(n);
	vector<ll> nl(n, 0);
	for (ll i = 0; i < n; i++) {
		nl[i] = i;
		a[i].push_back(i);
	}
	ll i = 0;
	while (true) {
		ll md = INF64, num = -1;
		for (ll j = 0; j < n; j++) {
			if (!used[j] && i != j && nl[i] != nl[j]) {
				if (assign_min(md, arr[i][j])) {
					num = j;
				}
			}
		}
		if (num == -1) {
			break;
		}
		used[num] = true;
		for (auto x : a[num]) {
			a[nl[i]].push_back(x);
			nl[x] = nl[i];
		}
		i = num;
	}
	vector<ll> p = a[nl.back()];
	for (ll i = 0; i < n; i++) {
		ans += arr[p[i]][p[(i + 1) % n]];
	}
	ll N = 100'000'000;
	for (ll i = N / 3 * 2; i < N; i++) {
		if (rnd32() % 2 == 0) {
			ll p1 = abs((ll)rnd32()) % n, p2 = abs((ll)rnd32()) % n;
			ll na = ans - (arr[p[(p1 - 1 + n) % n]][p[p1]] + arr[p[p1]][p[(p1 + 1) % n]] + arr[p[(p2 - 1 + n) % n]][p[p2]] + arr[p[p2]][p[(p2 + 1) % n]]);
			swap(p[p1], p[p2]);
			na += (arr[p[(p1 - 1 + n) % n]][p[p1]] + arr[p[p1]][p[(p1 + 1) % n]] + arr[p[(p2 - 1 + n) % n]][p[p2]] + arr[p[p2]][p[(p2 + 1) % n]]);
			if (na - ans <= 0) {
				ans = na;
			} else {
				swap(p[p1], p[p2]);
			}
		} else {
		}
		cout << i << ' ' << ans << endl;
	}
	for (auto i : p) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
	//cout << ans << '\n';
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
