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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<ll>> arr(n, vector<ll>(m, 0));
	vector<ll> sumv(m, 0), sumh(n, 0);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
			sumv[j] += arr[i][j];
			sumh[i] += arr[i][j];
			sum += arr[i][j];
		}
	}
	if (k == 1) {
		ll ans = sum - arr[0][0];
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				assign_max(ans, sum - arr[i][j] * 3 + sumv[j] + sumh[i]);
			}
		}
		cout << ans;
		return 0;
	}
	if (k == 2) {
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll k = 0; k < m; k++) {
					if (k != j) {
						assign_max(ans, sum - arr[i][j] * 4 + sumv[j] + sumh[i] - arr[i][k] * 4 + sumv[k] + sumh[i]);
					}
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll k = 0; k < n; k++) {
					if (k != i) {
						assign_max(ans, sum - arr[i][j] * 4 + sumv[j] + sumh[i] - arr[k][j] * 4 + sumv[j] + sumh[k]);
					}
				}
			}
		}
		vector<vector<ll>> pref(n, vector<ll>(m + 1, -INF)), suff(n, vector<ll>(m + 1, -INF));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				pref[i][j + 1] = pref[i][j];
				assign_max(pref[i][j + 1], -arr[i][j] * 3 + sumv[j] + sumh[i]);
			}
			for (ll j = m - 1; j >= 0; j--) {
				suff[i][j] = suff[i][j + 1];
				assign_max(suff[i][j], -arr[i][j] * 3 + sumv[j] + sumh[i]);
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll k = 0; k < n; k++) {
					if (k != i) {
						assign_max(ans, sum - arr[i][j] * 3 + sumv[j] + sumh[i] + max(pref[k][j], suff[k][j + 1]));
					}
				}
			}
		}
		cout << ans;
		return 0;
	}
	if (k == 3) {
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll k = 0; k < m; k++) {
					if (k != j) {
						assign_max(ans, sum - arr[i][j] * 4 + sumv[j] + sumh[i] - arr[i][k] * 4 + sumv[k] + sumh[i]);
					}
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll k = 0; k < n; k++) {
					if (k != i) {
						assign_max(ans, sum - arr[i][j] * 4 + sumv[j] + sumh[i] - arr[k][j] * 4 + sumv[j] + sumh[k]);
					}
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll k = 0; k < n; k++) {
					for (ll l = 0; l < m; l++) {
						if (k != i) {
							if (j != l) {
								assign_max(ans, sum - arr[i][j] * 3 + sumv[j] + sumh[i] - arr[k][l] * 3 + sumv[l] + sumh[k]);
							}
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
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
