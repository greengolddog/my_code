#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

struct segment_tree {
	vector<pair<pair<ll, ll>, ll>> tree;
	ll size;
	segment_tree(vector<pair<ll, ll>> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p *= 2;
		}
		arr.resize(p, {INF, INF});
		size = p;
		tree.resize(size * 2, {{INF, INF}, INF});
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<pair<ll, ll>>& arr) {
		if (r - l == 1) {
			tree[v] = {arr[l], l};
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
	pair<pair<ll, ll>, ll> get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	pair<pair<ll, ll>, ll> get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return {{INF, INF}, INF};
		}
		ll mid = (l + r) / 2;
		return min(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
};

ll build(vector<tuple<ll, ll, ll>>& arr, segment_tree& st, ll l, ll r, ll p, vector<tuple<ll, ll, ll>>& ans) {
	if (r - l == 0) {
		return -1;
	}
	if (r - l == 1) {
		ans.push_back(make_tuple(p + 1, 0, 0));
		return get<2>(arr[l]);
	}
	auto g = st.get(l, r);
	ll num = g.second;
	ll l1 = build(arr, st, l, num, g.first.second, ans);
	ll now = ans.size();
	ans.push_back(make_tuple(p + 1, l1 + 1, -1));
	ll r1 = build(arr, st, num + 1, r, g.first.second, ans);
	get<2>(ans[now]) = r1 + 1;
	return g.first.second;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	cout << "YES\n";
	vector<tuple<ll, ll, ll>> arr, ans;
	for (ll i = 0; i < n; i++) {
		ll k, p;
		cin >> k >> p;
		arr.push_back(tie(k, p, i));
	}
	sort(arr.begin(), arr.end());
	vector<pair<ll, ll>> a;
	for (auto[_, p, i] : arr) {
		a.push_back({p, i});
	}
	segment_tree st(a);
	build(arr, st, 0, n, -1, ans);
	vector<pair<ll, tuple<ll, ll, ll>>> aa;
	for (ll i = 0; i < n; i++) {
		aa.push_back(make_pair(get<2>(arr[i]), ans[i]));
	}
	sort(aa.begin(), aa.end());
	for (auto[_, i] : aa) {
		auto[a1, a2, a3] = i;
		cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
	}
}
