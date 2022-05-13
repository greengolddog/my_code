#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;
const double eps = 1e-8;

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
	freopen("inverse.in", "r", stdin);
	freopen("inverse.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<long double>> m(n, vector<long double>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	vector<vector<long double>> a(n, vector<long double>(n));
	for (ll l = 0; l < n; l++) {
		vector<vector<long double>> arr(n);
		vector<long double> ans(n, 0);
		ans[l] = 1;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				arr[i].push_back(m[i][j]);
			}
		}
		ll r = 0;
		for (ll i = 0; i < n; i++) {
			ll j = r;
			for (; j < n; j++) {
				if (abs(arr[j][i]) >= eps) {
					swap(arr[r], arr[j]);
					swap(ans[r], ans[j]);
					break;
				}
			}
			if (j == n) {
				continue;
			}
			for (ll j = 0; j < n; j++) {
				if (j != i) {
					arr[r][j] /= arr[r][i];
				}
			}
			ans[r] /= arr[r][i];
			arr[r][i] = 1;
			for (ll j = r + 1; j < n; j++) {
				ans[j] -= arr[j][i] * ans[r];
				for (ll k = 0; k < n; k++) {
					if (k != i) {
						arr[j][k] -= arr[j][i] * arr[r][k];
					}
				}
				arr[j][i] = 0;
			}
			r++;
		}
		if (r != n) {
			cout << "NO";
			return 0;
		}
		for (ll i = n - 1; i >= 0; i--) {
			for (ll j = i - 1; j >= 0; j--) {
				ans[j] -= arr[j][i] * ans[i];
				for (ll k = 0; k < n; k++) {
					if (k != i) {
						arr[j][k] -= arr[j][i] * arr[i][k];
					}
				}
				arr[j][i] = 0;
			}
		}
		for (ll i = 0; i < n; i++) {
			a[i][l] = ans[i];
		}
	}
	cout << "YES" << '\n';
	for (auto i : a) {
		for (auto j : i) {
			cout << setprecision(30) << j << ' ';
		}
		cout << '\n';
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
