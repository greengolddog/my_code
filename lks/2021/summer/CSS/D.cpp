#include <bits/stdc++.h>
#define mt make_tuple
typedef long long ll;

using namespace std;

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

const ll INF = 1'000'000'000'000'000;

void get_ans(ll u, ll v, vector<ll>& ans, vector<vector<ll>>& pred, vector<vector<ll>>& ma) {
	if (pred[u][v] == -1) {
		ans.push_back(ma[u][v]);
		return;
	}
	get_ans(u, pred[u][v], ans, pred, ma);
	get_ans(pred[u][v], v, ans, pred, ma);
}

int main() {
	freopen("floyd.in", "r", stdin);
	freopen("floyd.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<tuple<ll, ll, ll, ll>> arr;
	for (ll i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		arr.push_back(mt(u, v, -c, i + 1));
	}
	vector<ll> con(k, 0);
	vector<vector<ll>> to(n);
	for (ll i = 0; i < k; i++) {
		cin >> con[i];
		con[i]--;
		if (i != 0) {
			to[con[i - 1]].push_back(con[i]);
		}
	}
	for (ll j = 0; j < n; j++) {
		vector<ll> dist(n, INF);
		dist[j] = 0;
		for (ll i = 0; i < n; i++) {
			for (auto[u, v, c, _] : arr) {
				assign_min(dist[v], dist[u] + c);
			}
		}
		vector<ll> old_dist = dist;
		for (ll i = 0; i < n; i++) {
			for (auto[u, v, c, _] : arr) {
				assign_min(dist[v], dist[u] + c);
			}
		}
		for (auto i : to[j]) {
			if (dist[i] != old_dist[i]) {
				cout << "infinitely kind";
				return 0;
			}
		}
	}
	vector<vector<ll>> p_dist(n + 1, vector<ll>(n + 1, INF)), pred(n + 1, vector<ll>(n + 1, -1)), ma(n + 1, vector<ll>(n + 1, -1));
	for (ll i = 0; i <= n; i++) {
		assign_min(p_dist[i][i], 0ll);
	}
	for (auto[u, v, c, i] : arr) {
		if (assign_min(p_dist[u][v], c)) {
			ma[u][v] = i;
		}
	}
	for (ll k = 0; k < n; k++) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (assign_min(p_dist[i][j], p_dist[i][k] + p_dist[k][j])) {
					pred[i][j] = k;
				}
			}
		}
	}
	vector<ll> ans;
	for (ll i = 1; i < k; i++) {
		get_ans(con[i - 1], con[i], ans, pred, ma);
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
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
