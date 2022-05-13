#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000, MOD = 998'244'353, LOGMAXN = 19;
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

ll binpow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		ll x = binpow(a, b / 2);
		return x * x % MOD;
	} else {
		return binpow(a, b - 1) * a % MOD;
	}
}

ll inv(ll x) {
	return binpow(x, MOD - 2);
}

ll sub(ll a, ll b) {
	if (a - b < 0) {
		return a - b + MOD;
	}
	return a - b;
}

vector<ll> fft(vector<ll> arr, ll w) {
	ll n = arr.size();
	vector<ll> ans(n, 0);
	if (n == 1) {
		ans[0] = arr[0];
	} else {
		vector<ll> even, odd;
		for (ll i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even.push_back(arr[i]);
			} else {
				odd.push_back(arr[i]);
			}
		}
		vector<ll> e = fft(even, w * w % MOD), o = fft(odd, w * w % MOD);
		ll k = n / 2, wt = 1;
		for (ll i = 0; i < k; i++) {
			ans[i] = (e[i % k] + wt * o[i % k] % MOD) % MOD;
			ans[i + k] = sub(e[i % k], wt * o[i % k] % MOD);
			wt *= w;
			wt %= MOD;
		}
	}
	return ans;
}

vector<ll> fft(vector<ll> arr) {
	arr.resize((1 << LOGMAXN), 0);
	return fft(arr, 805775211);
}

vector<ll> ifft(vector<ll> arr) {
	vector<ll> ans = fft(arr, inv(805775211));
	for (auto& i : ans) {
		i *= inv(arr.size());
		i %= MOD;
	}
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(1 << n, 0), b(1 << n, 0);
	for (ll i = 0; i < (1 << n); i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < (1 << n); i++) {
		cin >> b[i];
	}
	vector<ll> a1 = fft(a), a2 = fft(b);
	for (ll i = 0; i < a1.size(); i++) {
		a1[i] *= a2[i];
		a1[i] %= MOD;
	}
	vector<ll> ans = ifft(a1);
	for (ll i = 0; i < (1 << (n + 1)); i++) {
		cout << ans[i] << ' ';
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
