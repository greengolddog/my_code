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

struct segment_tree_xor {
	vector<ll> tree, m;
	ll size;
	segment_tree_xor(vector<ll> arr) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, 0);
		tree.resize(size * 2, 0);
		m.resize(size * 2, 0);
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
		tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
	}
	void push(ll v, ll l, ll r) {
		ll mid = (l + r) / 2;
		if (mid - l == 2) {
			tree[v * 2] ^= m[v];
		}
		if (r - mid == 1) {
			tree[v * 2 + 1] ^= m[v];
		}
		m[v * 2] ^= m[v];
		m[v * 2 + 1] ^= m[v];
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
		return get(v * 2, l, mid, ql, qr) ^ get(v * 2 + 1, mid, r, ql, qr);
	}
	void upd_xor(ll l, ll r, ll x) {
		upd_xor(1, 0, size, l, r, x);
	}
	void upd_xor(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			if (r - l == 1) {
				tree[v] ^= x;
			}
			m[v] ^= x;
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		push(v, l, r);
		ll mid = (l + r) / 2;
		upd_xor(v * 2, l, mid, ql, qr, x);
		upd_xor(v * 2 + 1, mid, r, ql, qr, x);
		tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
	}
};

struct segment_tree_or {
	vector<ll> tree, m;
	ll size;
	segment_tree_or(vector<ll> arr) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, 0);
		tree.resize(size * 2, 0);
		m.resize(size * 2, 0);
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
		tree[v] = tree[v * 2] | tree[v * 2 + 1];
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
		return get(v * 2, l, mid, ql, qr) | get(v * 2 + 1, mid, r, ql, qr);
	}
};

struct segment_tree_and {
	vector<ll> tree, m;
	ll size;
	segment_tree_and(vector<ll> arr) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, ~0);
		tree.resize(size * 2, ~0);
		m.resize(size * 2, ~0);
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
		tree[v] = tree[v * 2] & tree[v * 2 + 1];
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return ~0;
		}
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qr) & get(v * 2 + 1, mid, r, ql, qr);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n * q <= 1'000'000) {
		for (ll i = 0; i < q; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (s1 == "get") {
				ll l, r;
				cin >> l >> r;
				l--;
				if (s2 == "or") {
					ll ans = 0;
					for (ll j = l; j < r; j++) {
						ans |= arr[j];
					}
					cout << ans;
				}
				if (s2 == "and") {
					ll ans = arr[l];
					for (ll j = l; j < r; j++) {
						ans &= arr[j];
					}
					cout << ans;
				}
				if (s2 == "xor") {
					ll ans = 0;
					for (ll j = l; j < r; j++) {
						ans ^= arr[j];
					}
					cout << ans;
				}
				cout << '\n';
			} else {
				ll l, r, x;
				cin >> l >> r >> x;
				l--;
				if (s2 == "or") {
					for (ll j = l; j < r; j++) {
						arr[j] |= x;
					}
				}
				if (s2 == "and") {
					for (ll j = l; j < r; j++) {
						arr[j] &= x;
					}
				}
				if (s2 == "xor") {
					for (ll j = l; j < r; j++) {
						arr[j] ^= x;
					}
				}
			}
		}
		return 0;
	}
	segment_tree_xor stx(arr);
	segment_tree_or sto(arr);
	segment_tree_and sta(arr);
	for (ll i = 0; i < q; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == "get") {
			ll l, r;
			cin >> l >> r;
			l--;
			if (s2 == "or") {
				cout << sto.get(l, r);
			}
			if (s2 == "and") {
				cout << sta.get(l, r);
			}
			if (s2 == "xor") {
				cout << stx.get(l, r);
			}
			cout << '\n';
		} else {
			ll l, r, x;
			cin >> l >> r >> x;
			l--;
			if (s2 == "or") {
				for (ll j = l; j < r; j++) {
					arr[j] |= x;
				}
			}
			if (s2 == "and") {
				for (ll j = l; j < r; j++) {
					arr[j] &= x;
				}
			}
			if (s2 == "xor") {
				stx.upd_xor(l, r, x);
			}
		}
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
