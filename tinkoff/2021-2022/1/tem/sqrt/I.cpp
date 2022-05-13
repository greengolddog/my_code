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
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
typedef int ll;

using namespace std;

const ll INF = 1000000000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct block {
	vector<ll> col;
	ll c = 0;
	block(ll x) {
		col.resize(x, 0);
		c = x;
	}
	ll get() {
		if (c == 0) {
			return -1;
		}
		for (ll i = 0; i < 400; i++) {
			if (col[i] == 0) {
				return i;
			}
		}
		return -1;
	}
	void insert(ll x) {
		c -= col[x] == 0;
		col[x]++;
	}
	void erase(ll x) {
		c += col[x] == 1;
		col[x]--;
	}
};

struct MEX {
	vector<block> arr;
	ll k = 400;
	MEX(ll n = 0) {
		arr = vector<block>(n / k + 1, block(k));
	}
	ll get() {
		ll ans = 0;
		for (auto& i : arr) {
			ll na = i.get();
			ans += (na == -1) * k;
			if (na != -1) {
				ans += na;
				break;
			}
		}
		return ans;
	}
	void insert(ll x) {
		arr[x / k].insert(x % k);
	}
	void erase(ll x) {
		arr[x / k].erase(x % k);
	}
};

struct MO {
	MEX m;
	ll arr[100000];
	ll col[200000];
	vector<pair<ll, ll>> qc;
	vector<ll> ans;
	vector<tuple<ll, ll, ll>> q;
	ll l = 0, r = -1, t = 0, k = 2500;
	MO(ll n, vector<ll> ar, ll mc) {
		for (ll i = 0; i < (ll)ar.size(); i++) {
			arr[i] = ar[i];
		}
		m = MEX(200000);
		for (ll i = 0; i < mc; i++) {
			col[i] = 0;
			m.insert(0);
		}
		m.insert(0);
	}
	void insert(ll x) {
		m.erase(col[x]);
		col[x]++;
		m.insert(col[x]);
	}
	void erase(ll x) {
		m.erase(col[x]);
		col[x]--;
		m.insert(col[x]);
	}
	void move_l(ll x) {
		if (l > x) {
			for (; l > x; l--) {
				insert(arr[l - 1]);
			}
		} else {
			for (; l < x; l++) {
				erase(arr[l]);
			}
		}
	}
	void move_r(ll x) {
		if (r < x) {
			for (; r < x; r++) {
				insert(arr[r + 1]);
			}
		} else {
			for (; r > x; r--) {
				erase(arr[r]);
			}
		}
	}
	void do_change(ll x) {
		ll old = arr[qc[x].first];
		if (qc[x].first >= l && qc[x].first <= r) {
			erase(arr[qc[x].first]);
			insert(qc[x].second);
		}
		arr[qc[x].first] = qc[x].second;
		qc[x].second = old;
	}
	void move_t(ll x) {
		if (t < x) {
			for (; t < x; t++) {
				do_change(t);
			}
		} else {
			for (; t > x; t--) {
				do_change(t - 1);
			}
		}
	}
	void add(ll ql, ll qr) {
		q.push_back({ql, qr, qc.size()});
		ans.push_back(0);
	}
	void change(ll n, ll x) {
		qc.push_back({n, x});
	}
	ll _get(ll ql, ll qr, ll qt) {
		move_l(ql);
		move_r(qr);
		move_t(qt);
		return m.get();
	}
	void end() {
		vector<tuple<ll, ll, ll, ll, ll, ll, ll>> sq;
		for (ll i = 0; i < (ll)q.size(); i++) {
			ll ql = get<0>(q[i]), qr = get<1>(q[i]), qt = get<2>(q[i]);
			sq.push_back({qt / k, ql / k, qr, ql, qr, qt, i});
		}
		sort(sq.begin(), sq.end());
		for (auto i : sq) {
			ans[get<6>(i)] = _get(get<3>(i), get<4>(i), get<5>(i));
		}
	}
	ll get_ans(ll i) {
		return ans[i];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n, 0);
	set<ll> se;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		se.insert(arr[i]);
	}
	vector<tuple<ll, ll, ll>> qu(q);
	for (auto& i : qu) {
		cin >> get<0>(i) >> get<1>(i) >> get<2>(i);
		get<1>(i)--;
		if (get<0>(i) == 1) {
			get<2>(i)--;
		} else {
			se.insert(get<2>(i));
		}
	}
	map<ll, ll> zip;
	ll last = 0;
	for (auto i : se) {
		zip[i] = last;
		last++;
	}
	for (ll i = 0; i < n; i++) {
		arr[i] = zip[arr[i]];
	}
	MO m(n, arr, last);
	ll col = 0;
	for (auto i : qu) {
		if (get<0>(i) == 1) {
			col++;
			m.add(get<1>(i), get<2>(i));
		} else {
			m.change(get<1>(i), zip[get<2>(i)]);
		}
	}
	m.end();
	for (ll i = 0; i < col; i++) {
		cout << m.get_ans(i) << '\n';
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
