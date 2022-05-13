#include <bits/stdc++.h>
typedef unsigned int ll;

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
	segment_tree(ll n) {
		size = 1;
		for (; size < n; size *= 2) {}
		tree.resize(size * 2, 0);
	}
	ll col() {
		return tree[1];
	}
	void add(ll x) {
		x += size;
		while (x > 0) {
			tree[x]++;
			x /= 2;
		}
		//change(1, 0, size, x);
	}
	void remove(ll x) {
		x += size;
		while (x > 0) {
			tree[x]--;
			x /= 2;
		}
		//change(1, 0, size, x);
	}
	//void change(ll v, ll l, ll r, ll x) {
	//	if (l > x || x >= r) {
	//		return;
	//	}
	//	if (r - l == 1) {
	//		tree[v] = 1 - tree[v];
	//		return;
	//	}
	//	ll mid = (l + r) / 2;
	//	change(v * 2, l, mid, x);
	//	change(v * 2 + 1, mid, r, x);
	//	tree[v] = tree[v * 2] + tree[v * 2 + 1];
	//}
	ll get(ll x) {
		return get(1, 0, size, x);
	}
	ll get(ll v, ll l, ll r, ll x) {
		while (r - l > 1) {
			if (tree[v * 2] < x) {
				x -= tree[v * 2];
				v = v * 2 + 1;
				l = (l + r) / 2;
			} else {
				v = v * 2;
				r = (l + r) / 2;
			}
		}
		return l;
	}
};

struct bit {
	vector<ll> tree;
	ll size;
	ll c = 0, l = 0;
	bit(ll n) {
		size = n;
		tree.resize(n + 1, 0);
		while (n > 1) {
			n /= 2;
			l++;
		}
	}
	ll col() {
		return c;
	}
	void add(ll x) {
		c++;
		x++;
		for (; x <= size; x += x & -x) {
			tree[x]++;
		}
	}
	void remove(ll x) {
		c--;
		x++;
		for (; x <= size; x += x & -x) {
			tree[x]--;
		}
	}
	ll get(ll x) {
		ll k = 0;
		for (ll i = l; i >= 0; i--) {
			if (k + (1 << i) <= size && tree[k + (1 << i)] < x) {
				k += (1 << i);
				x -= tree[k];
			}
		}
		return k;
	}
};

void dfs(ll v, ll p, vector<vector<ll>>& arr, segment_tree& st, vector<ll>& ans) {
	if (st.col() % 2 == 1 && arr[v].size() == 0) {
		return;
	}
	st.add(v);
	if (st.col() % 2 == 1) {
		ans[st.get(st.col() / 2 + 1)]++;
	}
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, st, ans);
		}
	}
	st.remove(v);
}

ll get_int() {
	ll ans = 0;
	char c = getwchar();
	while (c != ' ' && c != '\n') {
		ans *= 10;
		ans += c - '0';
		c = getwchar();
	}
	return ans;
}

void put_int(ll a) {
	for (auto i : to_string(a)) {
		putwchar(i);
	}
	putwchar('\n');
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	n = get_int();
	vector<ll> ans(n, 0);
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll a = get_int(), b = get_int();
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	segment_tree st(n);
	for (ll i = 0; i < n; i++) {
		dfs(i, i, arr, st, ans);
	}
	for (auto i : ans) {
		put_int(i - 1);
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
