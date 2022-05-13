#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
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

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> arr = vector<ll>(0, 0)) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, 0);
		tree.resize(size * 2, 0);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return max(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
	void change(ll x, ll h) {
		change(1, 0, size, x, h);
	}
	void change(ll v, ll l, ll r, ll x, ll h) {
		if (x < l || r <= x) {
			return;
		}
		if (r - l == 1) {
			tree[v] = h;
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, x, h);
		change(v * 2 + 1, mid, r, x, h);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
};

struct LCA {
	ll log = 20;
	vector<vector<ll>> binup;
	vector<ll> h;
	LCA(vector<vector<ll>> arr = vector<vector<ll>>(1, vector<ll>(0, 0))) {
		binup.resize(log, vector<ll>(arr.size(), 0));
		h.resize(arr.size(), -1);
		dfs(0, 0, arr);
	}
	void dfs(ll v, ll p, vector<vector<ll>>& arr) {
		binup[0][v] = p;
		for (ll i = 1; i < log; i++) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}
		h[v] = h[p] + 1;
		for (auto i : arr[v]) {
			if (i != p) {
				dfs(i, v, arr);
			}
		}
	}
	ll get_LA(ll a, ll x) {
		for (ll i = log - 1; i >= 0; i--) {
			if (x >= (1 << i)) {
				x -= 1 << i;
				a = binup[i][a];
			}
		}
		return a;
	}
	ll get_LCA(ll a, ll b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		a = get_LA(a, h[a] - h[b]);
		if (a == b) {
			return a;
		}
		for (ll i = log - 1; i >= 0; i--) {
			if (binup[i][a] != binup[i][b]) {
				a = binup[i][a];
				b = binup[i][b];
			}
		}
		return binup[0][a];
	}
};

struct HLD {
	vector<ll> up, reorder;
	segment_tree st;
	LCA l;
	HLD(vector<vector<ll>> arr, vector<ll> c) {
		up.resize(arr.size(), 0);
		reorder.resize(arr.size(), 0);
		vector<ll> size(arr.size(), 0);
		dfs_size(0, 0, size, arr);
		ll last = 0;
		hld_reorder(0, 0, last, size, reorder, up, arr);
		vector<vector<ll>> rarr(arr.size());
		vector<ll> nc(arr.size());
		for (ll i = 0; i < arr.size(); i++) {
			nc[reorder[i]] = c[i];
			for (auto j : arr[i]) {
				rarr[reorder[i]].push_back(reorder[j]);
			}
		}
		st = segment_tree(nc);
		l = LCA(rarr);
	}
	void dfs_size(ll v, ll p, vector<ll>& dp, vector<vector<ll>>& arr) {
		dp[v] = 1;
		for (auto i : arr[v]) {
			if (i != p) {
				dfs_size(i, v, dp, arr);
				dp[i] += dp[v];
			}
		}
	}
	void hld_reorder(ll v, ll p, ll& last, vector<ll>& dp, vector<ll>& reorder, vector<ll>& up, vector<vector<ll>>& arr) {
		reorder[v] = last;
		if (reorder[v] == reorder[p] + 1) {
			up[reorder[v]] = up[reorder[p]];
		} else {
			up[reorder[v]] = reorder[v];
		}
		last++;
		vector<pair<ll, ll>> all;
		for (auto i : arr[v]) {
			if (i != p) {
				all.emplace_back(dp[i], i);
			}
		}
		sort(all.begin(), all.end());
		reverse(all.begin(), all.end());
		for (auto[_, i] : all) {
			hld_reorder(i, v, last, dp, reorder, up, arr);
		}
	}
	ll get(ll a, ll b) {
		a = reorder[a];
		b = reorder[b];
		return max(getv(a, l.get_LCA(a, b)), getv(b, l.get_LCA(a, b)));
	}
	ll getv(ll a, ll b) {
		ll ans = 0;
		while (a != b) {
			if (up[a] > b) {
				assign_max(ans, st.get(up[a], a + 1));
				a = l.binup[0][up[a]];
			} else {
				assign_max(ans, st.get(b, a + 1));
				a = b;
			}
		}
		assign_max(ans, st.get(a, a + 1));
		return ans;
	}
	void change(ll a, ll h) {
		a = reorder[a];
		st.change(a, h);
	}
};

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	vector<ll> h(n);
	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	HLD tree(arr, h);
	ll k;
	cin >> k;
	for (ll i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == '!') {
			ll a, h;
			cin >> a >> h;
			a--;
			tree.change(a, h);
		} else {
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << tree.get(a, b) << '\n';
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
