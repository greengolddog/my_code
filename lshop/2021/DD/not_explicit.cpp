#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll to_ll(char c) {
	return c-'a';
}

struct node;

void upd(node *t);

struct node {
	ll p, s = 1, k;
	bool f = false;
	vector<bool> col;
	node *l = nullptr, *r = nullptr;
	node(ll k): k(k), p(rand()*rand()*rand()+rand()*rand()+rand()) {
		col.resize(30, false);
		col[k] = true;
	}
	void to_vector(vector<ll>& arr) {
		upd(this);
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

bool get(node *t, ll c) {
	if (t == nullptr) {
		return false;
	}
	return (t->col)[c];
}

void change(node *t) {
	if (t == nullptr) {
		return;
	}
	t->f = !(t->f);
}

void upd(node *t) {
	if (t->f) {
		swap(t->l, t->r);
		t->f = false;
		change(t->l);
		change(t->r);
	}
	t->s = get(t->l)+get(t->r)+1;
	for (ll i = 0; i < 30; i++) {
		(t->col)[i] = get(t->l, i) || get(t->r, i);
	}
	(t->col)[t->k] = true;
}

pair<node*, node*> split(node* t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	upd(t);
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
	upd(t1);
	upd(t2);
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
	void insert(ll i, ll n, ll x) {
		for (ll i = 0; i < n; i++) {
			insert(i, x);
		}
	}
	void insert(ll i, ll n, char c) {
		insert(i, n, to_ll(c));
	}
	void erase(ll k) {
		auto[t1, t2] = split(root, k);
		auto[t11, t12] = split(t1, k-1);
		root = merge(t11, t2);
		size--;
	}
	void remove(ll i, ll n) {
		auto[t1, t2] = split(root, i);
		auto[t21, t22] = split(t2, n);
		root = merge(t1, t22);
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
	void reverse(ll l, ll r) {
		auto[t1, t2] = split(root, l);
		auto[t21, t22] = split(t2, r-l+1);
		change(t21);
		root = merge(t1, merge(t21, t22));
	}
	ll get_r(ll l, ll r) {
		auto[t1, t2] = split(root, l);
		auto[t21, t22] = split(t2, r-l+1);
		ll ans = 0;
		for (ll i = 0; i < 30; i++) {
			ans += get(t21, i);
		}
		root = merge(t1, merge(t21, t22));
		return ans;
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
	ll n;
	cin >> n;
	cartesian_tree dd;
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll l, r;
			char c2;
			cin >> l >> r >> c2;
			dd.insert(l, r, c2);
		}
		if (c == '-') {
			ll l, r;
			cin >> l >> r;
			dd.remove(l, r);
		}
		if (c == '?') {
			ll l, r;
			cin >> l >> r;
			cout << dd.get_r(l, r) << '\n';
		}
	}
}
