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

struct node {
	int x = 0;
	node *sl = nullptr, *sr = nullptr;
	//int l, r;
	node(node *v) {
		x = v->x;
		sl = v->sl;
		sr = v->sr;
		//l = v->l;
		//r = v->r;
	}
	node() {
		//ll mid = (l + r) / 2;
		//if (r - l > 1) {
		//	sl = new node(l, mid);
		//	sr = new node(mid, r);
		//}
	}
	node *get_l() {
		if (sl == nullptr) {
			sl = new node();
		} else {
			sl = new node(sl);
		}
		return sl;
	}
	node *get_r() {
		if (sr == nullptr) {
			sr = new node();
		} else {
			sr = new node(sr);
		}
		return sr;
	}
	void change(int num, int l, int r) {
		if (num < l || num >= r) {
			return;
		}
		x++;
		if (r - l <= 1) {
			return;
		}
		int mid = (l + r) / 2;
		if (num < mid) {
			get_l()->change(num, l, mid);
		} else {
			get_r()->change(num, mid, r);
		}
	}
	ll get_xl() {
		if (sl == nullptr) {
			return 0;
		}
		return sl->x;
	}
};

struct persistent_segment_tree {
	node *roots[450'001];
	int col = 0;
	int size;
	persistent_segment_tree(int n) {
		ll s = n;
		while (s < n) {
			s *= 2;
		}
		size = s;
		roots[col] = new node();
	}
	void change(int num) {
		roots[col + 1] = new node(roots[col]);
		col++;
		roots[col]->change(num, 0, size);
	}
	ll get(int l, int r, int k) {
		return get(roots[r], roots[l], k, 0, size);
	}
	ll get(node *r, node *l, int k, int nl, int nr) {
		if (nr - nl <= 1) {
			return nl;
		}
		int mid = (nl + nr) / 2;
		if (r->get_xl() - l->get_xl() >= k) {
			if (l->sl == nullptr) {
				return get(r->sl, roots[0], k, nl, mid);
			}
			return get(r->sl, l->sl, k, nl, mid);
		} else {
			k -= r->get_xl() - l->get_xl();
			if (l->sr == nullptr) {
				return get(r->sr, roots[0], k, mid, nr);
			}
			return get(r->sr, l->sr, k, mid, nr);
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
	persistent_segment_tree pst(col);
	for (int i = 0; i < n; i++) {
		pst.change(arr[i]);
	}
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
		ans += narr[pst.get(i - 1, j, k)];
		for (int num = 1; num < q; num++) {
			x = (((ll)(i - 1) * lx + mx) % n) + 1;
			y = (((ll)(j - 1) * ly + my) % n) + 1;
			i = min(x, y);
			j = max(x, y);
			k = (((ll)(k - 1) * lk + mk) % (j - i + 1)) + 1;
			ans += narr[pst.get(i - 1, j, k)];
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
