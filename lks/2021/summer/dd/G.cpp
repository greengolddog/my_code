#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

mt19937 rnd(228);

struct node {
	ll k, p=rnd(), s=1, n;
	node *l = nullptr, *r = nullptr;
	node(ll k): k(k) {
		n = k*k;
	}
	void change(ll nk) {
		n -= k*k;
		n += nk*nk;
		k = nk;
	}
	void add(ll nk) {
		change(nk+k);
	}
};

ll size(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->s;
}

ll get(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->n;
}

ll get_k(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->k;
}

void upd(node *t) {
	t->s = 1+size(t->l)+size(t->r);
	t->n = t->k*t->k+get(t->l)+get(t->r);
}

pair<node*, node*> split(node *t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	if (k <= size(t->l)) {
		auto[l, r] = split(t->l, k);
		t->l = r;
		upd(t);
		return {l, t};
	} else {
		auto[l, r] = split(t->r, k-size(t->l)-1);
		t->r = l;
		upd(t);
		return {t, r};
	}
}

node *merge(node *t1, node *t2) {
	if (t1 == nullptr) {
		return t2;
	}
	if (t2 == nullptr) {
		return t1;
	}
	if (t1->p > t2->p) {
		auto t = merge(t1->r, t2);
		t1->r = t;
		upd(t1);
		return t1;
	} else {
		auto t = merge(t1, t2->l);
		t2->l = t;
		upd(t2);
		return t2;
	}
}

struct cartesian_tree {
	node *root = nullptr;
	ll s = 0;
	cartesian_tree(node *root = nullptr): root(root) {}
	ll size() {
		return s;
	}
	void push_back(ll x) {
		node *t = new node(x);
		root = merge(root, t);
		s++;
	}
	ll bank(ll n) {
		if (n == 0) {
			auto[t1, t2] = split(root, 2);
			auto[t11, t12] = split(t1, 1);
			t12->add(get_k(t11));
			root = merge(t12, t2);
		} else {
			if (n == size()-1) {
				auto[t1, t2] = split(root, size()-2);
				auto[t21, t22] = split(t2, 1);
				t21->add(get_k(t22));
				root = merge(t1, t21);
			} else {
				auto[t1, t2v] = split(root, n-1);
				auto[t2, t3] = split(t2v, 3);
				auto[t21, t22v] = split(t2, 1);
				auto[t22, t23] = split(t22v, 1);
				ll k = get_k(t22);
				t21->add(k/2);
				t23->add((k+1)/2);
				root = merge(merge(t1, merge(t21, t23)), t3);
			}
		}
		s--;
		return get(root);
	}
	ll sep(ll n) {
		auto[t1, t2v] = split(root, n);
		auto[t2, t3] = split(t2v, 1);
		ll k = get_k(t2);
		node *a1 = new node(k/2), *a2 = new node((k+1)/2);
		root = merge(merge(t1, merge(a1, a2)), t3);
		s++;
		return get(root);
	}
};

int main() {
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, p;
	cin >> n >> p;
	cartesian_tree dd;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		ans += x*x;
		dd.push_back(x);
	}
	cout << ans << '\n';
	ll k;
	cin >> k;
	for (ll i = 0; i < k; i++) {
		ll c;
		cin >> c;
		ll u;
		cin >> u;
		u--;
		if (c == 1) {
			cout << dd.bank(u) << '\n';
		} else {
			cout << dd.sep(u) << '\n';
		}
	}
}
