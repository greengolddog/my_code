#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs_match(ll u, vector<bool>& used, vector<ll>& match, vector<vector<ll>>& arr, ll a) {
	if (used[u]) {
		return false;
	}
	used[u] = true;
	for (auto v : arr[u]) {
		if (match[v - a] == -1 || dfs_match(match[v - a], used, match, arr, a)) {
			match[v - a] = u;
			return true;
		}
	}
	return false;
}

void dfs_used(ll u, vector<bool>& used, vector<vector<ll>>& arr) {
	used[u] = true;
	for (auto v : arr[u]) {
		if (!used[v]) {
			dfs_used(v, used, arr);
		}
	}
}

int main() {
	freopen("birthday.in", "r", stdin);
	freopen("birthday.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll a, b;
		cin >> a >> b;
		vector<vector<ll>> arr(a + b, vector<ll>(0, 0));
		set<pair<ll, ll>> inverse;
		for (ll i = 0; i < a; i++) {
			for (ll j = 0; j < b; j++) {
				inverse.insert({i, j + a});
				inverse.insert({j + a, i});
			}
		}
		for (ll i = 0; i < a; i++) {
			ll u;
			cin >> u;
			while (u != 0) {
				u--;
				inverse.erase({i, u + a});
				inverse.erase({u + a, i});
				cin >> u;
			}
		}
		for (auto[a, b] : inverse) {
			arr[a].push_back(b);
		}
		vector<ll> match(b, -1);
		vector<bool> used(a, false);
		for (ll i = 0; i < a; i++) {
			if (dfs_match(i, used, match, arr, a)) {
				used.clear();
				used.resize(a + b, false);
			}
		}
		set<pair<ll, ll>> s;
		for (ll i = 0; i < a + b; i++) {
			for (auto j : arr[i]) {
				s.insert({min(i, j), max(i, j)});
			}
		}
		for (ll i = 0; i < b; i++) {
			if (match[i] != -1) {
				s.insert({a + i, match[i]});
				s.erase({match[i], a + i});
			}
		}
		vector<vector<ll>> new_arr(a + b, vector<ll>(0, 0));
		for (auto[u, v] : s) {
			new_arr[u].push_back(v);
		}
		set<ll> s1;
		for (ll i = 0; i < a; i++) {
			s1.insert(i);
		}
		for (ll i = 0; i < b; i++) {
			if (match[i] != -1) {
				s1.erase(match[i]);
			}
		}
		used.clear();
		used.resize(a + b, false);
		for (auto i : s1) {
			dfs_used(i, used, new_arr);
		}
		ll cnt1 = 0, cnt2 = 0;
		for (ll i = 0; i < a; i++) {
			if (used[i]) {
				cnt1++;
			}
		}
		for (ll i = a; i < a + b; i++) {
			if (!used[i]) {
				cnt2++;
			}
		}
		cout << cnt1 + cnt2 << '\n';
		cout << cnt1 << ' ' << cnt2 << '\n';
		for (ll i = 0; i < a; i++) {
			if (used[i]) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
		for (ll i = a; i < a + b; i++) {
			if (!used[i]) {
				cout << i - a + 1 << ' ';
			}
		}
		cout << '\n';
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
