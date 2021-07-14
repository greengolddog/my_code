#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct node {
	ll p, s = 1, k;
	node *l = nullptr, *r = nullptr;
	node(ll k): k(k), p(rand()*rand()*rand()+rand()*rand()+rand()) {}
	void to_vector(vector<ll>& arr) {
		if (l != nullptr) {
			l->to_vector(arr);
		}
		arr.push_back(k);
		if (r != nullptr) {
			r->to_vector(arr);
		}
	}
};

ll get(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->s;
}

void upd(node *t) {
	t->s = get(t->l)+get(t->r)+1;
}

pair<node*, node*> split(node* t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	ll s = get(t->l);
	if (s >= k) {
		auto[t1, t2] = split(t->l, k);
		t->l = t2;
		upd(t);
		return {t1, t};
	} else {
		auto[t1, t2] = split(t->r, k-s-1);
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
	ll size = 0;
	cartesian_tree(node *root): root(root) {}
	cartesian_tree() {
		root = nullptr;
	}
	void insert(ll k, ll x) {
		node *t = new node(x);
		auto[t1, t2] = split(root, k);
		root = merge(merge(t1, t), t2);
		size++;
	}
	void erase(ll k) {
		auto[t1, t2] = split(root, k);
		auto[t11, t12] = split(t1, k-1);
		root = merge(t11, t2);
		size--;
	}
	void push_back(ll x) {
		node *t = new node(x);
		root = merge(root, t);
	}
	void to_begin(ll l, ll r) {
		auto[t1, t2] = split(root, l);
		auto[t21, t22] = split(t2, r-l+1);
		root = merge(merge(t21, t1), t22);
	}
	vector<ll> to_vector() {
		vector<ll> arr;
		root->to_vector(arr);
		return arr;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	srand(time(0));
	ll n, m;
	cin >> n >> m;
	cartesian_tree dd;
	for (ll i = 0; i < n; i++) {
		dd.push_back(i+1);
	}
	for (ll i = 0; i < m; i++) {
		ll r, l;
		cin >> l >> r;
		l--;
		r--;
		dd.to_begin(l, r);
	}
	vector<ll> ans = dd.to_vector();
	for (auto i : ans) {
		cout << i << ' ';
	}
}
