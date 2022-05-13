#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9000000000000000000;

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

struct node {
	ll tree, m;
	node *l = nullptr, *r = nullptr;
	ll ql, qr;
	node(node* v) {
		ql = v->ql;
		qr = v->qr;
		l = v->l;
		r = v->r;
		m = v->m;
		tree = v->tree;
	}
	node(ll ql, ll qr): ql(ql), qr(qr) {
		tree = 0;
		m = 0;
		ll mid = (ql + qr) / 2;
		if (qr - ql > 1) {
			l = new node(ql, mid);
			r = new node(mid, qr);
		}
	}
	void push() {
		if (m == 1) {
			l = new node(l);
			r = new node(r);
			l->change();
			r->change();
		}
	}
	void change() {
		m = 1;
		tree = qr - ql;
	}
	void upd() {
		tree = l->tree + r->tree;
	}
	ll get() {
		return tree;
	}
};

struct segment_tree {
	node* root;
	segment_tree(ll n) {
		ll size = n;
		while (size < n) {
			size *= 2;
		}
		root = new node(0, size);
	}
	ll get(ll l, ll r) {
		return get(root, l, r);
	}
	ll get(node *&v, ll ql, ll qr) {
		v = new node(v);
		if (ql <= v->ql && v->qr <= qr) {
			return v->get();
		}
		if (qr <= v->ql || v->qr <= ql) {
			return 0;
		}
		v->push();
		return get(v->l, ql, qr) + get(v->r, ql, qr);
	}
	void change(ll l, ll r) {
		change(root, l, r);
	}
	void change(node *&v, ll ql, ll qr) {
		v = new node(v);
		if (ql <= v->ql && v->qr <= qr) {
			v = new node(v);
			v->change();
			return;
		}
		if (qr <= v->ql || v->qr <= ql) {
			return;
		}
		change(v->l, ql, qr);
		change(v->r, ql, qr);
		v->upd();
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> q1;
	vector<tuple<ll, ll, ll>> q00, q01;
	vector<ll> arr;
	for (ll i = 0; i < q; i++) {
		ll t;
		cin >> t;
		if (t == 1) {
			ll x;
			cin >> x;
			x--;
			q1.push_back(make_pair(x, q00.size()));
		} else {
			ll l, r, x;
			cin >> l >> r >> x;
			l--;
			if (x == 0) {
				q00.push_back(make_tuple(l, r, q1.size()));
			} else {
				q01.push_back(make_tuple(l, r, x));
				arr.push_back(q1.size());
			}
		}
	}
	ll k = 300;
	segment_tree stz(n);
	segment_tree st = stz;
	for (ll i = 0; i < (q00.size() + k - 1) / k; i++) {
		segment_tree now_st = st;
		vector<tuple<ll, ll, ll>> now(min(k, (ll)(q00.size() - i * k)));
		for (ll j = 0; j < now.size(); j++) {
			now[j] = q00[j + i * k];
		}
		for (auto[l, r, _] : now) {
			now_st.change(l, r);
		}
		vector<ll> check;
		for (ll j = 0; j < q01.size(); j++) {
			auto[l, r, _] = q01[j];
		if (st.get(l, r) != (r - l - 1) && now_st.get(l, r) == (r - l - 1)) {
				check.push_back(j);
			}
		}
		for (auto j : check) {
			segment_tree nst = st;
			auto[ql, qr, __] = q01[j];
			for (ll kk = 0; kk < now.size(); kk++) {
				auto[l, r, qq] = now[kk];
				nst.change(l, r);
				if (nst.get(ql, qr) == (qr - ql - 1)) {
					assign_max(arr[j], qq);
					break;
				}
			}
		}
		st = now_st;
	}
	vector<ll> who(q01.size(), 0);
	for (ll i = 0; i < q01.size(); i++) {
		auto[l, r, _] = q01[i];
		if (st.get(l, r) != (r - l - 1)) {
			arr[i] = q1.size();
		} else {
			ll ql = l, qr = r;
			while (qr - ql > 1) {
				ll mid = (ql + qr) / 2;
				if (st.get(l, mid) == (mid - l)) {
					ql = mid;
				} else {
					qr = mid;
				}
			}
			who[i] = ql;
		}
	}
	vector<bool> ill(n, false);
	vector<pair<ll, ll>> alli;
	for (ll i = 0; i < q01.size(); i++) {
		alli.emplace_back(arr[i], who[i]);
	}
	sort(alli.begin(), alli.end());
	ll u1 = 0, u2 = 0;
	for (ll i = 0; i < q1.size(); i++) {
		auto[x, _] = q1[i];
		while (u1 < alli.size() && alli[u1].first <= i) {
			ill[alli[u1].second] = true;
			u1++;
		}
		while (u2 < q00.size() && get<2>(q00[u2]) <= i) {
			auto[l, r, _] = q00[u2];
			stz.change(l, r);
			u2++;
		}
		if (ill[x]) {
			cout << "YES";
		} else {
			if (stz.get(x, x + 1) == 1) {
				cout << "NO";
			} else {
				cout << "N/A";
			}
		}
		cout << '\n';
	}	
}
/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
