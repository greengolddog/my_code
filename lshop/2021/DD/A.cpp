#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct node {
	ll k, p, sum;
	node *l = nullptr, *r = nullptr;
	node(ll k): k(k), p(rand()*rand()*rand()+rand()*rand()+rand()), sum(k) {}
};

ll get(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->sum;
}

void upd(node *t) {
	t->sum = t->k+get(t->l)+get(t->r);
}

pair<node*, node*> split(node* t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	if (t->k > k) {
		auto[t1, t2] = split(t->l, k);
		t->l = t2;
		upd(t);
		return {t1, t};
	} else {
		auto[t1, t2] = split(t->r, k);
		t->r = t1;
		upd(t);
		return {t, t2};
	}
}

node* merge(node* t1, node* t2) {
	if (t1 == nullptr) {
		return t2;
	}
	if (t2 == nullptr) {
		return t1;
	}
	if (t1->p > t2->p) {
		auto tn = merge(t1->r, t2);
		t1->r = tn;
		upd(t1);
		return t1;
	} else {
		auto tn = merge(t1, t2->l);
		t2->l = tn;
		upd(t2);
		return t2;
	}
}

struct cartesian_tree {
	node *root;
	cartesian_tree(node *root): root(root) {}
	cartesian_tree() {
		root = nullptr;
	}
	bool is_in(ll k) {
		auto[t1, t2] = split(root, k-1);
		auto[t21, t22] = split(t2, k);
		bool isin = (t21 != nullptr);
		merge(t1, merge(t21, t22));
		return isin;
	}
	void insert(ll k) {
		if (is_in(k)) {
			return;
		}
		node *t = new node(k);
		auto[t1, t2] = split(root, k);
		root = merge(merge(t1, t), t2);
	}
	void erase(ll k) {
		auto[t1, t2] = split(root, k);
		auto[t11, t12] = split(t1, k-1);
		root =  merge(t11, t2);
	}
	ll get_sum(ll l, ll r) {
		auto[t1, t2] = split(root, l-1);
		auto[t21, t22] = split(t2, r);
		ll ans = get(t21);
		merge(t1, merge(t21, t22));
		return ans;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	srand(time(0));
	ll n;
	cin >> n;
	cartesian_tree dd;
	ll la = 0;
	bool b = false;
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll x;
			cin >> x;
			if (b) {
				x = (x+la)%1000000000;
				b = !b;
			}
			dd.insert(x);
		} else {
			ll l, r;
			cin >> l >> r;
			b = true;
			la = dd.get_sum(l, r);
			cout << la << '\n';
		}
	}
}
