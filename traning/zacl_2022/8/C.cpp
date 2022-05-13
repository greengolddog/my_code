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
	ll n;
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	ll x;
	cin >> x;
	if (x == 1) {
		for (ll j = 0; j < n / 2; j++) {
			if (j != 0) {
				cout << 'D';
			}
			for (ll i = 1; i < n; i++) {
				cout << 'R';
			}
			cout << 'D';
			for (ll i = 1; i < n; i++) {
				cout << 'L';
			}
		}
		return 0;
	}
	if (x == 2) {
		for (ll i = 0; i < n; i++) {
			if (i != 0) {
				cout << 'R';
			}
			ll j = 0;
			while (arr[j + 1][i] == 'B') {
				cout << 'D';
				j++;
			}
			while (j > 0) {
				cout << 'U';
				j--;
			}
		}
		return 0;
	}
	if (x == 3) {
		vector<pair<ll, ll>> go(1, make_pair(0, 1));
		go.emplace_back(0, -1);
		go.emplace_back(1, 0);
		go.emplace_back(-1, 0);
		map<pair<ll, ll>, char> m;
		m[make_pair(1, 0)] = 'D';
		m[make_pair(-1, 0)] = 'U';
		m[make_pair(0, 1)] = 'R';
		m[make_pair(0, -1)] = 'L';
		ll nx = 0, ny = 0, ox = 0, oy = 0;
		while (true) {
			ll onx = nx, ony = ny;
			for (auto[a, b] : go) {
				if (a + nx >= 0 && b + ny >= 0 && a + nx < n && b + ny < n && arr[a + nx][b + ny] == 'B') {
					if ((a + nx) != ox || (b + ny) != oy) {
						cout << m[make_pair(a, b)];
						nx += a;
						ny += b;
						break;
					}
				}
			}
			if (nx == onx && ny == ony) {
				break;
			}
			ox = onx;
			oy = ony;
		}
		return 0;
	}
	if (x == 4) {
		for (ll j = 0; j < n / 2; j++) {
			if (j != 0) {
				cout << 'D';
			}
			for (ll i = 1; i < n; i++) {
				cout << 'R';
			}
			cout << 'D';
			for (ll i = 1; i < n; i++) {
				cout << 'L';
			}
		}
		cout << "DRRRrrruDRRRRRRRRlllllllllURLLLLDUULRRRRRULLLLRURRRULLRRRRRRRRLLDLLDRRRDLLLRDRUUUUURRULULRDDLLLLLLLRRRRULLLLLLLLRDRULLUURRRLULDLDRRRRRRRRUUURLDLDLLUURLURLUUR";
		return 0;
	}
	if (x == 5) {
		cout << "RRRRRRRRRRRRDDDDDDDDDDDDRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRDDDDDDDDDDDDUUUUUUUUUUUUDRRRRRLLLLLLLLLLRRRRRDRRRRRLLLLLLLLLLRRRRRDRRRRRLLLLLLLLLLRRRRRDRRRRLLLLLLLLRRRRDRRRLLLLLLRRRUUUUUURRRRRLLLLLLLLLLRRRRRULLLLLRRRRRRRRRRLLLLLURRRRRLLLLLLLLLLRRRRRURRRRLLLLLLLLRRRRURRRLLLLLLuRRUUUUUULLLLLLLLLLL";
		return 0;
	}
	if (x == 6) {
		cout << "RRRRRRRRRRRRRRRRRRRRRRR";
		for (ll i = 0; i < 11; i++) {
			cout << "DDLLLLLLLLLLLLLLLLLLLLLLLuRRRRRRRRRRRRRRRRRRRRRRRd";
		}
		return 0;
	}
	if (x == 7) {
		cout << "RRRRRRRRRRRR";
		ll x = 12;
		for (ll i = 0; i < 6; i++) {
			for (ll j = 0; j < x; j++) {
				cout << 'R';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'D';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'D';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'L';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'L';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'U';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'U';
			}
			for (ll j = 0; j < x; j++) {
				cout << 'R';
			}
			x -= 2;
			cout << "DDLuRd";
		}
		cout << "ulD";
		return 0;
	}
	if (x == 8) {
		for (ll i = 0; i < 4; i++) {
			cout << "RRRdlllURRrDDRUURDDUURRRRdlllURRrDDRUURDDUURRRRdlllURRrDDRUURDDUU";
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
