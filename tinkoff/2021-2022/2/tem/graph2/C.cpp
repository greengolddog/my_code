#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

struct edge {
	ll a, b, c;
	edge *i;
	edge(ll a, ll b, ll c, edge *i): a(a), b(b), c(c), i(i) {}
};

bool find_layered_network(ll n, vector<vector<edge*>>& arr, ll x = 1) {
	vector<ll> dist(n, INF);
	dist[0] = 0;
	queue<ll> q;
	q.push(0);
	vector<bool> used(n, false);
	used[0] = true;
	while (!q.empty()) {
		ll i = q.front();
		q.pop();
		for (auto j : arr[i]) {
			if (!used[j->b] && j->c >= x) {
				used[j->b] = true;
				dist[j->b] = dist[i] + 1;
				q.push(j->b);
			}
		}
	}
	if (dist.back() == INF) {
		return false;
	}
	vector<vector<edge*>> narr(n);
	for (auto& i : arr) {
		for (auto j : i) {
			if (dist[j->a] == dist[j->b] - 1) {
				narr[j->a].push_back(j);
			}
		}
	}
	arr = narr;
	return true;
}

bool flow(ll v, ll n, vector<vector<edge*>>& arr, ll& now, ll x = 1) {
	if (v == n - 1) {
		return true;
	}
	ll save = now;
	while (!arr[v].empty()) {
		//if (arr[v].back()->c < x) {
		//	break;
		//}
		assign_min(now, arr[v].back()->c);
		if (!flow(arr[v].back()->b, n, arr, now, x)) {
			arr[v].pop_back();
			now = save;
		} else {
			return true;
		}
	}
	return false;
}

bool find_flow(ll n, vector<vector<edge*>> arr, ll& ans, ll x = 1) {
	if (!find_layered_network(n, arr, x)) {
		return false;
	}
	ll now = INF;
	//for (auto& i : arr) {
	//	sort(i.begin(), i.end(), cmp);
	//}
	while (flow(0, n, arr, now)) {
		ans += now;
		ll x = 0;
		while (x != n - 1) {
			arr[x].back()->c -= now;
			arr[x].back()->i->c += now;
			ll nx = arr[x].back()->b;
			if (arr[x].back()->c == 0) {
				arr[x].pop_back();
			}
			x = nx;
		}
		now = INF;
	}
	return true;
}

bool check(ll n, ll m, ll c, vector<vector<ll>>& arr) {
	ll col = n + m + 2;
	vector<vector<edge*>> all(col);
	for (ll i = 1; i <= n; i++) {
		all[0].push_back(new edge(0, i, 1, nullptr));
		all[i].push_back(new edge(i, 0, 0, all[0].back()));
		all[0].back()->i = all[i].back();
	}
	col--;
	for (ll i = n + 1; i < col; i++) {
		all[i].push_back(new edge(i, col, 1, nullptr));
		all[col].push_back(new edge(col, i, 0, all[i].back()));
		all[i].back()->i = all[col].back();
	}
	col++;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (arr[i][j] >= c) {
				all[i + 1].push_back(new edge(i + 1, j + 1 + n, 1, nullptr));
				all[j + 1 + n].push_back(new edge(j + 1 + n, i + 1, 0, all[i + 1].back()));
				all[i + 1].back()->i = all[j + 1 + n].back();
			}
		}
	}
	ll ans = 0;
	while (find_flow(col, all, ans)) {}
	return ans == min(n, m);
}

void solve() {
	ll n, m;
	cin >> n >> m;
	ll mx = 0;
	vector<vector<ll>> arr(n, vector<ll>(m, 0));
	for (auto& i : arr) {
		for (auto& j : i) {
			cin >> j;
			assign_max(mx, j);
		}
	}
	ll l = 0, r = mx + 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check(n, m, mid, arr)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
