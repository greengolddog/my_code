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
	segment_tree(vector<ll> arr = vector<ll>(0, 0)) {
		ll s = 1;
		for (; s < arr.size(); s *= 2) {}
		arr.resize(s, 0);
		size = s;
		tree.resize(s * 2, 0);
		build(1, 0, s, arr);
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
	ll get_first(ll l, ll r, ll x) {
		return get_first(1, 0, size, l, r, x);
	}
	ll get_first(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (r - l == 1) {
			return l;
		}
		ll mid = (l + r) / 2;
		if (get(v * 2, l, mid, ql, qr) >= x) {
			return get_first(v * 2, l, mid, ql, qr, x);
		} else {
			return get_first(v * 2 + 1, mid, r, ql, qr, x);
		}
	}
	ll get_last(ll l, ll r, ll x) {
		return get_last(1, 0, size, l, r, x);
	}
	ll get_last(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (r - l == 1) {
			return l;
		}
		ll mid = (l + r) / 2;
		if (get(v * 2 + 1, mid, r, ql, qr) >= x) {
			return get_last(v * 2 + 1, mid, r, ql, qr, x);
		} else {
			return get_last(v * 2, l, mid, ql, qr, x);
		}
	}
	void dec(ll x) {
		dec(1, 0, size, x);
	}
	void dec(ll v, ll l, ll r, ll x) {
		if (l > x || x >= r) {
			return;
		}
		if (r - l == 1) {
			tree[v]--;
			return;
		}
		ll mid = (l + r) / 2;
		dec(v * 2, l, mid, x);
		dec(v * 2 + 1, mid, r, x);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, r, k, p;
	cin >> n >> m >> r >> k >> p;
	vector<vector<ll>> arr(n, vector<ll>(m, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<segment_tree> WE(n), SN(m);
	for (ll i = 0; i < n; i++) {
		WE[i] = segment_tree(arr[i]);
	}
	for (ll i = 0; i < m; i++) {
		vector<ll> a(n);
		for (ll j = 0; j < n; j++) {
			a[j] = arr[j][i];
		}
		SN[i] = segment_tree(a);
	}
	for (ll i = 0; i < k; i++) {
		char c;
		cin >> c;
		ll a, b;
		cin >> a >> b;
		a--;
		if (c == 'W') {
			ll st = 0;
			for (ll i = 0; i < r; i++) {
				if (WE[a].get(st, m) < b) {
					break;
				}
				ll now = WE[a].get_first(st, m, b);
				st = now + 1;
				WE[a].dec(now);
				SN[now].dec(a);
				arr[a][now]--;
			}
		}
		if (c == 'E') {
			ll st = m;
			for (ll i = 0; i < r; i++) {
				if (WE[a].get(0, st) < b) {
					break;
				}
				ll now = WE[a].get_last(0, st, b);
				st = now;
				WE[a].dec(now);
				SN[now].dec(a);
				arr[a][now]--;
			}
		}
		if (c == 'N') {
			ll st = 0;
			for (ll i = 0; i < r; i++) {
				if (SN[a].get(st, n) < b) {
					break;
				}
				ll now = SN[a].get_first(st, n, b);
				st = now + 1;
				SN[a].dec(now);
				WE[now].dec(a);
				arr[now][a]--;
			}
		}
		if (c == 'S') {
			ll st = n;
			for (ll i = 0; i < r; i++) {
				if (SN[a].get(0, st) < b) {
					break;
				}
				ll now = SN[a].get_last(0, st, b);
				st = now;
				SN[a].dec(now);
				WE[now].dec(a);
				arr[now][a]--;
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= n - p; i++) {
		for (ll j = 0; j <= m - p; j++) {
			ll now = 0;
			for (ll k = 0; k < p; k++) {
				for (ll l = 0; l < p; l++) {
					now += arr[i + k][j + l];
				}
			}
			assign_max(ans, now);
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
