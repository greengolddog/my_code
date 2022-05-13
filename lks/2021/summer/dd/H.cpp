#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
typedef int ll;

using namespace std;

mt19937 rnd(time(0));

ll z = 0;

bitset<10000> emp;

struct node {
	ll k, p = rnd(), s = 1;
	bitset<10000> arr;
	node *l = nullptr, *r = nullptr;
	node(ll& k): k(k) {
		arr[k] = 1;
	}
};

ll& get_s(node *t) {
	if (t == nullptr) {
		return z;
	}
	return t->s;
}

bitset<10000>& get_b(node *t) {
	if (t == nullptr) {
		return emp;
	}
	return t->arr;
}

void upd(node *t) {
	t->s = 1+get_s(t->l)+get_s(t->r);
	t->arr = get_b(t->l)|get_b(t->r);
	t->arr[t->k] = 1;
}

pair<node*, node*> split(node *t, ll k) {
	if (t == nullptr) {
		return {nullptr, nullptr};
	}
	if (get_s(t->l) >= k) {
		auto[t1, t2] = split(t->l, k);
		t->l = t2;
		upd(t);
		return {t1, t};
	} else {
		auto[t1, t2] = split(t->r, k-get_s(t->l)-1);
		t->r = t1;
		upd(t);
		return {t, t2};
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

ll num = 0;

struct cartezian_tree {
	node *root = nullptr;
	ll s = 0;
	cartezian_tree(){}
	void push_back(ll& x) {
		node *t = new node(x);
		root = merge(root, t);
		s++;
	}
	void swap(ll& l1, ll& r1, ll& l2, ll& r2) {
		auto[t1, t2v] = split(root, l1);
		auto[t2, t3v] = split(t2v, r1-l1);
		auto[t3, t4v] = split(t3v, l2-r1);
		auto[t4, t5] = split(t4v, r2-l2);
		root = merge(merge(t1, merge(t4, t3)), merge(t2, t5));
	}
	ll& operator[](ll x) {
		node *now = root;
		while (true) {
			if (get_s(now->l)+1 == x) {
				break;
			}
			if (get_s(now->l) >= x) {
				now = now->l;
			} else {
				x -= get_s(now->l)+1;
				now = now->r;
			}
		}
		return now->k;
	}
	void get(ll& x) {
		node *now = root;
		num = 0;
		while (now->k != x) {
			if (get_b(now->l)[x]) {
				now = now->l;
			} else {
				num += get_s(now->l)+1;
				now = now->r;
			}
		}
		num += get_s(now->l);
	}
	ll& size() {
		return s;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	cartezian_tree dd;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		dd.push_back(x);
	}
	for (ll i = 0; i < q; i++) {
		ll c;
		cin >> c;
		if (c == 2) {
			ll x;
			cin >> x;
			x--;
			dd.get(x);
			cout << (dd.size() > num+1 ? dd[num+2]+1 : -1) << ' ' << (dd.size() > num+2 ? dd[num+3]+1 : -1) << ' ' << (dd.size() > num+3 ? dd[num+4]+1 : -1) << '\n';
		} else {
			ll l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			l1--;
			l2--;
			dd.swap(l1, r1, l2, r2);
		}
	}
}
