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

ll sub(ll a, ll b, ll m) {
	if (a < b) {
		return a - b + m;
	}
	return a - b;
}

int main() {
	freopen("traflights.in", "r", stdin);
	freopen("traflights.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<ll>> arr(n * m, vector<ll>(n * m, 0));
	vector<ll> ans(n * m, 0);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			ans[i * m + j] = 3 - a[i][j];
			for (ll k = 0; k < m; k++) {
				arr[i * m + j][i * m + k] = 1;
			}
			for (ll k = 0; k < n; k++) {
				arr[i * m + j][k * m + j] = 1;
			}
		}
	}
	vector<ll> rev(3, 0);
	rev[2] = 2;
	rev[1] = 1;
	ll r = 0;
	for (ll i = 0; i < n * m; i++) {
		ll j = r;
		for (; j < n * m; j++) {
			if (arr[j][i] != 0) {
				swap(arr[r], arr[j]);
				swap(ans[r], ans[j]);
				break;
			}
		}
		if (j == n * m) {
			continue;
		}
		for (ll j = 0; j < n * m; j++) {
			if (j != i) {
				arr[r][j] *= rev[arr[r][i]];
				arr[r][j] %= 3;
			}
		}
		ans[r] *= rev[arr[r][i]];
		ans[r] %= 3;
		arr[r][i] = 1;
		for (ll j = r + 1; j < n * m; j++) {
			ans[j] = sub(ans[j], arr[j][i] * ans[i] % 3, 3);
			for (ll k = 0; k < n * m; k++) {
				if (k != i) {
					arr[j][k] = sub(arr[j][k], arr[j][i] * arr[i][k] % 3, 3);
				}
			}
			arr[j][i] = 0;
		}
		r++;
	}
	if (r != n * m) {
		return 1;
	}
	for (ll i = n * m - 1; i >= 0; i--) {
		for (ll j = i - 1; j >= 0; j--) {
			ans[j] = sub(ans[j], arr[j][i] * ans[i] % 3, 3);
			for (ll k = 0; k < n; k++) {
				if (k != i) {
					arr[j][k] = sub(arr[j][k], arr[j][i] * arr[i][k] % 3, 3);
				}
			}
			arr[j][i] = 0;
		}
	}
	ll aa = 0;
	for (auto i : ans) {
		aa += i;
	}
	cout << aa << '\n';
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			for (ll k = 0; k < ans[i * m + j]; k++) {
				cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
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
