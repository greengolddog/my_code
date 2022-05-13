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
	vector<ll> count(ll n, ll m, vector<tuple<ll, ll, ll, ll>>& all) {
		DSU d(n);
		vector<ll> ans(m, 0);
		count(1, 0, size, d, ans, all);
		return ans;
	}
	void count(ll v, ll l, ll r, DSU& d, vector<ll>& ans, vector<tuple<ll, ll, ll, ll>>& all) {
		for (auto[a, b] : tree[v]) {
			d.unite(a, b);
		}
		if (r - l == 1) {
			auto[_, a, b, i] = all[l];
			ans[i] = d.get(a) - d.get(b);
		} else {
			ll mid = (l + r) / 2;
			count(v * 2, l, mid, d, ans, all);
			count(v * 2 + 1, mid, r, d, ans, all);
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
	ll n, m;
	cin >> n >> m;
	DSU d(n);
	vector<tuple<ll, ll, ll, ll>> arr(m);
	segment_tree st(m);
	for (ll i = 0; i < m; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		arr[i] = make_tuple(w, a, b, i);
	}
	arr.push_back(make_tuple(1'000'000'000, 0, 0, 0));
	sort(arr.begin(), arr.end());
	vector<ll> ans(m, 0);
	vector<tuple<ll, ll, ll, ll>> now;
	ll xx = 0;
	for (auto[w, a, b, i] : arr) {
		if (now.size() == 0 || get<0>(now.back()) == w) {
			now.push_back(make_tuple(w, a, b, i));
		} else {
			multiset<pair<ll, ll>> s;
			ll x = 0;
			for (auto[w, a, b, i] : now) {
				st.add(xx, xx + x, a, b);
				x++;
				st.add(xx + x, m, a, b);
				if (d.get(a) != d.get(b)) {
					ans[i] = 1;
				}
			}
			for (auto[w, a, b, i] : now) {
				d.unite(a, b);
			}
			xx += now.size();
			now.clear();
			now.push_back(make_tuple(w, a, b, i));
		}
	}
	vector<ll> a = st.count(n, m, arr);
	for (ll i = 0; i < m; i++) {
		cout << (ans[i] == 0 ? "none" : (a[i] != 0 ? "any" : "at least one")) << '\n';
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
