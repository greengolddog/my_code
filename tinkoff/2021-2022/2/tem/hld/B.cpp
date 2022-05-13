#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000, MOD = 1'000'000'007;
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
	vector<ll> tree, m;
	ll size;
	segment_tree(vector<ll> arr = vector<ll>(0, 0)) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, 0);
		m.resize(size * 2, 0);
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
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	void push(ll v, ll l, ll r) {
		ll mid = (l + r) / 2;
		tree[v * 2] += (mid - l) * m[v];
		tree[v * 2 + 1] += (r - mid) * m[v];
		m[v * 2] += m[v];
		m[v * 2 + 1] += m[v];
		m[v] = 0;
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
		push(v, l, r);
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qr) + get(v * 2 + 1, mid, r, ql, qr);
	}
	void change(ll l, ll r, ll x) {
		change(1, 0, size, l, r, x);
	}
	void change(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			tree[v] += x * (r - l);
			m[v] += x;
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		//push(v, l, r);
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, ql, qr, x);
		change(v * 2 + 1, mid, r, ql, qr, x);
		tree[v] = tree[v * 2] + tree[v * 2 + 1] + (r - l) * m[v];
	}
};

struct HLD {
	segment_tree st;
	vector<ll> reorder, head, mp, parent;
	ll root = 0;
	HLD(vector<vector<ll>> arr, vector<ll> c) {
		reorder.resize(arr.size(), 0);
		head.resize(arr.size(), 0);
		mp.resize(arr.size(), 0);
		parent.resize(arr.size(), 0);
		vector<ll> sz(arr.size(), 0);
		dfs(root, root, sz, arr);
		ll last = 0;
		dfs_reorder(root, root, last, sz, arr);
		vector<ll> nc(arr.size(), 0);
		for (ll i = 0; i < arr.size(); i++) {
			nc[reorder[i]] = c[i];
		}
		st = segment_tree(nc);
	}
	void dfs(ll v, ll p, vector<ll>& sz, vector<vector<ll>>& arr) {
		sz[v] = 1;
		for (auto i : arr[v]) {
			if (i != p) {
				dfs(i, v, sz, arr);
				sz[v] += sz[i];
			}
		}
	}
	void dfs_reorder(ll v, ll p, ll& last, vector<ll>& sz, vector<vector<ll>>& arr) {
		reorder[v] = last;
		parent[reorder[v]] = reorder[p];
		last++;
		if (reorder[v] == reorder[p] + 1) {
			head[reorder[v]] = head[reorder[p]];
		} else {
			head[reorder[v]] = reorder[v];
		}
		vector<pair<ll, ll>> all;
		for (auto i : arr[v]) {
			if (i != p) {
				all.emplace_back(sz[i], i);
			}
		}
		sort(all.begin(), all.end());
		reverse(all.begin(), all.end());
		//shuffle(all.begin(), all.end(), rnd64);
		for (auto[_, i] : all) {
			dfs_reorder(i, v, last, sz, arr);
		}
		mp[reorder[v]] = last;
	}
	ll get(ll v) {
		v = reorder[v];
		return st.get(v, v + 1);
	}
	ll get_pn(ll v) {
		v = reorder[v];
		ll ans = st.get(v + 1, mp[v]);
		if (v == 0) {
			ans += st.get(0, 1);
		}
		while (v != 0) {
			ans += st.get(head[v], v + 1);
			v = head[v];
			if (v == 0) {
				break;
			}
			v = parent[v];
			if (v == 0) {
				ans += st.get(v, v + 1);
			}
		}
		return ans;
	}
	void add(ll v, ll x) {
		v = reorder[v];
		st.change(v + 1, mp[v], x);
		if (v == 0) {
			st.change(0, 1, x);
		}
		while (v != 0) {
			st.change(head[v], v + 1, x);
			v = head[v];
			if (v == 0) {
				break;
			}
			v = parent[v];
			if (v == 0) {
				st.change(v, v + 1, x);
			}
		}
	}
};

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll a;
		cin >> a;
		arr[i].push_back(a);
		arr[a].push_back(i);
	}
	vector<ll> c(n);
	for (ll i = 0; i < n; i++) {
		cin >> c[i];
	}
	cout << c.back() << '\n';
	HLD h(arr, c);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		h.add(b, h.get_pn(a) % MOD);
		cout << h.get(n - 1) << '\n';
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
