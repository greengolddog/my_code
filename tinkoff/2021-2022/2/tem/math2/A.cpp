#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, mod = 998'244'353;
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

ll binpow(ll a, ll b, ll mod) {
	if (b == 0) {
		return 1 % mod;
	}
	if (b % 2 == 1) {
		return binpow(a, b - 1, mod) * a % mod;
	} else {
		ll x = binpow(a, b / 2, mod);
		return x * x % mod;
	}
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	reverse(arr.begin(), arr.end());
	ll ansa = 0, ansb = 1, nowa = 1, nowb = 1;
	for (auto i : arr) {
		nowa *= 100;
		nowa %= mod;
		nowb *= i;
		nowb %= mod;
		ansa *= nowb;
		ansa %= mod;
		ansa += nowa * ansb % mod;
		ansa %= mod;
		ansb *= nowb;
		ansb %= mod;
	}
	cout << ansa * binpow(ansb, mod - 2, mod) % mod;
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
