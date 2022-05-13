#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;
const double eps = 1e-14;

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
	ll k;
	cin >> k;
	ll n = k + 1;
	vector<vector<__float128>> arr(n, vector<__float128>(n));
	vector<__float128> ans(n, 0);
	__float128 x = 0;
	for (ll i = 1; i <= n; i++) {
		__float128 nn = 1;
		for (ll j = 0; j < k; j++) {
			nn *= i;
		}
		__float128 now = i;
		for (ll j = 1; j <= n; j++) {
			arr[i - 1][j - 1] = now;
			now *= i;
		}
		x += nn;
		ans[i - 1] = x;
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
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << setprecision(20) << (abs(i) <= eps ? 0 : (long double)i) << ' ';
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
