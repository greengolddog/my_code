#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF32 = 2'000'000'000, MOD = 1'000'000'007;
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
	bool b() {
		if (q2.size() > q1.size()) {
			q1.push_back(q2.front());
			q2.pop_front();
			return true;
		}
		//if (q1.size() - q2.size() > 1) {
		//	q2.push_front(q1.back());
		//	q1.pop_back();
		//	return true;
		//}
		return false;
	}
	void balance() {
		while (b()) {}
	}
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
	ll pop_mid() {
		T x = q1.back();
		q1.pop_back();
		if (q2.size() > q1.size()) {
			q1.push_back(q2.front());
			q2.pop_front();
		}
		return x;
	}
	void random_shuffle() {
		vector<ll> arr;
		for (auto i : q1) {
			arr.push_back(i);
		}
		for (auto j : q2) {
			arr.push_back(j);
		}
		shuffle(arr.begin(), arr.end(), rnd32);
		for (auto& i : q1) {
			i = arr.back();
			arr.pop_back();
		}
		for (auto& i : q2) {
			i = arr.back();
			arr.pop_back();
		}
	}
	bool empty() {
		return q1.empty() && q2.empty();
	}
};

bool find_flow(ll n, vector<vector<edge*>>& arr, ll& ans) {
	vector<ll> dist(n, INF32);
	vector<edge*> p(n, nullptr);
	midqueue<ll> q;
	vector<bool> be(n, false);
	dist[0] = 0;
	q.push(0);
	be[0] = true;
	ll col = 0, cc = 0;
	while (!q.empty()) {
		col++;
		ll x = (rnd32() % 2 ? q.pop() : q.pop_mid());
		be[x] = false;
		for (auto i : arr[x]) {
			cc++;
			ll b = i->b;
			if (i->f != 0 && assign_min(dist[b], dist[x] + i->c)) {
				p[b] = i;
				if (!be[b]) {
					if (rnd32() % 2) {
						q.push(b);
					} else {
						q.push_mid(b);
					}
					be[b] = true;
				}
			}
		}
		if (cc % (n * 5) == 0) {
			q.random_shuffle();
		}
	}
	//if (cc > n * n * 50) {
	//	exit(1);
	//}
	if (p.back() == nullptr) {
		return false;
	}
	ll now = n - 1;
	while (now != 0) {
		p[now]->add(1);
		ans += p[now]->c;
		now = p[now]->a;
	}
	return true;
}

void solve() {
	ll n;
	cin >> n;
	ll col = n * 2 + 2;
	vector<vector<edge*>> arr(col);
	for (ll i = 1; i <= n; i++) {
		arr[0].push_back(new edge(0, i, 0, 1, nullptr));
		arr[i].push_back(new edge(i, 0, 0, 0, arr[0].back()));
		arr[0].back()->i = arr[i].back();
	}
	for (ll i = n + 1; i < col - 1; i++) {
		arr.back().push_back(new edge(col - 1, i, 0, 0, nullptr));
		arr[i].push_back(new edge(i, col - 1, 0, 1, arr.back().back()));
		arr.back().back()->i = arr[i].back();
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = n + 1; j < col - 1; j++) {
			ll c;
			cin >> c;
			arr[i].push_back(new edge(i, j, c, 1, nullptr));
			arr[j].push_back(new edge(j, i, -c, 0, arr[i].back()));
			arr[i].back()->i = arr[j].back();
		}
	}
	for (ll i = 0; i < col; i++) {
		shuffle(arr[i].begin(), arr[i].end(), rnd32);
	}
	ll ans = 0;
	while (find_flow(col, arr, ans)) {}
	cout << ans << '\n';
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < arr[i].size(); j++) {
			if (arr[i][j]->b != 0 && arr[i][j]->f == 0) {
				cout << i << ' ' << arr[i][j]->b - n << '\n';
			}
		}
	}
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
