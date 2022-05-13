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

struct edge {
	ll a, b, f, c, rev;
};

bool dfs(ll v, vector<bool>& used, vector<edge>& e, vector<vector<ll>>& arr, ll f, ll& x) {
	used[v] = true;
	for (auto i : arr[v]) {
		if (!used[e[i].b]) {
			ll nx = min(x, e[i].c - e[i].f);
			if (e[i].f != e[i].c && (e[i].b == f || dfs(e[i].b, used, e, arr, f, nx))) {
				e[i].f += nx;
				e[e[i].rev].f -= nx;
				x = nx;
				return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, s = 0, f;
	cin >> n >> m;
	f = n - 1;
	vector<vector<ll>> arr(n);
	vector<edge> e;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		ll c;
		cin >> c;
		e.push_back({a, b, 0, c, 2 * i + 1});
		e.push_back({b, a, 0, c, 2 * i});
		arr[a].push_back(i * 2);
		arr[b].push_back(i * 2 + 1);
	}
	vector<bool> used(n, false);
	ll ans = 0;
	ll x = INF;
	while (dfs(s, used, e, arr, f, x)) {
		used.clear();
		used.resize(n, false);
		ans += x;
		x = INF;
	}
	cout << ans << '\n';
	for (ll i = 0; i < m; i++) {
		cout << e[i * 2].f << '\n';
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
