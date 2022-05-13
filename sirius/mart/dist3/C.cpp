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

void dfs(ll v, ll c, vector<ll>& color, vector<vector<ll>>& arr) {
	color[v] = c;
	for (auto i : arr[v]) {
		if (color[i] == -1) {
			dfs(i, c, color, arr);
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	vector<pair<ll, ll>> all;
	vector<bool> be;
	vector<bool> cs(n, false);
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			if (arr[i].first == arr[j].first) {
				cs[i] = true;
				cs[j] = true;
				all.emplace_back(i, j);
				be.push_back(true);
			}
			if (arr[i].second == arr[j].second) {
				cs[i] = true;
				cs[j] = true;
				all.emplace_back(i, j);
				be.push_back(false);
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		if (!cs[i]) {
			cout << "NE";
			return 0;
		}
	}
	vector<vector<ll>> g(all.size());
	for (ll i = 0; i < all.size(); i++) {
		for (ll j = 0; j < all.size(); j++) {
			if (!be[i] && be[j]) {
				if (arr[all[i].first].first <= arr[all[j].first].first && arr[all[j].first].first <= arr[all[i].second].first && arr[all[i].first].second >= arr[all[j].first].second && arr[all[i].first].second <= arr[all[j].second].second) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
	}
	vector<ll> color(all.size(), -1);
	ll last = 0;
	for (ll i = 0; i < n; i++) {
		if (color[i] == -1) {
			dfs(i, last, color, g);
			last++;
		}
	}
	vector<pair<ll, ll>> ans;
	for (ll j = 0; j < last; j++) {
		vector<bool> can(n, false), used(n, false);
		for (ll k = 0; k < all.size(); k++) {
			if (color[k] == j) {
				can[all[k].first] = true;
				can[all[k].second] = true;
			}
		}
		for (ll k = 0; k < all.size(); k++) {
			if (color[k] == j) {
				if (be[k]) {
					used[all[k].first] = true;
					used[all[k].second] = true;
				}
			}
		}
		bool b = true;
		for (ll k = 0; k < n; k++) {
			if (can[k] && !used[k]) {
				b = false;
				break;
			}
		}
		if (b) {
			for (ll k = 0; k < all.size(); k++) {
				if (color[k] == j) {
					if (be[k]) {
						ans.emplace_back(all[k].first, all[k].second);
					}
				}
			}
			continue;
		}
		used.clear();
		used.resize(n, false);
		for (ll k = 0; k < all.size(); k++) {
			if (color[k] == j) {
				if (!be[k]) {
					used[all[k].first] = true;
					used[all[k].second] = true;
				}
			}
		}
		b = true;
		for (ll k = 0; k < n; k++) {
			if (can[k] && !used[k]) {
				b = false;
				break;
			}
		}
		if (b) {
			for (ll k = 0; k < all.size(); k++) {
				if (color[k] == j) {
					if (!be[k]) {
						ans.emplace_back(all[k].first, all[k].second);
					}
				}
			}
			continue;
		}
		cout << "NE";
		return 0;
	}
	cout << "DA\n";
	for (auto[a, b] : ans) {
		cout << a + 1 << ' ' << b + 1 << '\n';
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
