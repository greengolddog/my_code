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
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr[i] = 1 - (c - '0');
	}
	ll m, a, b;
	cin >> m >> a >> b;
	vector<ll> dp(n - (m - 1) * (a + b) - b, 0);
	for (ll i = 0; i < min((ll)dp.size(), a + b); i++) {
		for (ll j = i + (m - 1) * (a + b); j >= 0; j -= a + b) {
			dp[i] += arr[j];
		}
	}
	for (ll i = a + b; i < dp.size(); i++) {
		dp[i] = dp[i - a - b] - arr[i - a - b] + arr[i + (m - 1) * (a + b)];
	}
	ll ans = 0, ns = 0;
	for (ll i = 0; i < a; i++) {
		ns += dp[i];
	}
	ans += ns == 0;
	for (ll i = a; i < dp.size(); i++) {
		ns += dp[i];
		ns -= dp[i - a];
		ans += ns == 0;
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
