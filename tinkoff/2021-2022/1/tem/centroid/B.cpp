#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 9'000'000'000'000'000'000;
mt19937 rnd(time(0));

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

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(ll n = 1) {
		ll p = 1;
		for (; p < n; p *= 2) {}
		size = p;
		tree.resize(p * 2, -INF);
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return -INF;
		}
		ll mid = (l + r) / 2;
		return max(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
	void change(ll n, ll x) {
		change(1, 0, size, n, x);
	}
	void change(ll v, ll l, ll r, ll n, ll x) {
		if (n < l || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = x;
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, n, x);
		change(v * 2 + 1, mid, n, x);
	}
}

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& s, vector<bool>& used) {
	s[v] = 1;
	for (auto i : arr[v]) {
		if (i != p && !used[i]) {
			dfs(i, v, arr, s, used);
			s[v] += s[i];
		}
	}
}

ll dfs_find(ll v, ll p, ll sz, vector<vector<ll>>& arr, vector<ll>& s, vector<bool>& used) {
	for (auto i : arr[v]) {
		if (i != p && !used[i] && s[i] >= sz / 2) {
			return dfs_find(i, v, sz, arr, s, used);
		}
	}
	return v;
}

void dec(ll v, vector<vector<ll>>& arr, ll p, vector<bool>& used, vector<ll>& ans, vector<ll>& s, vector<ll>& h) {
	dfs(v, v, arr, s, used);
	ll nc = dfs_find(v, v, s[v], arr, s, used);
	used[nc] = true;
	ans[nc] = p;
	for (auto i : arr[nc]) {
		if (!used[i]) {
			dec(i, arr, nc, used, ans, s, h);
			assign_max(h[v], h[i] + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	map<pair<ll, ll>, ll> pv;
	for (ll i = 1; i < n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		pv[make_pair(a, b)] = c;
		pv[make_pair(b, a)] = c;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<bool> used(n, false);
	vector<ll> s(n);
	vector<ll> ans(n), h(n, 1);
	dec(0, arr, -1, used, ans, s, h);
	ll q;
	cin >> q;
	vector<segment_tree> aq(n);
	for (ll i = 0; i < n; i++) {
		aq[i] = segment_tree(h[i]);
	}
	vector<ll> t;
	for (ll i = 0; i < q; i++) {
		ll tq;
		cin >> tq;
		if (tq == 1) {
			ll v, d, c;
			vin >> v >> d >> c;
			v--;
			t.push_back(c);
			c = t.size() - 1;
			while (v != -1) {
			}
		} else {
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
