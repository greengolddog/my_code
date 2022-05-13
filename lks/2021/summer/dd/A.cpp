#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

mt19937 rnd(228);

const ll INF = 1'000'000'000'000'000;

struct node {
	ll k, p;
	node *l = nullptr, *r = nullptr;
	node(ll k, ll p = rnd()): k(k), p(p) {}
};

pair<node*, node*> split(node *t, ll x) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	if (t->k > x) {
		auto[l, r] = split(t->l, x);
		t->l = r;
		return {l, t};
	} else {
		auto[l, r] = split(t->r, x);
		t->r = l;
		return {t, r};
	}
};

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
		return t1;
	} else {
		auto t = merge(t1, t2->l);
		t2->l = t;
		return t2;
	}
}

struct cartesian_tree {
	node *root = nullptr;
	cartesian_tree(){}
	cartesian_tree(node *root): root(root) {}
	bool exist(ll x) {
		auto[t1, t2] = split(root, x);
		auto[t11, t12] = split(t1, x-1);
		bool f = t12 != nullptr;
		t1 = merge(t11, t12);
		root = merge(t1, t2);
		return f;
	}
	void insert(ll x) {
		if (!exist(x)) {
			node *t = new node(x);
			auto[t1, t2] = split(root, x);
			t1 = merge(t1, t);
			root = merge(t1, t2);
		}
	}
	void erase(ll x) {
		auto[t1, t2] = split(root, x);
		auto[t11, t12] = split(t1, x-1);
		root = merge(t11, t2);
	}
	ll prev(ll x) {
		auto[l, r] = split(root, x-1);
		node *t = new node(-INF);
		t->r = l;
		while (t->r != nullptr) {
			t = t->r;
		}
		ll ans = t->k;
		root = merge(l, r);
		return ans;
	}
	ll next(ll x) {
		auto[l, r] = split(root, x);
		node *t = new node(INF);
		t->l = r;
		while (t->l != nullptr) {
			t = t->l;
		}
		ll ans = t->k;
		root = merge(l, r);
		return ans;
	}
};

int main() {
	freopen("bst.in", "r", stdin);
	freopen("bst.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cartesian_tree dd;
	string c;
	while (cin >> c) {
		ll x;
		cin >> x;
		if (c == "insert") {
			dd.insert(x);
		}
		if (c == "delete") {
			dd.erase(x);
		}
		if (c == "exists") {
			cout << (dd.exist(x) ? "true" : "false") << '\n';
		}
		if (c == "next") {
			ll ans = dd.next(x);
			cout << (ans == INF ? "none" : to_string(ans)) << '\n';
		}
		if (c == "prev") {
			ll ans = dd.prev(x);
			cout << (ans == -INF ? "none" : to_string(ans)) << '\n';
		}
		//cout << endl;
	}
}
