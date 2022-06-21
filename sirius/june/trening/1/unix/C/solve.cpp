#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

typedef int ll;

using namespace std;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

bool check(vector<ll> arr, ll p, ll q, vector<ll> col) {
	if (arr.size() == 1) {
		return true;
	}
	vector<ll> c(col.size(), 0);
	if (arr[0] != q) {
		return false;
	}
	if (arr.back() != p) {
		return false;
	}
	for (auto i : arr) {
		if (i < 0 || i >= col.size()) {
			return false;
		}
		c[i]++;
	}
	for (ll i = 0; i < arr.size() - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			return false;
		}
	}
	return c == col;
}

vector<ll> stupid(ll k, ll pp, ll q, vector<ll> arr) {
	pp--;
	q--;
	vector<ll> to, p;
	for (ll i = 0; i < k; i++) {
		ll x = arr[i];
		ll j = 0;
		for (; j < x; j++) {
			to.push_back(i);
			p.push_back(p.size());
		}
	}
	do {
		vector<ll> ans;
		for (ll i = 0; i < p.size(); i++) {
			ans.push_back(to[p[i]]);
		}
		if (ans[0] != pp) {
			continue;
		}
		if (ans.back() != q) {
			continue;
		}
		bool b = true;
		for (ll i = 0; i < p.size() - 1; i++) {
			if (ans[i] == ans[i + 1]) {
				b = false;
				break;
			}
		}
		if (b) {
			return ans;
		}
	} while (next_permutation(p.begin() + 1, p.end() - 1));
	return vector<ll>(1, -1);
}

vector<ll> solve(ll k, ll p, ll q, vector<ll> col) {
	p--;
	q--;
	vector<ll> lc, ic = col;
	ll sum = 0;
	for (ll i = 0; i < k; i++) {
		sum += col[i];
	}
	if (p == q && sum == 2) {
		return vector<ll>(1, -1);
	}
	vector<ll> st(sum, -1);
	st[0] = p;
	st.back() = q;
	if (col[q] == 0 || col[p] == 0) {
		return vector<ll>(1, -1);
	}
	col[p]--;
	col[q]--;
	lc = col;
	for (ll i = 0; i < 1; i++) {
		bool b = true;
		vector<ll> now = st;
		ll last = 1;
		if (p == q) {
			b = false;
		}
		col = lc;
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		last--;
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		vector<pair<ll, ll>> cc;
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		bool bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 2;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i || now[last] != -1) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 2;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 2;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 2;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 2;
		col = lc;
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		last--;
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 3;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		if (last >= sum - 1) {
			last = 1;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc.clear();
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 1;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 1;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 1;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 1;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 2;
		col = lc;
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 3;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		if (last >= sum - 1) {
			last = 1;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc.clear();
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 1;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 1;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 1;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 1;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 1;
		col = lc;
		if (p == q) {
			b = false;
		}
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc.clear();
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 2;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 2;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 2;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 2;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 1;
		if (p == q) {
			b = false;
		}
		col = lc;
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		last--;
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		last--;
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc;
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 2;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 2;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 2;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 2;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 2;
		col = lc;
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		last--;
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 3;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		last--;
		if (last >= sum - 1) {
			last = 1;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc.clear();
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 1;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 1;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 1;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 1;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 2;
		col = lc;
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 3;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		last--;
		if (last >= sum - 1) {
			last = 1;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc.clear();
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 1;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 1;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 1;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 1;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		b = true;
		now = st;
		last = 1;
		col = lc;
		if (p == q) {
			b = false;
		}
		while (col[q] > 0) {
			if (now[last + 1] != q && now[last] != q) {
				now[last] = q;
				col[q]--;
				last += 2;
			} else {
				b = false;
				break;
			}
		}
		while (col[p] > 0 && last < sum - 1) {
			now[last] = p;
			col[p]--;
			last += 2;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		while (col[p] > 0) {
			if (last >= sum - 1) {
				b = false;
				break;
			} else {
				now[last] = p;
				col[p]--;
				last+= 2;
			}
		}
		last--;
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		if (now[last] != -1) {
			last++;
		}
		if (last >= sum - 1) {
			last = 2;
			if (now[last] != -1) {
				last++;
			}
		}
		cc.clear();
		for (ll i = 0; i < k; i++) {
			cc.push_back(make_pair(col[i], i));
		}
		bbb = false;
		while (now[last] != -1) {
			last++;
			if (last >= sum - 1) {
				last = 2;
				if (bbb) {
					break;
				}
				bbb = true;
			}
		}
		sort(cc.begin(), cc.end());
		reverse(cc.begin(), cc.end());
		for (auto[mc, i] : cc) {
			for (ll j = 0; j < mc; j++) {
				if (now[last + 1] == i || now[last - 1] == i) {
					b = false;
					break;
				}
				now[last] = i;
				last += 2;
				if (last >= sum - 1) {
					last = 2;
				}
				bool bb = false;
				while (now[last] != -1) {
					last++;
					if (last >= sum - 1) {
						last = 2;
						if (bb) {
							break;
						}
						bb = true;
					}
				}
				if (last >= sum - 1) {
					last = 2;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b && check(now, q, p, ic)) {
			if (i == 1) {
				reverse(now.begin(), now.end());
			}
			return now;
		}
		swap(q, p);
		reverse(st.begin(), st.end());
	}
	return vector<ll>(1, -1);
}

bool check2(vector<ll> arr, ll q, ll p, vector<ll> col) {
	q--;
	p--;
	if (arr.size() == 1) {
		return true;
	}
	vector<ll> c(col.size(), 0);
	if (arr[0] != q) {
		return false;
	}
	if (arr.back() != p) {
		return false;
	}
	for (auto i : arr) {
		if (i < 0 || i >= col.size()) {
			return false;
		}
		c[i]++;
	}
	for (ll i = 0; i < arr.size() - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			return false;
		}
	}
	return c == col;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool b = true;
	if (b) {
		ll k, q, p;
		cin >> k >> q >> p;
		vector<ll> col(k, 0);
		for (ll i = 0; i < k; i++) {
			cin >> col[i];
		}
		for (auto i : solve(k, q, p, col)) {
			cout << i + 1 << ' ';
		}
		return 0;
	}
	ll x = 0;
	while (true) {
		ll k = 3, sum = rnd32() % 8 + 2;
		ll q = rnd32() % k + 1;
		ll p = rnd32() % k + 1;
		vector<ll> col(k, 0);
		col[q - 1]++;
		col[p - 1]++;
		sum--;
		sum--;
		for (ll i = 0; i < sum; i++) {
			col[rnd32() % k]++;
		}
		cout << k << ' ' << q << ' ' << p << '\n';
		for (auto i : col) {
			cout << i << ' ';
		}
		cout << endl;
		cout << x << endl;
		x++;
		if ((stupid(k, q, p, col).size() != 1 && solve(k, q, p, col).size() == 1) || !check2(solve(k, q, p, col), q, p, col)) {
			cout << k << ' ' << q << ' ' << p << '\n';
			for (auto i : col) {
				cout << i << ' ';
			}
			cout << endl;
			break;
		}
	}
}
