#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, MAXK = 200'001;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

bool check(ll a1, ll b1, ll a2, ll b2, ll x) {
	return (a1 + b1 * x) > (a2 + b2 * x);
}

struct node {
	ll a, b;
	ll lx, rx;
	node *l = nullptr, *r = nullptr;
	node(ll lx, ll rx, ll a = -INF64, ll b = 0): lx(lx), rx(rx), a(a), b(b), l(l), r(r) {
		if (rx - lx != 1) {
			ll mid = (lx + rx) / 2;
			l = new node(lx, mid, a, b);
			r = new node(mid, rx, a, b);
		}
	}
	node(node *n) {
		lx = n->lx;
		rx = n->rx;
		a = n->a;
		b = n->b;
		l = n->l;
		r = n->r;
	}
	ll get(ll x) {
		if (rx - lx == 1) {
			return a + b * x;
		}
		ll mid = (lx + rx) / 2;
		ll qa = -INF64;
		if (mid > x) {
			qa = l->get(x);
		} else {
			qa = r->get(x);
		}
		return max(a + b * x, qa);
	}
	node *add(ll na, ll nb) {
		node* n = new node(this);
		if (rx - lx == 1) {
			if (na + nb * lx > a + b * lx) {
				n->a = na;
				n->b = nb;
			}
			return n;
		}
		ll mid = (lx + rx) / 2;
		bool b1 = check(na, nb, a, b, lx), b2 = check(na, nb, a, b, mid - 1), b3 = check(na, nb, a, b, mid), b4 = check(na, nb, a, b, rx - 1);
		if (b1 + b2 + b3 + b4 > 2) {
			swap(n->a, na);
			swap(n->b, nb);
			b1 = !b1;
			b4 = !b4;
		}
		if (b1) {
			n->l = l->add(na, nb);
		}
		if (b4) {
			n->r = r->add(na, nb);
		}
		return n;
	}
};

struct li_chao {
	node *root;
	li_chao(ll n) {
		root = new node(0, n);
	}
	ll get(ll x) {
		return root->get(x);
	}
	void add(ll na, ll nb) {
		root = root->add(na, nb);
	}
};

void solve() {
	ll n, m;
	cin >> n >> m;
	li_chao emp(MAXK);
	vector<li_chao> arr(n, emp);
	for (ll i = 0; i < m; i++) {
		char c;
		cin >> c;
		if (c == '#') {
			ll t, v;
			cin >> t >> v;
			t--;
			v--;
			arr[v] = arr[t];
		}
		if (c == '+') {
			ll t, a, b;
			cin >> t >> a >> b;
			t--;
			arr[t].add(-a, b);
		}
		if (c == '?') {
			ll t, k;
			cin >> t >> k;
			t--;
			cout << arr[t].get(k) << '\n';
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
