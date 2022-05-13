#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef int_fast64_t ll;

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
	ll l, r, x;
	node(ll x = -1): x(x) {
		l = -1;
		r = -1;
	}
	node(const node& n) {
		l = n.l;
		r = n.r;
		x = n.x;
	}
};

struct persistent_segment_tree {
	vector<node> tree;
	vector<ll> roots;
	ll size;
	persistent_segment_tree(ll n) {
		size = n;
		while (size < n) {
			size *= 2;
		}
		roots.push_back(1);
		tree.resize(size * 4, node());
		for (ll i = 1; i < size * 2; i++) {
			tree[i].l = i * 2;
			tree[i].r = i * 2 + 1;
		}
	}
	void change(ll n, ll x) {
		roots.push_back(change(roots.back(), 0, size, n, x));
	}
	ll change(ll v, ll l, ll r, ll n, ll x) {
		if (n < l || r <= n) {
			return v;
		}
		if (r - l == 1) {
			ll num = tree.size();
			tree.push_back(node(tree[v]));
			tree[num].x = x;
			return num;
		}
		ll num = tree.size();
		tree.push_back(node(tree[v]));
		ll mid = (l + r) / 2;
		tree[num].l = change(tree[v].l, l, mid, n, x);
		tree[num].r = change(tree[v].r, mid, r, n, x);
		tree[num].x = min(tree[tree[num].l].x, tree[tree[num].r].x);
		return num;
	}
	ll get(ll l, ll r) {
		return get(roots[r + 1], 0, size, l);
	}
	ll get(ll v, ll l, ll r, ll x) {
		if (r - l == 1) {
			return l;
		}
		ll mid = (l + r) / 2;
		if (tree[tree[v].l].x < x) {
			return get(tree[v].l, l, mid, x);
		} else {
			return get(tree[v].r, mid, r, x);
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	persistent_segment_tree pst(n + 1);
	pst.change(0, 0);
	vector<ll> arr(1, 0);
	vector<ll> pref(2, 0), bn(1, 0);
	for (ll i = 0; i < n; i++) {
		char c;
		ll l, r, x;
		cin >> c >> l >> r >> x;
		if (c == '+') {
			set<ll> s;
			l = lower_bound(bn.begin(), bn.end(), l) - bn.begin();
			r = lower_bound(bn.begin(), bn.end(), r) - bn.begin();
			ll ans = pst.get(l, r);
			//pst.change(ans, arr.size());
			//if (x % 2 == 1) {
			//	pref.push_back(pref.back() ^ ans);
			//} else {
			//	pref.push_back(pref.back());
			//}
			for (ll i = 0; i < x; i++) {
				pref.push_back(pref.back() ^ ans);
				pst.change(ans, arr.size());
				arr.push_back(ans);
				bn.push_back(bn.back() + 1);
			}
		} else {
			if (x % 2 == 0) {
				cout << "SECOND\n";
				continue;
			}
			ll nl = lower_bound(bn.begin(), bn.end(), l) - bn.begin(), nr = lower_bound(bn.begin(), bn.end(), r) - bn.begin();
			ll ans = 0;
			if (nl != nr) {
				ans ^= pref[nr] ^ pref[nl + 1];
				if ((bn[nl] - l) % 2 == 0) {
					ans ^= arr[nl];
				}
				if ((r - bn[nr - 1]) % 2 == 1) {
					ans ^= arr[nr];
				}
			} else {
				if ((r - l) % 2 == 0) {
					ans ^= arr[nl];
				}
			}
			cout << (ans == 0 ? "SECOND" : "FIRST") << '\n';
		}
	}
}
