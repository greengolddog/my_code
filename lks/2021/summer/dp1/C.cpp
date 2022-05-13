#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<pair<ll, ll>> tree;
	ll size;
	segment_tree(vector<pair<ll, ll>> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p *= 2;
		}
		size = p;
		arr.resize(p, {-1, -1});
		tree.resize(p * 2);
		build(arr, 0, size, 1);
	}
	void build(vector<pair<ll, ll>>& arr, ll l, ll r, ll v) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(arr, l, mid, v * 2);
		build(arr, mid, r, v * 2 + 1);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
	pair<ll, ll> get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	pair<ll, ll> get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return {-1, -1};
		}
		ll mid = (l + r) / 2;
		return max(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
};

int main() {
	//freopen("dowry.in", "r", stdin);
	//freopen("dowry.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, l, r;
	cin >> n >> l >> r;
	vector<pair<ll, ll>> arr1, arr2;
	for (ll i = 0; i < n / 2; i++) {
		ll x, c;
		cin >> x >> c;
		arr1.push_back({x, c});
	}
	for (ll i = n / 2; i < n; i++) {
		ll x, c;
		cin >> x >> c;
		arr2.push_back({x, c});
	}
	vector<tuple<ll, ll, ll>> a1, a2;
	for (ll i = 0; i < (1 << arr1.size()); i++) {
		ll ans = 0, sum = 0;
		for (ll j = 0; j < arr1.size(); j++) {
			if (i >> j & 1) {
				ans += arr1[j].first;
				sum += arr1[j].second;
			}
		}
		a1.push_back({ans, sum, i});
	}
	for (ll i = 0; i < (1 << arr2.size()); i++) {
		ll ans = 0, sum = 0;
		for (ll j = 0; j < arr2.size(); j++) {
			if (i >> j & 1) {
				ans += arr2[j].first;
				sum += arr2[j].second;
			}
		}
		a2.push_back({ans, sum, i});
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	vector<pair<ll, ll>> na;
	for (auto[_, i, a] : a2) {
		na.push_back({i, a});
	}
	segment_tree st(na);
	ll u1 = a2.size() - 1, u2 = a2.size() - 1;
	ll m = 0;
	pair<ll, ll> aa = {0, 0};
	for (auto[i, s, ans] : a1) {
		while (u1 > 0 && get<0>(a2[u1]) + i > r) {
			u1--;
		}
		while (u2 > 0 && get<0>(a2[u2]) + i >= l) {
			u2--;
		}
		if (i < l && u2 + 1 < a2.size()) {
			u2++;
		}
		if (i > r) {
			break;
		}
		if (get<0>(a2[u1]) + i >= l && get<0>(a2[u2]) + i >= l) {
			auto[ns, ans2] = st.get(u2, u1 + 1);
			ns += s;
			if (ns > m) {
				m = ns;
				aa = make_pair(ans, ans2);
			}
		}
	}
	ll cnt = 0;
	vector<ll> ans;
	for (ll i = 0; i < arr1.size(); i++) {
		if ((aa.first >> i) & 1) {
			cnt++;
			ans.push_back(i + 1);
		}
	}
	for (ll i = 0; i < arr2.size(); i++) {
		if ((aa.second >> i) & 1) {
			cnt++;
			ans.push_back(i + 1 + arr1.size());
		}
	}
	cout << cnt << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
}
