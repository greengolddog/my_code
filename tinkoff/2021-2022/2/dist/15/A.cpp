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

ll get(ll x) {
	return 3 - x;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<ll> s(n), f(n);
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
		s[i]--;
	}
	for (ll i = 0; i < n; i++) {
		cin >> f[i];
		f[i]--;
	}
	vector<vector<ll>> need(3, vector<ll>(3, 0)), have(3, vector<ll>(3, 0));
	bool b = true;
	ll x = s[0];
	for (ll i = 0; i < n; i++) {
		need[s[i]][f[i]]++;
		if (s[i] != x || f[i] != x) {
			b = false;
		}
	}
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		have[a][b]++;
	}
	for (ll i = 0; i < 3; i++) {
		for (ll j = 0; j < 3; j++) {
			if (i == j) {
				continue;
			}
			while (min(have[i][j], need[i][j]) > 0) {
				have[i][j]--;
				need[i][j]--;
			}
			while (min(min(have[i][get(i + j)], have[get(i + j)][j]), need[i][j]) > 0) {
				have[i][get(i + j)]--;
				have[get(i + j)][j]--;
				need[i][j]--;
			}
			if (need[i][j] != 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	swap(need, have);
	if (min(min(need[0][1], need[1][2]) , need[2][0]) > 0) {
		b = false;
		ll x = min(min(need[0][1], need[1][2]), need[2][0]);
		need[0][1] -= x;
		need[1][2] -= x;
		need[2][0] -= x;
	}
	if (min(min(need[1][0], need[2][1]) , need[0][2]) > 0) {
		b = false;
		ll x = min(min(need[1][0], need[2][1]), need[0][2]);
		need[1][0] -= x;
		need[2][1] -= x;
		need[0][2] -= x;
	}
	if (min(need[1][0], need[0][1]) > 0) {
		if (x != 2) {
			b = false;
		}
		ll x = min(need[1][0], need[0][1]);
		need[1][0] -= x;
		need[0][1] -= x;
	}
	if (min(need[1][2], need[2][1]) > 0) {
		if (x != 0) {
			b = false;
		}
		ll x = min(need[1][2], need[2][1]);
		need[1][2] -= x;
		need[2][1] -= x;
	}
	if (min(need[2][0], need[0][2]) > 0) {
		if (x != 1) {
			b = false;
		}
		ll x = min(need[2][0], need[0][2]);
		need[2][0] -= x;
		need[0][2] -= x;
	}
	for (ll i = 0; i < 3; i++) {
		for (ll j = 0; j < 3; j++) {
			if (need[i][j] != 0) {
				cout << "NO";
				return  0;
			}
		}
	}
	cout << "YES";
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
