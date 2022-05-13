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

bool find_flow(vector<vector<ll>>& c, vector<vector<ll>>& arr, ll& ans, ll minc = 1) {
	vector<ll> dist(arr.size(), INF), p(arr.size(), -1);
	dist[0] = 0;
	queue<ll> q;
	vector<bool> used(arr.size(), 0);
	q.push(0);
	while (!q.empty()) {
		ll i = q.front();
		q.pop();
		for (auto a : arr[i]) {
			if (!used[a] && c[i][a] >= minc) {
				used[a] = true;
				dist[a] = dist[i] + 1;
				q.push(a);
				p[a] = i;
			}
		}
	}
	if (dist.back() == INF) {
		return false;
	}
	ll m = INF;
	ll now = arr.size() - 1;
	while (now != 0) {
		assign_min(m, c[p[now]][now]);
		now = p[now];
	}
	ans += m;
	now = arr.size() - 1;
	while (now != 0) {
		c[p[now]][now] -= m;
		c[now][p[now]] += m;
		now = p[now];
	}
	return true;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> c(n, vector<ll>(n, 0));
	vector<vector<ll>> arr(n);
	ll mc = 0;
	for (ll i = 0; i < m; i++) {
		ll a, b, cc;
		cin >> a >> b >> cc;
		a--;
		b--;
		c[a][b] = cc;
		arr[a].push_back(b);
		arr[b].push_back(a);
		assign_max(mc, cc);
	}
	for (auto& i : arr) {
		//shuffle(i.begin(), i.end(), rnd64);
	}
	ll ans = 0;
	ll log = 5;
	for (ll i = mc; i > 0; i /= 2) {
		while (find_flow(c, arr, ans, i)) {}
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
