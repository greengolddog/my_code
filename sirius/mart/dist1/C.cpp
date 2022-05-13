#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef int_fast32_t ll;

const ll INF = 1'000'000'000;

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

struct merge_sort_tree {
	vector<vector<ll>> tree;
	ll size = 1;
	merge_sort_tree(vector<vector<ll>> arr) {
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size);
		tree.resize(size * 2);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<vector<ll>>& arr) {
		if (r - l == 1) {
			for (auto a : arr[l]) {
				tree[v].push_back(a);
			}
			sort(tree[v].begin(), tree[v].end());
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		merge(tree[v * 2].begin(), tree[v * 2].end(), tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(), back_inserter(tree[v]));
	}
	ll get(ll l, ll ql) {
		return get(1, 0, size, l, ql);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qql) {
		if (ql >= r) {
			ll x = upper_bound(tree[v].begin(), tree[v].end(), qql) - tree[v].begin();
			return x;
		}
		if (l > ql) {
			return 0;
		}
		if (r - l == 1) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qql) + get(v * 2 + 1, mid, r, ql, qql);
	}
};

struct BIT {
	vector<merge_sort_tree> st;
	vector<vector<ll>> zip;
	ll n;
	BIT(vector<tuple<ll, ll, ll>> arr, ll sz) {
		n = sz;
		vector<vector<pair<ll, ll>>> all(n + 1);
		zip.resize(n + 1);
		for (auto[a, b, c] : arr) {
			for (; a <= n; a += a & -a) {
				all[a].push_back(make_pair(b, c));
				zip[a].push_back(b);
			}
		}
		st.push_back(merge_sort_tree(vector<vector<ll>>(1)));
		for (ll i = 1; i <= n; i++) {
			sort(zip[i].begin(), zip[i].end());
			zip[i].resize(unique(zip[i].begin(), zip[i].end()) - zip[i].begin());
			vector<vector<ll>> aa(zip.size());
			for (auto&[a, b] : all[i]) {
				a = lower_bound(zip[i].begin(), zip[i].end(), a) - zip[i].begin();
				aa[a].push_back(b);
			}
			st.push_back(merge_sort_tree(aa));
		}
	}
	ll get(ll a, ll b, ll c) {
		ll ans = 0;
		for (; a > 0; a -= a & -a) {
			ans += st[a].get(upper_bound(zip[a].begin(), zip[a].end(), b) - zip[a].begin(), c);
		}
		return ans;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	ll mx = 1'000'000'000;
	vector<tuple<ll, ll, ll>> arr(n);
	vector<ll> zip;
	for (auto&[a, b, c] : arr) {
		cin >> a >> b;
		a = mx - a;
		b = mx - b;
		c = a + b;
		zip.push_back(a);
	}
	sort(zip.begin(), zip.end());
	zip.resize(unique(zip.begin(), zip.end()) - zip.begin());
	for (auto&[a, b, c] : arr) {
		a = lower_bound(zip.begin(), zip.end(), a) - zip.begin() + 1;
	}
	BIT b(arr, zip.size());
	for (ll i = 0; i < q; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		x = mx - x;
		y = mx - y;
		z = mx * 2 - z;
		x = upper_bound(zip.begin(),  zip.end(), x) - zip.begin();
		cout << b.get(x, y, z) << '\n';
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
