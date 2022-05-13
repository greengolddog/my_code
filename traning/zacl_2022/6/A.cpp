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

mt19937 rnd(time(0));

void solve() {
	ll h, w, n;
	cin >> h >> w >> n;
	ll on = n;
	vector<vector<char>> arr(h, vector<char>(w, '/'));
	char c = '/';
	for (ll i = 0; i < min(h, w); i++) {
		for (ll j = i; j < w; j++) {
			if (n == 0) {
				break;
			}
			if (i < 2) {
				if ((j - i) % 4 == 0) {
					arr[i][j] = 'I';
					if (j != i) {
						n--;
					}
				}
				if ((j - i) % 4 == 2) {
					arr[i][j] = 'O';
					n--;
				}
			} else {
				if (n == 1) {
					if (j + 2 < w) {
						if ((j - i) % 4 == 0) {
							arr[i][j] = 'O';
							arr[i][j + 2] = 'I';
						} else {
							arr[i][j] = 'I';
							arr[i][j + 2] = 'O';
						}
						n--;
					}
				} else {
					if ((j - i) % 4 == 0) {
						arr[i][j] = 'I';
						n--;
						n--;
					}
					if ((j - i) % 4 == 2) {
						arr[i][j] = 'O';
						n--;
						n--;
					}
				}
			}
		}
		for (ll j = i + 1; j < h; j++) {
			if (n == 0) {
				break;
			}
			if (i < 2) {
				if ((j - i) % 4 == 0) {
					arr[j][i] = 'I';
					if (j != i) {
						n--;
					}
				}
				if ((j - i) % 4 == 2) {
					arr[j][i] = 'O';
					n--;
				}
			} else {
				if (n == 1) {
					if (j + 2 < h) {
						if ((j - i) % 4 == 0) {
							arr[j][i] = 'O';
							arr[j + 2][i] = 'I';
						} else {
							arr[j][i] = 'I';
							arr[j + 2][i] = 'O';
						}
						n--;
					}
				} else {
					if ((j - i) % 4 == 0) {
						arr[j][i] = 'I';
						n--;
						n--;
					}
					if ((j - i) % 4 == 2) {
						arr[j][i] = 'O';
						n--;
						n--;
					}
				}
			}
		}
		if (n == 0) {
			break;
		}
		c = '/';
	}
	if (n == 0) {
		for (auto& i : arr) {
			for (auto j : i) {
				cout << j;
			}
			cout << '\n';
		}
	} else {
		bool b = false;
		for (ll _ = 0; _ < 10'000'000; _++) {
			for (auto& j : arr) {
				for (auto& k : j) {
					ll now = rnd() % 3;
					k = (now == 0 ? 'I' : (now == 1 ? '/' : 'O'));
				}
			}
			ll now = 0;
			for (ll i = 0; i < h; i++) {
				for (ll j = 0; j < w; j++) {
					if (arr[i][j] == 'I') {
						if (j + 2 < w) {
							now += (arr[i][j + 1] == '/') && (arr[i][j + 2] == 'O');
						}
						if (i + 2 < h) {
							now += (arr[i + 1][j] == '/') && (arr[i + 2][j] == 'O');
						}
						if ((j + 2) < w && (i + 2) < h) {
							now += (arr[i + 1][j + 1] == '/') && (arr[i + 2][j + 2] == 'O');
						}
					}
					if (arr[i][j] == 'O') {
						if (j + 2 < w) {
							now += (arr[i][j + 1] == '/') && (arr[i][j + 2] == 'I');
						}
						if (i + 2 < h) {
							now += (arr[i + 1][j] == '/') && (arr[i + 2][j] == 'I');
						}
						if ((j + 2) < w && (i + 2) < h) {
							now += (arr[i + 1][j + 1] == '/') && (arr[i + 2][j + 2] == 'I');
						}
					}
				}
			}
			if (now == on) {
				b = true;
				break;
			}
		}
		if (!b) {
			cout << "Impossible" << '\n';
		} else {
			for (auto& i : arr) {
				for (auto j : i) {
					cout << j;
				}
				cout << '\n';
			}
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
		cout << "===\n";
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
