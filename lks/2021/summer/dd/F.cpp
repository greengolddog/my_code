#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

mt19937 rnd(228);

struct node {
	ll k, p = rnd(), s = 1, sum;
	node *l = nullptr, *r = nullptr;
	node(ll k): k(k) {
		sum = k;
	}
};

ll get(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->s;
}

ll get_sum(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->sum;
}

void upd(node *t) {
	t->s = 1+get(t->l)+get(t->r);
	t->sum = t->k+get_sum(t->l)+get_sum(t->r);
}

pair<node*, node*> split(node *t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	if (get(t->l) >= k) {
		auto[l, r] = split(t->l, k);
		t->l = r;
		upd(t);
		return {l, t};
	} else {
		auto[l, r] = split(t->r, k-get(t->l)-1);
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
		node *t = merge(t1->r, t2);
		t1->r = t;
		upd(t1);
		return t1;
	} else {
		node *t = merge(t1, t2->l);
		t2->l = t;
		upd(t2);
		return t2;
	}
}

struct cartezian_tree {
	node *root1 = nullptr, *root2 = nullptr;
	bool f = true;
	cartezian_tree() {}
	void push_back_first(ll x) {
		node *t = new node(x);
		root1 = merge(root1, t);
	}
	void push_back_second(ll x) {
		node *t = new node(x);
		root2 = merge(root2, t);
	}
	void push_back(ll x) {
		if (f) {
			push_back_first(x);
		} else {
			push_back_second(x);
		}
		f = !f;
	}
	void swap(ll l, ll r) {
		ll l1 = (l+1)/2, r1 = (r+1)/2, l2 = l/2, r2 = r/2;
		auto[t11, t12v] = split(root1, l1);
		auto[t12, t13] = split(t12v, r1-l1);
		auto[t21, t22v] = split(root2, l2);
		auto[t22, t23] = split(t22v, r2-l2);
		root1 = merge(merge(t11, t22), t13);
		root2 = merge(merge(t21, t12), t23);
	}
	ll get(ll l, ll r) {
		ll l1 = (l+1)/2, r1 = (r+1)/2, l2 = l/2, r2 = r/2;
		auto[t11, t12v] = split(root1, l1);
		auto[t12, t13] = split(t12v, r1-l1);
		auto[t21, t22v] = split(root2, l2);
		auto[t22, t23] = split(t22v, r2-l2);
		ll ans = get_sum(t12)+get_sum(t22);
		root1 = merge(merge(t11, t12), t13);
		root2 = merge(merge(t21, t22), t23);
		return ans;
	}
};

int main() {
	freopen("swapper.in", "r", stdin);
	freopen("swapper.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, cnt = 1;
	cin >> n >> m;
	while (n != 0 && m != 0) {
		cartezian_tree dd;
		for (ll i = 0; i < n; i++) {
			ll x;
			cin >> x;
			dd.push_back(x);
		}
		cout << "Swapper " << cnt << ':' << '\n';
		for (ll i = 0; i < m; i++) {
			ll c, x, y;
			cin >> c >> x >> y;
			x--;
			if (c == 1) {
				dd.swap(x, y);
			} else {
				cout << dd.get(x, y) << '\n';
			}
		}
		cnt++;
		cin >> n >> m;
	}
}
