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
	vector<vector<int>> tree;
	vector<int> ans;
	ll size;
	segment_tree(vector<pair<int, int>>& arr) {
		size = arr.size();
		tree.resize(arr.size() * 4);
		ans.resize(arr.size() * 4);
		build(1, 0, size, arr);
	}
	void build(int v, int l, int r, vector<pair<int, int>>& arr) {
		if (r - l == 1) {
			tree[v].push_back(arr[l].second);
			ans[v] = arr[l].first;
			return;
		}
		int mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		merge(tree[v * 2].begin(), tree[v * 2].end(), tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(), back_inserter(tree[v]));
	}
	int get(ll l, ll r, ll k) {
		return get(1, 0, size, l, r, k);
	}
	int get(int v, int l, int r, int ql, int qr, int k) {
		if (tree[v].size() == 1) {
			return ans[v];
		}
		int mid = (l + r) / 2;
		int mk = lower_bound(tree[v * 2].begin(), tree[v * 2].end(), qr) - lower_bound(tree[v * 2].begin(), tree[v * 2].end(), ql);
		if (k <= mk) {
			return get(v * 2, l, mid, ql, qr, k);
		} else {
			k -= mk;
			return get(v * 2 + 1, mid, r, ql, qr, k);
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	int n;
	cin >> n;
	int mod = 1'000'000'000;
	int arr[450'001], narr[450'001];
	cin >> arr[0];
	ll l, m;
	cin >> l >> m;
	narr[0] = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] = ((ll)arr[i - 1] * l + m) % mod;
		narr[i] = arr[i];
	}
	sort(narr, narr + n);
	int col = unique(narr, narr + n) - narr;
	for (int i = 0; i < n; i++) {
		arr[i] = lower_bound(narr, narr + col, arr[i]) - narr;
	}
	vector<pair<int, int>> a;
	for (ll i = 0; i < n; i++) {
		a.push_back(make_pair(arr[i], i));
	}
	sort(a.begin(), a.end());
	segment_tree st(a);
	ll ans = 0;
	int B;
	cin >> B;
	for (int _ = 0; _ < B; _++) {
		int q;
		cin >> q;
		int x, y, k, i, j;
		int lx, mx, ly, my, lk, mk;
		cin >> x >> lx >> mx >> y >> ly >> my >> k >> lk >> mk;
		i = min(x, y);
		j = max(x, y);
		ans += narr[st.get(i - 1, j, k)];
		for (int num = 1; num < q; num++) {
			x = (((ll)(i - 1) * lx + mx) % n) + 1;
			y = (((ll)(j - 1) * ly + my) % n) + 1;
			i = min(x, y);
			j = max(x, y);
			k = (((ll)(k - 1) * lk + mk) % (j - i + 1)) + 1;
			ans += narr[st.get(i - 1, j, k)];
		}
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
