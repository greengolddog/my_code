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
		string s = to_string(x);
		return binpow(*this, s, mod);
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

int main() {
	freopen("mpow.in", "r", stdin);
	freopen("mpow.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, p;
	cin >> n >> m >> p;
	vector<vector<ll>> m1(n, vector<ll>(n));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> m1[i][j];
		}
	}
	cout << matrix(m1).pow(m, p);
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
