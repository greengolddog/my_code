#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 1'000'000'000, MOD = 786'433, MAXN = 65'536, sqrt1 = 3;
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
		return 1ll * x * x % MOD;
	} else {
		return 1ll * binpow(a, b - 1) * a % MOD;
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
		vector<ll> e = fft(even, 1ll * w * w % MOD), o = fft(odd, 1ll * w * w % MOD);
		ll k = n / 2;
		ll wt = 1;
		for (ll i = 0; i < k; i++) {
			ans[i] = (e[i] + 1ll * wt * o[i]) % MOD;
			ans[i + k] = sub(e[i], 1ll * wt * o[i] % MOD);
			wt = wt * 1ll * w % MOD;
		}
	}
	return ans;
}

vector<ll> fft(vector<ll> arr) {
	arr.resize(MAXN, 0);
	return fft(arr, sqrt1);
}

vector<ll> ifft(vector<ll> arr) {
	vector<ll> ans = fft(arr, inv(sqrt1));
	for (auto &i : ans) {
		i = i * 1ll * inv(MAXN) % MOD;
	}
	return ans;
}

void solve() {
	ll n, h;
	cin >> n >> h;
	h++;
	vector<vector<ll>> dp_fft;
	vector<ll> ldp(MAXN, 0);
	ldp[1] = 1;
	dp_fft.push_back(vector<ll>(MAXN, 1));
	dp_fft.push_back(fft(ldp));
	for (ll i = 2; i <= h; i++) {
		vector<ll> ans(MAXN, 0);
		for (ll j = 0; j < MAXN; j++) {
			ans[j] = (1ll * dp_fft[i - 1][j] * (dp_fft[i - 1][j] + dp_fft[i - 2][j] * 2)) % MOD;
		}
		ldp = ifft(ans);
		for (ll j = MAXN - 1; j > 0; j--) {
			ldp[j] = ldp[j - 1];
		}
		dp_fft.push_back(fft(ldp));
	}
	cout << ldp[n];
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
