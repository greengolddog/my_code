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

struct segment_tree {
	vector<pair<ll, ll>> tree;
	ll size = 1;
	segment_tree(ll n) {
		while (size < n) {
			size *= 2;
		}
		tree.resize(size * 2, make_pair(-1, 0));
	}
	pair<ll, ll> get(ll r) {
		return get(1, 0, size, 0, r + 1);
	}
	pair<ll, ll> get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return make_pair(-1, 0);
		}
		ll mid = (l + r) / 2;
		return max(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
	void change(ll x, ll c) {
		change(1, 0, size, x, c);
	}
	void change(ll v, ll l, ll r, ll x, ll c) {
		if (x < l || r <= x) {
			return;
		}
		if (r - l == 1) {
			tree[v] = make_pair(c, x);
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, x, c);
		change(v * 2 + 1, mid, r, x, c);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	deque<vector<pair<ll, ll>>> all(n);
	for (ll i = 0; i < m; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		all[l].push_back(make_pair(r, i));
	}
	for (ll i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	for (ll _ = 0; _ < n; _++) {
	segment_tree st(n);
	for (ll i = 0; i < n; i++) {
		if (!all[i].empty()) {
			st.change(i, all[i].back().first);
		}
	}
	ll fir = 0, sec = 0;
	vector<bool> ans(m, false);
	bool bb = true;
	while (fir != n || sec != n) {
		if (fir <= sec) {
			auto[a, b] = st.get(fir);
			if (a == -1) {
				bb = false;
				break;
			}
			fir = a + 1;
			all[b].pop_back();
			if (!all[b].empty()) {
				st.change(b, all[b].back().first);
			} else {
				st.change(b, -1);
			}
		} else {
			auto[a, b] = st.get(sec);
			if (a == -1) {
				bb = false;
				break;
			}
			ans[all[b].back().second] = true;
			sec = a + 1;
			all[b].pop_back();
			if (!all[b].empty()) {
				st.change(b, all[b].back().first);
			} else {
				st.change(b, -1);
			}
		}
	}
	if (bb) {
		for (auto i : ans) {
			cout << i;
		}
		return 0;
	}
	}
	cout << "impossible";
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
