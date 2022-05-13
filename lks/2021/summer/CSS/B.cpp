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

ll SCC(ll n, vector<vector<ll>>& arr, vector<ll>& color) {
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
	ll last = 0;
	for (auto i : tp) {
		if (color[i] == -1) {
			dfs(i, new_arr, color, last, used);
			last++;
		}
	}
	return last;
}

int main() {
	freopen("2sat.in", "r", stdin);
	freopen("2sat.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	while (cin >> n) {
		cin >> m;
		vector<vector<ll>> arr(n * 2, vector<ll>(0, 0));
		for (ll i = 0; i < m; i++) {
			ll u, p1, v, p2;
			cin >> u >> p1 >> v >> p2;
			arr[u * 2 + 1 - p1].push_back(v * 2 + p2);
			arr[v * 2 + 1 - p2].push_back(u * 2 + p1);
		}
		vector<ll> color(n * 2, -1);
		ll col = SCC(n * 2, arr, color);
		vector<vector<ll>> a(col, vector<ll>(0, 0));
		for (ll i = 0; i < n * 2; i++) {
			a[color[i]].push_back(i);
		}
		vector<ll> ans(n, -1);
		set<pair<ll, ll>> s;
		for (ll i = 0; i < n * 2; i++) {
			for (auto j : arr[i]) {
				if (color[i] != color[j]) {
					s.insert({color[i], color[j]});
				}
			}
		}
		arr.clear();
		arr.resize(col, vector<ll>(0, 0));
		for (auto[u, v] : s) {
			arr[v].push_back(u);
		}
		vector<ll> used(col, -1);
		vector<ll> ts;
		for (ll i = 0; i < col; i++) {
			if (used[i] == -1) {
				topsort(i, arr, ts, used, 0);
			}
		}
		reverse(ts.begin(), ts.end());
		for (auto i : ts) {
			ll now = 0;
			for (auto j : a[i]) {
				if (ans[j / 2] != -1) {
					now = 1 - ans[j / 2];
					break;
				}
			}
			for (auto j : a[i]) {
				if (ans[j / 2] == -1) {
					ans[j / 2] = now;
				} else {
					if (j % 2 == 0) {
						ans[j / 2] = now;
					}
				}
			}
		}
		for (auto i : ans) {
			cout << i;
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
