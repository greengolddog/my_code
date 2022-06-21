#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, MAXLOG = 0;
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

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

struct edge {
	ll a, b, f;
	edge *i;
	edge(ll a, ll b, ll f, edge *i): a(a), b(b), f(f), i(i) {}
	void add(ll x) {
		f -= x;
		i->f += x;
	}
};

pair<edge*, edge*> make_edge(ll a, ll b, ll f) {
	edge *r1 = new edge(a, b, f, nullptr);
	edge *r2 = new edge(b, a, 0, r1);
	r1->i = r2;
	return make_pair(r1, r2);
}

bool bfs(vector<deque<edge*>>& arr, ll min_cost) {
	ll n = arr.size();
	vector<ll> dist(n, INF64);
	dist[0] = 0;
	queue<ll> q;
	q.push(0);
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (auto i : arr[x]) {
			if (i->f >= min_cost && assign_min(dist[i->b], dist[x] + 1)) {
				q.push(i->b);
			}
		}
	}
	if (dist.back() == INF64) {
		return false;
	}
	vector<deque<edge*>> narr(n);
	for (auto& i : arr) {
		for (auto j : i) {
			if (j->f >= min_cost && dist[j->a] < dist[j->b]) {
				narr[j->a].push_back(j);
			}
		}
	}
	arr = narr;
	return true;
}

bool dfs(ll v, vector<deque<edge*>>& arr, ll& x, ll last, ll min_cost) {
	if (v == last) {
		return true;
	}
	while (!arr[v].empty()) {
		edge *i = arr[v].front();
		ll ox = x;
		assign_min(x, i->f);
		if (dfs(i->b, arr, x, last, min_cost)) {
			i->add(x);
			if (i->f < min_cost) {
				arr[v].pop_front();
			}
			return true;
		}
		arr[v].pop_front();
		x = ox;
	}
	return false;
}

bool find_flow(vector<deque<edge*>> arr, ll min_cost, ll& ans) {
	ll n = arr.size();
	if (!bfs(arr, min_cost)) {
		return false;
	}
	ll x = INF64;
	while (dfs(0, arr, x, n - 1, min_cost)) {
		ans += x;
		x = INF64;
	}
	return true;
}

ll find_flow(vector<deque<edge*>>& arr) {
	ll ans = 0;
	for (ll i = (1 << MAXLOG); i > 0; i >>= 1) {
		while (find_flow(arr, i, ans)) {}
	}
	return ans;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n + 2, vector<ll>(m + 2, 0));
	ll sumc = 0, sumnc = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			char c;
			cin >> c;
			arr[i + 1][j + 1] = (c == 'H' ? 1 : (c == 'O' ? 2 : (c == 'N' ? 3 : (c == 'C' ? 4 : 0))));
			sumc += arr[i + 1][j + 1] * (1 - (i + j) % 2);
			sumnc += arr[i + 1][j + 1] * ((i + j) % 2);
		}
	}
	if (sumc == 0 || sumc != sumnc) {
		cout << "Invalid" << '\n';
		return;
	}
	vector<ll> go;
	go.push_back(-1);
	go.push_back(1);
	vector<deque<edge*>> r((n + 2) * (m + 2) + 2);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				continue;
			}
			if ((i + j) % 2 == 0) {
				auto[a, b] = make_edge(0, i * m + j + 1, arr[i][j]);
				r[0].push_back(a);
				r[i * m + j + 1].push_back(b);
				for (auto pi : go) {
					if (arr[i + pi][j] == 0) {
						continue;
					}
					auto[aa, bb] = make_edge(i * m + j + 1, (i + pi) * m + j + 1, 1);
					r[i * m + j + 1].push_back(aa);
					r[(i + pi) * m + j + 1].push_back(bb);
				}
				for (auto pj : go) {
					if (arr[i][j + pj] == 0) {
						continue;
					}
					auto[aa, bb] = make_edge(i * m + j + 1, i * m + j + pj + 1, 1);
					r[i * m + j + 1].push_back(aa);
					r[i * m + j + pj + 1].push_back(bb);
				}
			} else {
				auto[a, b] = make_edge(i * m + j + 1, r.size() - 1, arr[i][j]);
				r[i * m + j + 1].push_back(a);
				r.back().push_back(b);
			}
		}
	}
	cout << (find_flow(r) == sumc ? "Valid" : "Invalid");
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
