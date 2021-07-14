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

void tops(ll v, vector<vector<ll>>& arr, vector<ll>& ans, vector<bool>& used) {
	used[v] = true;
	for (auto i : arr[v]) {
		if (!used[i]) {
			tops(i, arr, ans, used);
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

ll CSC(ll n, vector<vector<ll>>& arr, vector<ll>& color) {
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const ll INF = 10000000000000000;
	ll n, m;
	cin >> n >> m;
	vector<tuple<ll, ll, ll>> all;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	vector<vector<pair<ll, ll>>> cost(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		all.push_back(tie(a, b, c));
		arr[a].push_back(b);
		cost[a].push_back({b, c});
	}
	vector<ll> color(n, -1);
	ll col = CSC(n, arr, color);
	set<tuple<ll, ll, ll>> s;
	vector<ll> maxx(col, 0), minn(col, INF);
	for (ll i = 0; i < n; i++) {
		for (auto[j, c] : cost[i]) {
			if (color[i] != color[j]) {
				s.insert(tie(color[i], color[j], c));
			} else {
				maxx[color[i]] = max(maxx[color[i]], c);
				minn[color[i]] = min(minn[color[i]], c);
			}
		}
	}
	arr.clear();
	arr.resize(col);
	cost.clear();
	cost.resize(col);
	ll ans = 0;
	for (auto[a, b, c] : s) {
		arr[a].push_back(b);
		cost[a].push_back({b, c});
	}
	vector<ll> tp;
	vector<bool> used(col, false);
	for (ll i = 0; i < col; i++) {
		if (!used[i]) {
			tops(i, arr, tp, used);
		}
	}
	reverse(tp.begin(), tp.end());
	for (auto i : tp) {
		for (auto[j, c] : cost[i]) {
			maxx[j] = max(maxx[j], max(maxx[i], c));
			minn[j] = min(minn[j], min(minn[i], c));
		}
	}
	for (auto[a, _, c] : all) {
		ans = max(ans, max(maxx[color[a]]-c, c-minn[color[a]]));
	}
	cout << ans;
}
