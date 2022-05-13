#include <bits/stdc++.h>
typedef int ll;

using namespace std;

const ll INF = 2'000'000'000, mod = 1'000'000'007;
ll n;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct DSU {
	vector<ll> parent, sz;
	ll col;
	DSU(ll n) {
		col = n;
		parent.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			parent[i] = i;
		}
		sz.resize(n, 1);
	}
	ll get(ll x) {
		return (parent[x] == x ? x : parent[x] = get(parent[x]));
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		col--;
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		parent[b] = a;
		sz[a] += sz[b];
	}
};

struct LCA {
	vector<vector<ll>> binup;
	vector<ll> h;
	ll log = 1;
	LCA(vector<vector<ll>>& arr, ll root) {
		ll now = arr.size();
		while (now > 0) {
			log++;
			now /= 2;
		}
		binup.resize(arr.size(), vector<ll>(log + 1, 0));
		h.resize(arr.size(), -1);
		dfs(root, root, arr);
	}
	void dfs(ll v, ll p, vector<vector<ll>>& arr) {
		binup[v][0] = p;
		for (ll i = 1; i <= log; i++) {
			binup[v][i] = binup[binup[v][i - 1]][i - 1];
		}
		h[v] = h[p] + 1;
		for (auto i : arr[v]) {
			if (i != p) {
				dfs(i, v, arr);
			}
		}
	}
	ll get_la(ll v, ll x) {
		if (x == 1) {
			return binup[v][0];
		}
		for (ll i = log; i >= 0; i--) {
			if (h[v] - h[binup[v][i]] <= x) {
				x -= h[v] - h[binup[v][i]];
				v = binup[v][i];
			}
		}
		return v;
	}
	pair<ll, ll> get_lca(ll a, ll b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		ll oa = a, ob = b;
		a = get_la(a, h[a] - h[b]);
		if (a == b) {
			return {-1, -1};
		}
		for (ll i = log; i >= 0; i--) {
			if (binup[a][i] != binup[b][i]) {
				a = binup[a][i];
				b = binup[b][i];
			}
		}
		return {a, b};
	}
	bool is_p(ll a, ll b) {
		if (h[a] > h[b]) {
			return false;
		}
		return get_la(b, h[a] - h[b]) == a;
	}
};

mt19937 rnd(1647845257);

ll make_pair2(ll a, ll b) {
	return ((long long)(a)*(long long)(n) + b) % mod;
}

ll dfs(ll v, ll p, ll pp, unordered_map<ll, ll>& num, unordered_map<ll, ll>& col, DSU& d, vector<vector<ll>>& arr) {
	ll now = col[make_pair2(v, p)];
	for (auto i : arr[v]) {
		if (i != p) {
			now += dfs(i, v, p, num, col, d, arr);
		}
	}
	if (now > 0 && pp != p) {
		d.unite(num[make_pair2(v, p)], num[make_pair2(p, pp)]);
		d.unite(num[make_pair2(p, v)], num[make_pair2(pp, p)]);
	}
	return now;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll m;
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	ll root = rnd() % n;
	vector<vector<ll>> arr(n);
	unordered_map<ll, ll> num;
	unordered_map<ll, ll> col;
	ll last = 0;
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		num[make_pair2(a, b)] = last;
		num[make_pair2(b, a)] = last + 1;
		last++;
		last++;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	DSU d(last);
	LCA l(arr, root);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			continue;
		}
		a--;
		b--;
		auto[aa, ba] = l.get_lca(a, b);
		if (aa == -1) {
			if (l.is_p(b, a)) {
				swap(a, b);
			}
			col[make_pair2(l.get_la(b, l.h[b] - l.h[a] - 1), a)]--;
			col[make_pair2(b, l.get_la(b, 1))]++;
		} else {
			ll na = l.get_la(aa, 1);
			d.unite(num[make_pair2(na, aa)], num[make_pair2(ba, na)]);
			d.unite(num[make_pair2(aa, na)], num[make_pair2(na, ba)]);
			col[make_pair2(l.get_la(a, l.h[a] - l.h[na] - 1), na)]--;
			col[make_pair2(a, l.get_la(a, 1))]++;
			col[make_pair2(l.get_la(b, l.h[b] - l.h[na] - 1), na)]--;
			col[make_pair2(b, l.get_la(b, 1))]++;
		}
	}
	dfs(root, root, root, num, col, d, arr);
	for (ll i = 0; i < n; i++) {
		for (auto j : arr[i]) {
			if (d.get(num[make_pair2(i, j)]) == d.get(num[make_pair2(j, i)])) {
				cout << 0;
				return 0;
			}
		}
	}
	ll ans = 1;
	for (ll i = 0; i < d.col / 2; i++) {
		ans = ans * 2;
		ans = ans % mod;
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
