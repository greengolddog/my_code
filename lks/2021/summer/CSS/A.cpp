#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void topsort(ll v, vector<vector<ll>>& arr, vector<ll>& ans, vector<ll>& used, ll col) {
	used[v] = col;
	for (auto i : arr[v]) {
		if (used[i] == -1) {
			topsort(i, arr, ans, used, col);
		}
	}
	ans.push_back(v);
}

void dfs(ll v, vector<vector<ll>>& arr, vector<ll>& color, ll now, vector<ll>& used) {
	color[v] = now;
	for (auto i : arr[v]) {
		if ((color[i] == -1) && (used[v] == used[i])) {
			dfs(i, arr, color, now, used);
		}
	}
}

void CSC(ll n, vector<vector<ll>>& arr, vector<ll>& color) {
	vector<ll> tp;
	vector<ll> used(n, -1);
	ll next = 1;
	for (ll i = 0; i < n; i++) {
		if (used[i] == -1) {
			topsort(i, arr, tp, used, next);
			next++;
		}
	}
	reverse(tp.begin(), tp.end());
	vector<vector<ll>> new_arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < n; i++) {
		for (auto v : arr[i]) {
			new_arr[v].push_back(i);
		}
	}
	ll last = 1;
	for (auto i : tp) {
		if (color[i] == -1) {
			dfs(i, new_arr, color, last, used);
			last++;
		}
	}
}

int main() {
	freopen("condense2.in", "r", stdin);
	freopen("condense2.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
	}
	vector<ll> color(n, -1);
	CSC(n, arr, color);
	set<pair<ll, ll>> s;
	for (ll i = 0; i < n; i++) {
		for (auto j : arr[i]) {
			if (color[i] != color[j]) {
				s.insert(make_pair(color[i], color[j]));
			}
		}
	}
	cout << s.size();
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
