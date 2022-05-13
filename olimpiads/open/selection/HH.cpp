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
	vector<pair<ll, ll>> ans(1, make_pair(0, 1));
	if (n % 2 == 1) {
		ans.emplace_back(1, 10);
	}
	n /= 2;
	//ans.emplace_back(0, 1);
	//if (n % 2 == 1) {
	//	ans.emplace_back(1, 10);
	//}
	//n /= 2;
	//ans.emplace_back(0, 1);
	//ans.emplace_back(0, 1);
	//if (n % 2 == 1) {
	//	ans.emplace_back(1, 10);
	//}
	//n /= 2;
	ll now = 2;
	while (n > 0) {
		ans.emplace_back(1, now);
		if (n % 2 == 1) {
			ans.emplace_back(1, 10);
		}
		n /= 2;
		if (n == 0) {
			break;
		}
		if (n == 1) {
			ans.emplace_back(1, 10);
			ans.emplace_back(1, 10);
			break;
		}
		ans.emplace_back(1, now);
		ans.emplace_back(1, now);
		if (n % 2 == 1) {
			ans.emplace_back(1, 10);
		}
		n /= 2;
		now++;
	}
	//n *= 2;
	//while (n > 0) {
	//	ans.emplace_back(1, 10);
	//	n--;
	//}
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
		if (ans.size() > 40) {
			return 1;
		}
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
