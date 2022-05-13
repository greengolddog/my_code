#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 1'000'000'000'000'000'000;

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

mt19937 rnd(time(0));

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 0;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<ll> arr(n * 2, 0);
		ll s = 0;
		for (ll i = 0; i < n * 2; i++) {
			cin >> arr[i];
			s += arr[i];
		}
		vector<vector<ll>> dp(s + 1, vector<ll>(2 * n + 1, -1));
		dp[0][0] = 0;
		for (auto i : arr) {
			for (ll j = s; j >= 0; j--) {
				for (ll k = 2 * n; k >= 0; k--) {
					if (dp[j][k] != -1 && dp[j + i][k + 1] == -1) {
						dp[j + i][k + 1] = i;
					}
				}
			}
		}
		ll aa = INF;
		for (ll need = 0; need <= s; need++) {
			vector<ll> a(n), b;
			ll x = need;
			if (dp[x][n] == -1) {
				continue;
			}
			multiset<ll> ss;
			for (auto i : arr) {
				ss.insert(i);
			}
			ll col = n;
			while (col > 0) {
				a[col - 1] = dp[x][col];
				ss.erase(ss.find(dp[x][col]));
				x -= dp[x][col];
				col--;
			}
			for (auto i : ss) {
				b.push_back(i);
			}
			ll ans = 0;
			for (ll i = 0; i < n; i++) {
				for (ll j = i + 1; j < n; j++) {
					ans += (a[i] + a[j]) * (a[i] + a[j]) + (b[i] + b[j]) * (b[i] + b[j]);
				}
			}
			assign_min(aa, ans);
		}
		cout << aa << '\n';
	}
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
