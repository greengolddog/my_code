#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
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
	ll a, b, c, f;
	edge *i;
	edge(ll a, ll b, ll c, ll f, edge *i): a(a), b(b), c(c), f(f), i(i) {}
	void add(ll x) {
		f -= x;
		i->f += x;
	}
};

template<typename T>
struct midqueue {
	deque<T> q1, q2;
	midqueue() {}
	void push(T x) {
		q2.push_back(x);
		if (q2.size() > q1.size()) {
			q1.push_back(q2.front());
			q2.pop_front();
		}
	}
	T pop() {
		T x = q1.front();
		q1.pop_front();
		if (q2.size() > q1.size()) {
			q1.push_back(q2.front());
			q2.pop_front();
		}
		return x;
	}
	void push_mid(T x) {
		q2.push_front(x);
		if (q2.size() > q1.size()) {
			q1.push_back(q2.front());
			q2.pop_front();
		}
	}
	bool empty() {
		return q1.empty() && q2.empty();
	}
};

bool find_flow(ll n, vector<vector<edge*>>& arr, ll& ans) {
	vector<ll> dist(n, INF64);
	vector<edge*> p(n, nullptr);
	dist[0] = 0;
	vector<bool> be(n, false);
	midqueue<ll> mq;
	mq.push(0);
	while (!mq.empty()) {
		ll x = mq.pop();
		be[x] = false;
		for (auto i : arr[x]) {
			if (i->f != 0 && assign_min(dist[i->b], dist[i->a] + i->c)) {
				p[i->b] = i;
				if (!be[i->b]) {
					mq.push_mid(i->b);
					be[i->b] = true;
				}
			}
		}
	}
	if (p.back() == nullptr) {
		return false;
	}
	ll x = INF64, now = n - 1;
	while (now != 0) {
		assign_min(x, p[now]->f);
		now = p[now]->a;
	}
	ans += x * dist.back();
	now = n - 1;
	while (now != 0) {
		p[now]->add(x);
		now = p[now]->a;
	}
	return true;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<edge*>> arr(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, f, c;
		cin >> a >> b >> f >> c;
		a--;
		b--;
		arr[a].push_back(new edge(a, b, c, f, nullptr));
		arr[b].push_back(new edge(b, a, -c, 0, arr[a].back()));
		arr[a].back()->i = arr[b].back();
	}
	ll ans = 0;
	while (find_flow(n, arr, ans)) {}
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
