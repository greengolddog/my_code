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

mt19937 rnd(time(0));

struct node {
	node *l = nullptr, *r = nullptr;
	ll p = rnd(), k = 0, sz = 1, maxx = 0, nx = 0, p = 0;
	node(ll k, ll nx = 0): k(k), nx(nx) {
		maxx = nx;
	}
	node(node *t) {
		l = t->l;
		r = t->r;
		p = t->p;
		k = t->k;
		sz = t->sz;
		maxx = t->maxx;
		mx = t->nx;
		p = t->p;
	}
};

ll gets(node *t) {
	return (t == nullptr ? 0 : t->sz);
}

ll getx(node *t) {
	return (t == nullptr ? 0 : t->maxx);
}

void push(node *t) {
	if (t->l != nullptr) {
		t->l->k += t->p;
		t->l->p += t->p;
	}
	if (t->r != nullptr) {
		t->r->l += t->p;
		t->r->p += t->p;
	}
	t->p = 0;
}

void upd(node *t) {
	t->sz = gets(t->l) + gets(t->r) + 1;
	t->maxx = max(max(getx(t->l), getx(t->r)), t->nx);
}

pair<node*, node*> split(node *t, ll k) {
	if (t == nullptr) {
		return make_pair(nullptr, nullptr);
	}
	if (t->k <= k) {
		auto[l, r] = split(t->r, k);
		t->r = l;
		upd(t);
		return make_pair(t, r);
	} else {
		auto[l, r] = split(t->l, k);
		t->l = r;
		upd(t);
		return make_pair(l, t);
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
	node *root;
	cartezian_tree() {
		root = nullptr;
	}
	void insert(ll x, ll nx = 0) {
		node *t = new node(x, nx);
		auto[t1, t2] = split(root, x);
		root = merge(merge(t1, t), t2);
	}
	ll get(ll l, ll r) {
		auto[t1, t2] = split(root, r);
		auto[t11, t12] = split(t1, l - 1);
		ll ans = gets(t12);
		root = merge(merge(t11, t12), t2);
		return ans;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, e;
	cin >> n >> e;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll add = 0, cole = 0, ans = 0;
	cartezian_tree cs;
	cs.insert(0);
	for (ll i = 0; i < n; i++) {
		if (arr[i] == e) {
			ll nb = 0;
			ans += cs.get(add, add);
			for (ll j = i + 1; j < n && arr[j] != e; j++) {
				nb += arr[j] > e;
				nb -= arr[j] < e;
				ans += cs.get(add + nb, add + nb);
			}
		}
		add += arr[i] > e;
		add -= arr[i] < e;
		cs.insert(add);
	}
	cout << ans;
}
