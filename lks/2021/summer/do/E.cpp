#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct node {
	ll sum;
	node *l = nullptr, *r = nullptr;
	node(ll sum): sum(sum) {}
	node(node *l, node *r): l(l), r(r) {
		sum = l->sum + r->sum;
	}
};

struct segment_tree {
	node *root = nullptr;
	ll size = 0;
	segment_tree(node *root, ll size): root(root), size(size) {}
	segment_tree(vector<ll> arr) {
		ll p = 1;
		while (p < arr.size()) {
			p *= 2;
		}
		arr.resize(p, 0);
		size = p;
		root = build(arr, 0, size);
	}
	node *build(vector<ll>& arr, ll l, ll r) {
		if (r - l == 1) {
			return new node(arr[l]);
		}
		ll mid = (l + r) / 2;
		return new node(build(arr, l, mid), build(arr, mid, r));
	}
	ll get(ll l, ll r) {
		return get(root, 0, size, l, r);
	}
	ll get(node *v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return v->sum;
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return get(v->l, l, mid, ql, qr) + get(v->r, mid, r, ql, qr);
	}
	node *change(ll n, ll x) {
		return change(root, 0, size, n, x);
	}
	node *change(node *v, ll l, ll r, ll n, ll x) {
		if (n < l || r <= n) {
			return v;
		}
		if (r - l == 1) {
			return new node(x);
		}
		ll mid = (l + r) / 2;
		return new node(change(v->l, l, mid, n, x), change(v->r, mid, r, n, x));
	}
};

struct pdo {
	vector<segment_tree> arr;
	ll size;
	pdo(vector<ll> a) {
		size = a.size();
		arr.emplace_back(a);
	}
	ll get(ll i, ll l, ll r) {
		return arr[i].get(l, r);
	}
	void change_back(ll n, ll x) {
		arr.emplace_back(arr.back().change(n, x), size);
	}
	void change(ll i, ll n, ll x) {
		arr.emplace_back(arr[i].change(n, x), size);
	}
	void pop() {
		arr.pop_back();
	}
	segment_tree& back() {
		return arr.back();
	}
	void push(segment_tree& a) {
		arr.push_back(a);
	}
};

int main() {
	freopen("rollback.in", "r", stdin);
	freopen("rollback.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	pdo st(vector<ll>(n, 0));
	vector<ll> last(m, -1);
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		if (last[x] == -1) {
			last[x] = i;
			st.change_back(i, 1);
		} else {
			st.change_back(last[x], 0);
			st.change_back(i, 1);
			last[x] = i;
			segment_tree a = st.back();
			st.pop();
			st.pop();
			st.push(a);
		}
	}
	ll q, p = 0;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		x = ((x + p) % n) + 1;
		y = ((y + p) % m) + 1;
		ll l = x - 1, r = n;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (st.get(mid, x - 1, mid) < y) {
				l = mid;
			} else {
				r = mid;
			}
		}
		if (st.get(n, x - 1, n) < y) {
			p = 0;
			cout << 0 << '\n';
		} else {
			p = r;
			cout << r << '\n';
		}
	}
}
