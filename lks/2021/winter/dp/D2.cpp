#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

using namespace std;

template<typename T>
T longpow(T a, ll x, ll mod = INF) {
	T ans = a;
	for (ll i = 1; i < x; i++) {
		ans = ans * a;
		ans = ans % mod;
	}
	return ans;
}

template<typename T>
T binpow(T a, string& x, ll mod = INF) {
	a = a % mod;
	if (x == "1") {
		return a;
	}
	if (x.back() != '0') {
		x.back()--;
		return binpow(a, x, mod) * a % mod;
	} else {
		x.pop_back();
		return longpow(binpow(a, x, mod), 10, mod);
	}
}

template<typename T>
T binpow(T a, ll x, ll mod = INF) {
	a = a % mod;
	if (x == 1) {
		return a;
	}
	if (x % 2 == 0) {
		return longpow(binpow(a, x / 2, mod), 2, mod);
	} else {
		return binpow(a, x - 1, mod) * a % mod;
	}
}

struct matrix {
	vector<vector<__int128>> arr;
	matrix(vector<vector<ll>> a) {
		for (auto i : a) {
			arr.push_back(vector<__int128>(0, 0));
			for (auto j : i) {
				arr.back().push_back(j);
			}
		}
	}
	matrix(ll n = 0) {
		arr.resize(n, vector<__int128>(n, 0));
		for (ll i = 0; i < n; i++) {
			arr[i][i] = 1;
		}
	}
	matrix operator* (matrix m) {
		matrix ans(vector<vector<ll>>(arr.size(), vector<ll>(m.arr[0].size(), 0)));
		for (ll i = 0; i < arr.size(); i++) {
			for (ll j = 0; j < m.arr[0].size(); j++) {
				for (ll k = 0; k < m.arr.size(); k++) {
					ans.arr[i][j] += arr[i][k] * m.arr[k][j];
				}
			}
		}
		return ans;
	}
	matrix operator% (ll mod) {
		matrix m = *this;
		for (auto& i : m.arr) {
			for (auto& j : i) {
				j %= mod;
			}
		}
		return m;
	}
	matrix pow(ll x, ll mod = INF) {
		if (x == 0) {
			return matrix(arr.size());
		}
		return binpow(*this, x, mod);
	}
};

ostream& operator<< (ostream &out, matrix m) {
	for (auto i : m.arr) {
		for (auto j : i) {
			cout << (ll)j << ' ';
		}
		cout << '\n';
	}
	return out;
}

bool get(ll x, ll i) {
	return (x >> i) & 1;
}

int main() {
	freopen("nice3.in", "r", stdin);
	freopen("nice3.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, p;
	cin >> n >> m >> p;
	if (n == 1) {
		return 1;
	}
	if (n > m) {
		swap(n, m);
	}
	vector<vector<bool>> go(1 << n, vector<bool>(1 << n, false));
	vector<bool> can_zero(1 << n, false), can_one(1 << n, false);
	for (ll i = 0; i < (1 << n); i++) {
		bool b = true;
		for (ll j = 0; j < n; j++) {
			if (!get(i, j)) {
				if (j != n - 1 && !get(i, j + 1)) {
					b = false;
					break;
				}
			}
		}
		can_zero[i] = b;
	}
	for (ll i = 0; i < (1 << n); i++) {
		bool b = true;
		for (ll j = 0; j < n; j++) {
			if (get(i, j)) {
				if (j != n - 1 && get(i, j + 1)) {
					b = false;
					break;
				}
			}
		}
		can_one[i] = b;
	}
	for (ll i = 0; i < (1 << n); i++) {
		for (ll j = 0; j < (1 << n); j++) {
			go[i][j] = can_zero[i | j] && can_one[i & j];
		}
	}
	vector<ll> dp(1 << n, 1);
	for (ll i = 1; i < m; i++) {
		vector<ll> new_dp(1 << n, 0);
		for (ll j = 0; j < (1 << n); j++) {
			if (dp[j] == 0) {
				continue;
			}
			for (ll k = 0; k < (1 << n); k++) {
				if (go[j][k]) {
					new_dp[k] += dp[j];
					new_dp[k] %= p;
				}
			}
		}
		dp = new_dp;
	}
	ll ans = 0;
	for (auto i : dp) {
		ans += i;
	}
	cout << ans % p;
}
/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
