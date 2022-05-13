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

bool cmp(edge *a, edge *b) {
	return a->c > b->c;
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

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<edge*>> arr(n);
	ll mc = 0;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		assign_max(mc, c);
		arr[a].push_back(new edge(a, b, c, nullptr));
		arr[b].push_back(new edge(b, a, 0, arr[a].back()));
		arr[a].back()->i = arr[b].back();
	}
	//for (auto& i : arr) {
	//	shuffle(i.begin(), i.end(), rnd64);
	//}
	ll ans = 0;
	for (ll i = (1 << 30); i > 0; i /= 2) {
		while (find_flow(n, arr, ans, i)) {}
	}
	cout << ans << '\n';
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
