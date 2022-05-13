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

struct DSU {
	vector<ll> arr, s;
	vector<ll> h;
	ll sz;
	DSU(ll n) {
		sz = n;
		arr.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			arr[i] = i;
		}
		s.resize(n, 1);
	}
	ll get(ll v) {
		return (v == arr[v] ? v : get(arr[v]));
	}
	void unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			h.push_back(-1);
			return;
		}
		sz--;
		if (s[a] < s[b]) {
			swap(a, b);
		}
		h.push_back(b);
		arr[b] = a;
		s[a] += s[b];
	}
	void back() {
		if (h.back() == -1) {
			h.pop_back();
			return;
		}
		sz++;
		s[arr[h.back()]] -= s[h.back()];
		arr[h.back()] = h.back();
		h.pop_back();
	}
};

struct segment_tree {
	vector<vector<pair<ll, ll>>> tree;
	ll size;
	segment_tree(ll n) {
		size = n;
		tree.resize(size * 4);
	}
	void add(ll l, ll r, ll a, ll b) {
		add(1, 0, size, l, r, a, b);
	}
	void add(ll v, ll l, ll r, ll ql, ll qr, ll a, ll b) {
		if (ql <= l && r <= qr) {
			tree[v].push_back(make_pair(a, b));
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		if (r - l == 1) {
			tree[v].push_back(make_pair(a, b));
			return;
		}
		ll mid = (l + r) / 2;
		add(v * 2, l, mid, ql, qr, a, b);
		add(v * 2 + 1, mid, r, ql, qr, a, b);
	}
	vector<ll> count(ll n) {
		DSU d(n);
		vector<ll> ans;
		count(1, 0, size, d, ans);
		return ans;
	}
	void count(ll v, ll l, ll r, DSU& d, vector<ll>& ans) {
		for (auto[a, b] : tree[v]) {
			d.unite(a, b);
		}
		if (r - l == 1) {
			ans.push_back(d.sz);
		} else {
			ll mid = (l + r) / 2;
			count(v * 2, l, mid, d, ans);
			count(v * 2 + 1, mid, r, d, ans);
		}
		for (auto[a, b] : tree[v]) {
			d.back();
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	map<pair<ll, ll>, ll> m;
	vector<pair<pair<ll, ll>, pair<ll, ll>>> arr;
	ll t = 0;
	for (ll i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == '?') {
			t++;
		} else {
			ll a, b;
			cin >> a >> b;
			if (a < b) {
				swap(a, b);
			}
			a--;
			b--;
			if (c == '+') {
				m[make_pair(a, b)] = t;
			} else {
				arr.push_back(make_pair(make_pair(m[make_pair(a, b)], t), make_pair(a, b)));
				m[make_pair(a, b)] = -1;
			}
		}
	}
	if (t == 0) {
		return 0;
	}
	for (auto[x, t1] : m) {
		auto[a, b] = x;
		if (t1 == -1) {
			continue;
		}
		arr.push_back(make_pair(make_pair(t1, t), make_pair(a, b)));
	}
	segment_tree st(t);
	for (auto[x, y] : arr) {
		auto[t1, t2] = x;
		auto[a, b] = y;
		st.add(t1, t2, a, b);
	}
	for (auto i : st.count(n)) {
		cout << i << ' ';
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
