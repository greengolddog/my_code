#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

using namespace std;

mt19937 rnd(time(0));

struct node {
	map<char, node*> m;
	ll num = 0;
	node(ll num): num(num) {}
	node *go(char c, vector<vector<ll>>& arr, ll& col) {
		if (m.find(c) == m.end()) {
			m[c] = new node(col);
			arr[num].push_back(col);
			arr.push_back(vector<ll>(1, num));
			col++;
		}
		return m[c];
	}
};

struct trie {
	node *root;
	ll col = 0;
	trie() {
		root = new node(col);
		col++;
	}
	void add(string s, vector<vector<ll>>& arr, vector<ll>& cost, ll c, vector<ll>& num) {
		node *now = root;
		for (auto i : s) {
			now = now->go(i, arr, col);
		}
		cost.resize(arr.size(), 0);
		cost[now->num] = c;
		num.push_back(now->num);
	}
};

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& sz) {
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, sz);
			sz[v] += sz[i];
		}
	}
}

void reorder(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& sz, ll& num, vector<ll>& new_num) {
	new_num[v] = num;
	num++;
	vector<pair<ll, ll>> all;
	for (auto i : arr[v]) {
		if (i != p) {
			all.emplace_back(sz[i], i);
		}
	}
	sort(all.begin(), all.end());
	for (auto[_, i] : all) {
		reorder(i, v, arr, sz, num, new_num);
	}
}

void dfs2(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& pp, vector<ll>& max_up, vector<ll>& h, bool b) {
	h[v] = h[p] + 1;
	pp[v] = p;
	if (b) {
		max_up[v] = max_up[p] + 1;
	}
	if ((v == p && arr[v].size() == 1) || (arr[v].size() > 1)) {
		dfs2(v + 1, v, arr, pp, max_up, h, true);
	}
	for (auto i : arr[v]) {
		if (i != p && i != v + 1) {
			dfs2(i, v, arr, pp, max_up, h, false);
		}
	}
}

struct bit {
	vector<ll> tree;
	ll size;
	bit(vector<ll> arr) {
		size = arr.size();
		tree.resize(arr.size() + 1);
		for (ll i = 0; i < size; i++) {
			add(i, arr[i]);
		}
	}
	void add(ll n, ll x) {
		n++;
		for (; n <= size; n += n & -n) {
			tree[n] += x;
		}
	}
	ll get(ll x) {
		ll ans = 0;
		for (; x > 0; x -= x & -x) {
			ans += tree[x];
		}
		return ans;
	}
	ll get(ll l, ll r) {
		return get(r + 1) - get(l);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(1);
	vector<ll> cost(1, 0), num;
	trie t;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll c;
		cin >> c;
		t.add(s, arr, cost, c, num);
	}
	n = arr.size();
	vector<ll> sz(n, 1);
	dfs(0, 0, arr, sz);
	ll nn = 0;
	vector<ll> nnum(n);
	reorder(0, 0, arr, sz, nn, nnum);
	vector<vector<ll>> narr(n);
	vector<ll> ncost(n), nsz(n);
	for (ll i = 0; i < n; i++) {
		ncost[nnum[i]] = cost[i];
		nsz[nnum[i]] = sz[i];
		for (auto j : arr[i]) {
			narr[nnum[i]].push_back(nnum[j]);
		}
	}
	arr = narr;
	cost = ncost;
	sz = nsz;
	for (auto& i : num) {
		i = nnum[i];
	}
	vector<ll> max_up(n, 0), p(n, 0), h(n, -1);
	dfs2(0, 0, arr, p, max_up, h, false);
	bit b(cost);
	for (ll _ = 0; _ < m; _++) {
		char c;
		cin >> c;
		if (c == '?') {
			ll i, k;
			cin >> i >> k;
			i--;
			i = num[i];
			ll up = h[i] - k;
			ll ans = 0;
			while (up >= 0) {
				ll can = max_up[i];
				if (can >= up) {
					ans += b.get(i - up, i);
					break;
				}
				ans += b.get(i - can, i);
				up -= can;
				i -= can;
				i = p[i];
				up--;
			}
			cout << ans << '\n';
		} else {
			ll i, j;
			cin >> i >> j;
			i--;
			b.add(num[i], j);
		}
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
