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
	vector<ll> tree;
	ll size;
	segment_tree(ll x) {
		ll p;
		for (p = 1; p <= x; p *= 2) {}
		size = p;
		tree.resize(p * 2, 0);
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
		return get(v * 2, l, mid, ql, qr) + get(v * 2 + 1, mid, r, ql, qr);
	}
	void inc(ll x) {
		change(1, 0, size, 1, x);
	}
	void dec(ll x) {
		change(1, 0, size, -1, x);
	}
	void change(ll v, ll l, ll r, ll x, ll n) {
		if (l > n || n >= r) {
			return;
		}
		tree[v] += x;
		if (r - l == 1) {
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, x, n);
		change(v * 2 + 1, mid, r, x, n);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> q(m);
	for (ll i = 0; i < m; i++) {
		cin >> q[i];
		q[i]--;
	}
	deque<ll> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	vector<ll> lv(n, -1);
	segment_tree st(m + n);
	vector<ll> ans;
	ll cnt = 0;
	for (auto i : q) {
		if (lv[i] == -1) {
			ll ld = -1;
			while (ld != i) {
				ans.push_back(n);
				ld = arr.front();
				st.inc(cnt);
				lv[arr.front()] = cnt;
				cnt++;
				arr.pop_front();
			}
		} else {
			ans[lv[i]] = st.get(lv[i], cnt);
			st.dec(lv[i]);
			ans.push_back(n);
			lv[i] = cnt;
			st.inc(cnt);
			cnt++;
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
}
