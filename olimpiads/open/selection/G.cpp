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

ll solve(ll n, string sti) {
	string st;
	vector<ll> c(1, 1);
	st.push_back(sti[0]);
	for (ll i = 1; i < n; i++) {
		if (sti[i] != sti[i - 1]) {
			st.push_back(sti[i]);
			c.push_back(1);
		} else {
			c.back()++;
		}
	}
	n = st.size();
	if (n == 1) {
		return 0;
	}
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) {
		arr[i] = st[i] - 'a';
	}
	vector<ll> prefc(1, 0), prefnc(1, 0);
	for (ll i = 0; i < n; i++) {
		if (i % 2 == 0) {
			prefc.push_back(prefc.back() + c[i]);
		} else {
			prefnc.push_back(prefnc.back() + c[i]);
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (i % 2 == 0) {
			ans += c[i] * (prefnc.back() - prefnc[i / 2]);
		} else {
			ans += c[i] * (prefc.back() - prefc[i / 2 + 1]);
		}
	}
	vector<ll> col(26, 0);
	set<ll> s;
	s.insert(arr[0]);
	s.insert(arr[1]);
	col[arr[0]]++;
	col[arr[1]]++;
	ll lc = 0, lnc = 0;
	for (ll i = 2; i < n; i++) {
		if (i > 2) {
			if (col[arr[i - 3]] == 1) {
				s.erase(arr[i - 3]);
			}
			col[arr[i - 3]]--;
		}
		if (col[arr[i]] == 0) {
			s.insert(arr[i]);
		}
		col[arr[i]]++;
		if (s.size() == 2) {
			if (i % 2 == 0) {
				ans += ((prefnc[i / 2 - 1] - prefnc[lc]) + c[i - 2]) * (((i / 2 + 1) == prefc.size() ? 0 : (prefc.back() - prefc[i / 2 + 1])) + c[i]);
				lc = i / 2;
			} else {
				ans += ((prefc[i / 2 - 1] - prefc[lnc]) + c[i - 2]) * (((i / 2 + 1) == prefnc.size() ? 0 : (prefnc.back() - prefnc[i / 2 + 1])) + c[i]);
				lnc = i / 2;
			}
		}
	}
	return ans;
}

ll smart(ll n, string s) {
	vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
	ll ans = 0;
	for (ll l = 2; l <= n; l++) {
		for (ll i = 0; i <= (n - l); i++) {
			ll j = i + l;
			for (ll k = i + 2; k < j; k++) {
				dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
			}
			if (!dp[i][j]) {
				set<char> se;
				for (ll k = i; k < j; k++) {
					se.insert(s[k]);
				}
				dp[i][j] = se.size() == 2;
			}
			ans += dp[i][j];
		}
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	bool b = false;
	if (b) {
		ll n;
		cin >> n;
		string sti;
		cin >> sti;
		if (n <= 500) {
			cout << smart(n, sti);
		} else {
			cout << solve(n, sti);
		}
	} else {
		while (true) {
			ll n = rnd() % 3 + 1;
			string s;
			//s.push_back((rnd() % 26) + 'a');
			//ll last = s[0] - 'a';
			for (ll i = 0; i < n; i++) {
				//ll x = rnd() % 26;
				//if (x >= last) {
				//	x++;
				//}
				//last = x;
				//s.push_back(x + 'a');
				s.push_back(rnd() % 26 + 'a');
			}
			if (smart(n, s) != solve(n, s)) {
				cout << n << '\n' << s << '\n';
				cout << smart(n, s) << '\n';
				cout << solve(n, s) << '\n';
				break;
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
