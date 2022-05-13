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

struct DSU {
	vector<ll> p, r;
	DSU(ll n) {
		p.resize(n, 0);
		r.resize(n, 1);
		for (ll i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	ll get(ll v) {
		return (p[v] == v ? v : p[v] = get(p[v]));
	}
	bool unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return false;
		}
		if (r[a] < r[b]) {
			swap(a, b);
		}
		p[b] = a;
		r[a] += r[b];
		return true;
	}
};

struct LCA {
	vector<vector<ll>> binup, mins, maxs;
	vector<ll> h;
	ll log = 20;
	LCA(vector<vector<pair<ll, ll>>>& arr) {
		ll n = arr.size();
		binup.resize(log, vector<ll>(n, 0));
		mins.resize(log, vector<ll>(n, 0));
		maxs.resize(log, vector<ll>(n, 0));
		h.resize(n, -1);
		for (ll i = 0; i < n; i++) {
			if (h[i] == -1) {
				dfs(i, i, -1, arr);
			}
			}
	}
	void dfs(ll v, ll p, ll c, vector<vector<pair<ll, ll>>>& arr) {
		h[v] = h[p] + 1;
		binup[0][v] = p;
		if (c != -1) {
			mins[0][v] = c;
			maxs[0][v] = c;
		} else {
			mins[0][v] = INF;
			maxs[0][v] = 0;
		}
		for (ll i = 1; i < log; i++) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
			mins[i][v] = min(mins[i - 1][v], mins[i - 1][binup[i - 1][v]]);
			maxs[i][v] = max(maxs[i - 1][v], maxs[i - 1][binup[i - 1][v]]);
		}
		for (auto[i, c] : arr[v]) {
			if (i != p) {
				dfs(i, v, c, arr);
			}
		}
	}
	pair<ll, ll> get(ll v, ll u) {
		ll nmin = INF, nmax = 0;
		if (h[v] < h[u]) {
			swap(u, v);
		}
		for (ll i = log - 1; i >= 0; i--) {
			if (h[binup[i][v]] >= h[u]) {
				assign_min(nmin, mins[i][v]);
				assign_max(nmax, maxs[i][v]);
				v = binup[i][v];
			}
		}
		if (u == v) {
			return make_pair(nmin, nmax);
		}
		for (ll i = log - 1; i >= 0; i--) {
			if (binup[i][v] != binup[i][u]) {
				assign_min(nmin, mins[i][v]);
				assign_max(nmax, maxs[i][v]);
				assign_min(nmin, mins[i][u]);
				assign_max(nmax, maxs[i][u]);
				u = binup[i][u];
				v = binup[i][v];
			}
		}
		ll i = 0;
		assign_min(nmin, mins[i][v]);
		assign_max(nmax, maxs[i][v]);
		assign_min(nmin, mins[i][u]);
		assign_max(nmax, maxs[i][u]);
		u = binup[i][u];
		v = binup[i][v];
		return make_pair(nmin, nmax);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, pair<ll, ll>>> all;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c = -c;
		all.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(all.begin(), all.end());
	DSU d(n);
	vector<pair<ll, pair<ll, ll>>> used, unused;
	for (ll i = 0; i < m; i++) {
		if (d.unite(all[i].second.first, all[i].second.second)) {
			used.push_back(all[i]);
		} else {
			unused.push_back(all[i]);
		}
	}
	vector<vector<pair<ll, ll>>> arr(n);
	for (auto[c, ab] : used) {
		arr[ab.first].push_back({ab.second, -c});
		arr[ab.second].push_back({ab.first, -c});
	}
	LCA l(arr);
	ll ans = 0;
	for (auto[c, ab] : unused) {
		auto[a, b] = ab;
		auto[nmin, nmax] = l.get(a, b);
		assign_min(nmin, -c);
		assign_max(nmax, -c);
		assign_max(ans, nmin + nmax);
	}
	cout << ans;
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
