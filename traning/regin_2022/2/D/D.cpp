#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000, mod = 1'000'000'007;

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

ll sub(ll a, ll b) {
	if (a < b) {
		return a - b + mod;
	}
	return a - b;
}

ll sum(ll a, ll b) {
	if (a + b > mod) {
		return a + b - mod;
	}
	return a + b;
}

ll stupid(ll n, ll x) {
	ll arr[5001];
	arr[0] = 1;
	for (ll i = 1; i <= n; i++) {
		arr[i] = arr[i - 1] * i % mod;
	}
	vector<vector<ll>> C(n + 1, vector<ll>(n + 1, 1));
	for (ll i = 2; i <= n; i++) {
		for (ll j = 1; j < i; j++) {
			C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	vector<vector<ll>> pref(n - 1, vector<ll>(n - 1));
	for (ll j = 0; j <= (n - 2); j++) {
		ll i = 0;
		pref[0][j] = arr[i] * arr[n - i - 2] % mod * C[j][i] % mod * (i + 1) % mod;
		for (i = 1; i <= j; i++) {
			pref[i][j] = sum(pref[i - 1][j], arr[i - 1] * arr[n - i - 2] % mod * C[j][i] % mod * ((i + 1) * i / 2) % mod);
		}
	}
	ll ans = 0;
	x = n - x;
	vector<vector<ll>> pref2(n - 1, vector<ll>(n - 1));
	for (ll j = 0; j <= (n - 2); j++) {
		ll i = 0;
		pref2[0][j] = arr[i] * arr[n - i - 2] % mod * C[j][i] % mod * (i + 1) % mod;
		for (i = 1; i <= j; i++) {
			pref2[i][j] = sum(pref2[i - 1][j], arr[i] * arr[n - i - 2] % mod * C[j][i] % mod * (i + 1) % mod);
		}
	}
	for (ll i = 1; i <= x; i++) {
		for (ll j = n; j > x; j--) {
			ans = sum(ans, sum(sub(pref[n - (j - i - 1) - 2][n - (j - i - 1) - 2], pref[i - 1][i - 1]), pref2[i - 1][i - 1]));
		}
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, x;
	cin >> n >> x;
	cout << stupid(n, x);
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
