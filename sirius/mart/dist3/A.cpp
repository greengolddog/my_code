#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef int_fast64_t ll;

using namespace std;

const ll INF = 1'000'000'000;

mt19937 rnd(time(0));

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

ll sum(ll a, ll b, ll m) {
	if (a + b >= m) {
		return a + b - m;
	}
	return a + b;
}

ll sub(ll a, ll b, ll m) {
	if (a - b < 0) {
		return a - b + m;
	}
	return a - b;
}

ll col(string s, bool b) {
	vector<vector<vector<ll>>> dp(10, vector<vector<ll>>(10, vector<ll>(2, 0)));
	for (ll i = 0; i < 10; i++) {
		for (ll j = 1; j < (s[0] - '0'); j++) {
			dp[j][i][0] = 1;
		}
		dp[s[0] - '0'][i][1] = 1;
	}
	ll m = 10;
	for (ll a = 1; a < s.size(); a++) {
		char k = s[a];
		vector<vector<vector<ll>>> dp2(10, vector<vector<ll>>(10, vector<ll>(2, 0)));
		for (ll i = 0; i < 10; i++) {
			for (ll j = 0; j < 10; j++) {
				dp2[sum(i, j, m)][j][0] += dp[i][j][0];
			}
			for (ll j = 0; j < 10; j++) {
				if (sum(i, j, m) == (k - '0')) {
					dp2[sum(i, j, m)][j][1] += dp[i][j][1];
				}
				if (sum(i, j, m) < (k - '0')) {
					dp2[sum(i, j, m)][j][0] += dp[i][j][1];
				}
			}
			if (i != 0) {
				for (ll j = 0; j < 10; j++) {
					dp2[i][j][0]++;
				}
			}
		}
		dp = dp2;
	}
	ll sum = 0;
	for (ll i = 0; i < 10; i++) {
		for (ll j = 0; j < 10; j++) {
			if (dp[i][j][0] != 0 && j != 0 && i != 0) {
				dp[i][j][0]--;
			}
			if (b) {
				sum += dp[i][j][0] + dp[i][j][1];
			} else {
				sum += dp[i][j][0];
			}
		}
	}
	return sum;
}

ll solve(string l, string r) {
	if (r.size() == 1) {
		return (r[0] - '0') - (l[0] - '0') + 1;
	}
	return col(r, true) - col(l, false);
}

bool is_a(ll x) {
	ll a = 0;
	string sx = to_string(x);
	for (ll i = 0; i < sx.size() - 1; i++) {
		if (i == 0) {
			a = sub(sx[i + 1] - '0', sx[i] - '0', 10);
		} else {
			if (sub(sx[i + 1] - '0', sx[i] - '0', 10) != a) {
				return false;
			}
		}
	}
	return true;
}

ll stupid(ll l, ll r) {
	ll ans = 0;
	for (ll i = l; i <= r; i++) {
		ans += is_a(i);
	}
	return ans;
}

pair<ll, ll> gen() {
	ll l = rnd() % 1'000'000 + 1, r = rnd() % 1'000'000 + 1;
	if (l > r) {
		return {r, l};
	} else {
		return {l, r};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//while (true) {
	//	auto[l, r] = gen();
	//	cout << l << ' ' << r << '\n';
	//	if (stupid(l, r) != solve(to_string(l), to_string(r))) {
	//		cout << l << ' ' << r << '\n';
	//		cout << stupid(l, r) << ' ' << solve(to_string(l), to_string(r)) << '\n';
	//		return 0;
	//	}
	//}
	string l, r;
	cin >> l >> r;
	cout << solve(l, r);
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
