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
	ll size = 1;
	segment_tree(ll n) {
		while (size < n) {
			size *= 2;
		}
		tree.resize(size * 2, 1);
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
	ll get_first(ll l, ll r) {
		if (get(l, r) == 0) {
			return -1;
		} else {
			return get_first(1, 0, size, l, r);
		}
	}
	ll get_first(ll v, ll l, ll r, ll ql, ll qr) {
		if (r - l == 1) {
			return l;
		}
		ll mid = (l + r) / 2;
		if (get(v * 2, l, mid, ql, qr) > 0) {
			return get_first(v * 2, l, mid, ql, qr);
		} else {
			return get_first(v * 2 + 1, mid, r, ql, qr);
		}
	}
	ll get_last(ll l, ll r) {
		if (get(l, r) == 0) {
			return -1;
		} else {
			return get_last(1, 0, size, l, r);
		}
	}
	ll get_last(ll v, ll l, ll r, ll ql, ll qr) {
		if (r - l == 1) {
			return l;
		}
		ll mid = (l + r) / 2;
		if (get(v * 2 + 1, mid, r, ql, qr) == 0) {
			return get_last(v * 2, l, mid, ql, qr);
		} else {
			return get_last(v * 2 + 1, mid, r, ql, qr);
		}
	}
	void change(ll x) {
		change(1, 0, size, x);
	}
	void change(ll v, ll l, ll r, ll x) {
		if (l > x || x >= r) {
			return;
		}
		if (r - l == 1) {
			tree[v] = 0;
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, x);
		change(v * 2 + 1, mid, r, x);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	segment_tree st(n);
	for (ll i = 0; i < m; i++) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll x;
			cin >> x;
			x--;
			st.change(x);
		} else {
			ll x, y;
			cin >> x >> y;
			x--;
			y--;
			ll a = st.get_first(x, n), b = st.get_last(0, x + 1);
			if (a == -1) {
				a = st.get_first(0, n);
			}
			if (b == -1) {
				b = st.get_last(0, n);
			}
			ll da = min(abs(a - x), n - abs(a - x)), db = min(abs(b - x), n - abs(b - x));
			cout << min(min(abs(y - a), n - abs(y - a)) + da, min(abs(y - b), n - abs(y - b)) + db) << '\n';
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
