#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef int_fast64_t ll;

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
	long long n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> arr;
	arr.reserve(30'000'000);
	for (ll i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		x--;
		y--;
		vector<bool> fir, sec;
		while (x > 0) {
			if (x >= (1ll << (k - fir.size() - 1))) {
				x -= (1ll << (k - fir.size() - 1));
				fir.push_back(true);
			} else {
				x--;
				fir.push_back(false);
			}
		}
		while (y > 0) {
			if (y >= (1ll << (k - sec.size() - 1))) {
				y -= (1ll << (k - sec.size() - 1));
				sec.push_back(true);
			} else {
				y--;
				sec.push_back(false);
			}
		}
		if (fir.size() != sec.size()) {
			cout << "No";
			return 0;
		}
		ll now1 = 0, now2 = 0;
		for (ll i = 0; i < fir.size(); i++) {
			ll on1 = 0, on2 = 0;
			if (fir[i]) {
				on1 = now1 + 1;
				now1 += (1ll << (k - i - 1));
			} else {
				on1 = now1 + (1ll << (k - i - 1));
				now1++;
			}
			if (sec[i]) {
				on2 = now2 + 1;
				now2 += (1ll << (k - i - 1));
			} else {
				on2 = now2 + (1ll << (k - i - 1));
				now2++;
			}
			if (fir[i]) {
				arr.push_back(make_pair(on1, on2));
			} else {
				arr.push_back(make_pair(now1, now2));
			}
		}
	}
	sort(arr.begin(), arr.end());
	for (ll i = 1; i < arr.size(); i++) {
		if (arr[i].first == arr[i - 1].first && arr[i].second != arr[i - 1].second) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
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
