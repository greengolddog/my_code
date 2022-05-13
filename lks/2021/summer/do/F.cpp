#include <bits/stdc++.h>
typedef int ll;

using namespace std;

struct node {
	ll sum, num = 0;
	node *l = nullptr, *r = nullptr;
	node(ll sum, ll num): sum(sum), num(num) {}
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
			return new node(arr[l], l);
		}
		ll mid = (l + r) / 2;
		return new node(build(arr, l, mid), build(arr, mid, r));
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
			return new node(v->sum+x, v->num);
		}
		ll mid = (l + r) / 2;
		return new node(change(v->l, l, mid, n, x), change(v->r, mid, r, n, x));
	}
	ll get(ll l, ll r, segment_tree& s, ll k) {
		return get(root, s.root, 0, size, l, r, k);
	}
	ll get(node *v, node *u, ll l, ll r, ll ql, ll qr, ll k) {
		if (r - l == 1) {
			return v->num;
		}
		ll mid = (l+r)/2;
		ll now = abs(get(v->l, l, mid, ql, qr) - get(u->l, l, mid, ql, qr));
		if (k <= now) {
			return get(v->l, u->l, l, mid, ql, qr, k);
		} else {
			return get(v->r, u->r, mid, r, ql, qr, k - now);
		}
	}
};

struct pdo {
	vector<segment_tree> arr;
	ll size;
	pdo(vector<ll> a) {
		arr.emplace_back(a);
		size = arr[0].size;
	}
	ll get(ll l, ll r, ll k) {
		return arr[r].get(0, size, arr[l], k);
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
	//freopen("kth.in", "r", stdin);
	//freopen("kth.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const ll mod = 1'000'000'000;
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	cin >> arr[0];
	long long l, m;
	cin >> l >> m;
	for (ll i = 1; i < n; i++) {
		arr[i] = (arr[i - 1] * l + m) % mod;
	}
	vector<ll> a = arr;
	sort(a.begin(), a.end());
	map<ll, ll> zip, unzip;
	ll cnt = 0;
	for (auto i : a) {
		if (zip.find(i) == zip.end()) {
			zip[i] = cnt;
			unzip[cnt] = i;
			cnt++;
		}
	}
	for (ll i = 0; i < n; i++) {
		arr[i] = zip[arr[i]];
	}
	pdo st(vector<ll>(cnt, 0));
	for (auto i : arr) {
		st.change_back(i, 1);
	}
	ll b;
	cin >> b;
	long long ans = 0;
	for (ll _ = 0; _ < b; _++) {
		ll g;
		cin >> g;
		vector<ll> x(g, 0), y(g, 0), i(g, 0), j(g, 0), k(g, 0);
		long long lx, mx, ly, my, lk, mk;
		cin >> x[0] >> lx >> mx >> y[0] >> ly >> my >> k[0] >> lk >> mk;
		i[0] = min(x[0], y[0]);
		j[0] = max(x[0], y[0]);
		for (ll f = 1; f < g; f++) {
			x[f] = (((i[f - 1] - 1) * lx + mx) % n) + 1;
			y[f] = (((j[f - 1] - 1) * ly + my) % n) + 1;
			i[f] = min(x[f], y[f]);
			j[f] = max(x[f], y[f]);
			k[f] = (((k[f - 1] - 1) * lk + mk) % (j[f] - i[f] + 1)) + 1;
		}
		for (ll f = 0; f < g; f++) {
			//cout << unzip[st.get(i[f] - 1, j[f], k[f])] << endl;
			ans += unzip[st.get(i[f] - 1, j[f], k[f])];
		}
	}
	cout << ans;
}
