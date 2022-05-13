#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

struct LCA {
	vector<vector<ll>> binup, binupm1, cost;
	map<pair<ll, ll>, bool> m;
	vector<ll> h;
	ll size, MAXLN = 20;
	LCA(vector<vector<pair<ll, bool>>>& arr) {
		size = arr.size();
		for (ll i = 0; i < arr.size(); i++) {
			for (auto[j, c] : arr[i]) {
				m[{i, j}] = c;
			}
		}
		binup.resize(MAXLN, vector<ll>(size, 0));
		binupm1.resize(MAXLN, vector<ll>(size, 0));
		cost.resize(MAXLN, vector<ll>(size, 0));
		h.resize(size, -1);
		dfs(0, 0, arr);
	}
	private:
	void dfs(ll v, ll p, vector<vector<pair<ll, bool>>>& arr) {
		h[v] = h[p] + 1;
		binup[0][v] = p;
		binupm1[0][v] = v;
		for (ll i = 1; i < MAXLN; i++) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
			binupm1[i][v] = binupm1[i - 1][binup[i - 1][v]];
			cost[i][v] = cost[i - 1][v] + cost[i - 1][binup[i - 1][v]] + (binup[i - 1][v] != 0 && m[{binupm1[i - 1][v], binup[i - 1][v]}] != m[{binup[i - 1][v], binup[0][binup[i - 1][v]]}]);
		}
		for (auto[i, _] : arr[v]) {
			if (i != p) {
				dfs(i, v, arr);
			}
		}
	}
	public:
	ll get(ll u, ll v) {
		if (u == v) {
			return 0;
		}
		if (h[u] < h[v]) {
			swap(u, v);
		}
		ll ans = 0, pred = -1;
		if (h[u] != h[v]) {
			for (ll i = MAXLN - 1; i >= 0; i--) {
				if (h[binupm1[i][u]] > h[v]) {
					if (pred != -1) {
						ans += (u != 0 && m[{pred, u}] != m[{u, binup[0][u]}]);
					}
					ans += cost[i][u];
					pred = binupm1[i][u];
					u = binup[i][u];
				}
			}
			if (u == v) {
				return ans;
			}
		}
		ll predu = pred, predv = -1;
		for (ll i = MAXLN - 1; i >= 0; i--) {
			if (binupm1[i][u] != binupm1[i][v]) {
				if (predu != -1) {
					ans += (u != 0 && m[{predu, u}] != m[{u, binup[0][u]}]);
				}
				if (predv != -1) {
					ans += (v != 0 && m[{predv, v}] != m[{v, binup[0][v]}]);
				}
				ans += cost[i][u] + cost[i][v];
				predu = binupm1[i][u];
				predv = binupm1[i][v];
				u = binup[i][u];
				v = binup[i][v];
			}
		}
		ans += (m[{predu, u}] != m[{predv, v}]);
		return ans;
	}
};

int main() {
	freopen("turtles.in", "r", stdin);
	freopen("turtles.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll h, w;
	cin >> h >> w;
	vector<vector<bool>> arr(h + 2, vector<bool>(w + 2, false));
	map<pair<ll, ll>, ll> num;
	ll cnt = 0;
	vector<vector<pair<ll, bool>>> g;
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) {
			char c;
			cin >> c;
			if (c == '#') {
				arr[i][j] = true;
				num[{i, j}] = cnt;
				cnt++;
				g.push_back(vector<pair<ll, bool>>(0, {0, true}));
			}
		}
	}
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) {
			if (arr[i][j]) {
				if (arr[i - 1][j]) {
					g[num[{i, j}]].push_back({num[{i - 1, j}], true});
				}
				if (arr[i][j - 1]) {
					g[num[{i, j}]].push_back({num[{i, j - 1}], false});
				}
				if (arr[i + 1][j]) {
					g[num[{i, j}]].push_back({num[{i + 1, j}], true});
				}
				if (arr[i][j + 1]) {
					g[num[{i, j}]].push_back({num[{i, j + 1}], false});
				}
			}
		}
	}
	LCA l(g);
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << l.get(num[{x1, y1}], num[{x2, y2}]) << '\n';
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
