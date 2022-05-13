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

vector<pair<ll, ll>> solve(ll k, ll q, ll n) {
	ll on = n;
	vector<pair<ll, ll>> ans;
	vector<ll> pow(11, 0);
	ll ce = 0, cd = 1, ct = 2;
	for (ll i = 0; i < 9; i++) {
		pow[i] = n % 4;
		if (pow[i] == 2) {
			cd++;
		}
		if (pow[i] == 3) {
			ct++;
			ct++;
		}
		n /= 4;
	}
	bool ie = false, id = (ce >= ct), it = (ct > ce);
	reverse(pow.begin(), pow.end());
	bool b = false;
	for (ll i = 2; i <= 10; i++) {
		ans.emplace_back(1, i);
		ans.emplace_back(1, i);
		ans.emplace_back(1, i);
		if (pow[i] == 3) {
			if (it) {
				if (!b) {
					ans.emplace_back(0, 1);
					ans.emplace_back(0, 1);
					ans.emplace_back(0, 1);
					b = true;
				} else {
					ans.emplace_back(1, 2);
				}
			} else {
				ans.emplace_back(0, i);
				ans.emplace_back(0, i);
				ans.emplace_back(0, i);
			}
		}
		if (pow[i] == 2) {
			if (id) {
				if (!b) {
					ans.emplace_back(0, 1);
					ans.emplace_back(0, 1);
					b = true;
				} else {
					ans.emplace_back(1, 2);
				}
			} else {
				ans.emplace_back(0, i);
				ans.emplace_back(0, i);
			}
		}
		if (pow[i] == 1) {
			if (ie) {
				if (!b) {
					ans.emplace_back(0, 1);
					b = true;
				} else {
					ans.emplace_back(1, 2);
				}
			} else {
				ans.emplace_back(0, i);
			}
		}
	}
	ans.emplace_back(1, 10);
	if (ans.size()) {}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll k, q, t;
	cin >> k >> q >> t;
	for (ll i = 0; i < t; i++) {
		ll n;
		cin >> n;
		auto ans = solve(k, q, n);
		cout << ans.size() << '\n';
		//if (ans.size() > 40) {
		//	return 1;
		//}
		for (auto[a, b] : ans) {
			cout << a << ' ' << b << '\n';
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
