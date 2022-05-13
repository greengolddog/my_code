#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
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

void solve() {
	ll n, t;
	double p;
	cin >> n >> p >> t;
	vector<double> arr(n + 1, 0);
	arr[0] = 1;
	for (ll i = 0; i < t; i++) {
		vector<double> narr(n + 1, 0);
		for (ll j = 0; j < n; j++) {
			narr[j] += arr[j] * (1 - p);
			narr[j + 1] += arr[j] * p;
		}
		narr.back() += arr.back();
		arr = narr;
	}
	double ans = 0;
	for (ll i = 0; i <= n; i++) {
		ans += i * arr[i];
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
