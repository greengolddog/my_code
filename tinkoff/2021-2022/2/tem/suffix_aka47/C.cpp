#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, COLC = 26;
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

struct node {
	ll go[COLC];
	ll p, suf;
	node() {
		p = -1;
		suf = -1;
		for (ll i = 0; i < COLC; i++) {
			go[i] = -1;
		}
	}
};

struct suffix_aka47 {
	vector<node> arr;
	vector<ll> roots;
	vector<ll> dist, col;
	vector<bool> used;
	vector<ll> be;
	suffix_aka47() {
		arr.push_back(node());
	}
	void add_string(string s) {
		ll nr = roots.size();
		roots.push_back(0);
		for (auto i : s) {
			add(i, nr);
		}
	}
	void add(char c, ll root) {
		ll x = c - 'a';
		ll a = roots[root];
		ll b = arr.size();
		arr.push_back(node());
		arr[b].suf = 0;
		arr[b].p = a;
		for (; a != -1; a = arr[a].suf) {
			if (arr[a].go[x] == -1) {
				arr[a].go[x] = b;
				continue;
			}
			ll c = arr[a].go[x];
			if (arr[c].p == a) {
				arr[b].suf = c;
				break;
			}
			ll d = arr.size();
			arr.push_back(node());
			arr[d].suf = arr[c].suf;
			arr[d].p = a;
			arr[c].suf = d;
			arr[b].suf = d;
			for (ll i = 0; i < COLC; i++) {
				arr[d].go[i] = arr[c].go[i];
			}
			for (; a != -1 && arr[a].go[x] == c; a = arr[a].suf) {
				arr[a].go[x] = d;
			}
			break;
		}
		roots[root] = arr[roots[root]].go[x];
	}
	void end() {
		dist.resize(arr.size(), 0);
		col.resize(arr.size(), 0);
		for (ll i = 1; i < arr.size(); i++) {
			dist[i] = dist[arr[i].p] + 1;
		}
		used.resize(arr.size(), false);
		for (auto i : roots) {
			dfs(i);
			for (auto j : be) {
				used[j] = false;
			}
			be.clear();
		}
	}
	void dfs(ll v) {
		be.push_back(v);
		col[v]++;
		used[v] = true;
		if (arr[v].p != -1 && !used[arr[v].p]) {
			dfs(arr[v].p);
		}
		if (arr[v].suf != -1 && !used[arr[v].suf]) {
			dfs(arr[v].suf);
		}
	}
};

void solve() {
	ll n;
	cin >> n;
	suffix_aka47 sa;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		sa.add_string(s);
	}
	sa.end();
	vector<ll> ans(n + 1, 0);
	for (ll i = 0; i < sa.arr.size(); i++) {
		assign_max(ans[sa.col[i]], sa.dist[i]);
	}
	for (ll i = n - 1; i >= 0; i--) {
		assign_max(ans[i], ans[i + 1]);
	}
	for (ll i = 2; i <= n; i++) {
		cout << ans[i] << '\n';
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
