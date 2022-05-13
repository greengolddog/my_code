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
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	ll c = 0;
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < m - 1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	cout << c << ' ';
	c = 0;
	for (ll i = 0; i < n - 3; i++) {
		for (ll j = 0; j < m; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j] && arr[i][j] == arr[i + 3][j] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m - 3; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	cout << c << ' ';
	c = 0;
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 1; j < m - 1; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j - 1] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	for (ll i = 1; i < n - 1; i++) {
		for (ll j = 0; j < m - 1; j++) {
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	cout << c << ' ';
	c = 0;
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < m - 2; j++) {
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 1][j + 2] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	for (ll i = 1; i < n - 1; i++) {
		for (ll j = 0; j < m - 1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i - 1][j + 1] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	cout << c << ' ';
	c = 0;
	for (ll i = 1; i < n - 1; i++) {
		for (ll j = 0; j < m - 1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i - 1][j] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 1; j < m - 1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j - 1] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j < m - 1; j++) {
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i][j + 1] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	for (ll i = 1; i < n - 1; i++) {
		for (ll j = 1; j < m; j++) {
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i + 1][j] && arr[i][j] != '.') {
				c++;
			}
		}
	}
	cout << c;
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
