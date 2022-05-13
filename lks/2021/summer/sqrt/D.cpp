#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct block {
	vector<ll> arr;
	ll sum = 0;
	block(vector<ll>& a) {
		swap(a, arr);
		for (auto& i : arr) {
			sum += i;
		}
	}
	block() {
		arr.push_back(-1);
		sum = -1;
	}
	ll get(ll l, ll r) {
		if (l <= arr[0] && arr.back() <= r) {
			return sum;
		}
		if (arr.back() < l || r < arr[0]) {
			return 0;
		}
		ll ans = 0;
		for (auto& i : arr) {
			if (l <= i && i <= r) {
				ans += i;
			}
		}
		return ans;
	}
	bool insert(ll x) {
		if (x > arr.back()) {
			return false;
		}
		auto it = arr.begin();
		for (; *it < x; it++) {}
		if (*it != x) {
			arr.insert(it, x);
			sum += x;
		}
		return true;
	}
	void push_back(ll x) {
		arr.push_back(x);
		sum += x;
	}
	ll operator[](ll n) {
		return arr[n];
	}
	ll size() {
		return arr.size();
	}
};

struct sqrt_d {
	vector<block> arr;
	ll k = 500, cnt = 0, s = 0;
	sqrt_d() {
		arr.emplace_back();
	}
	void insert(ll x) {
		insert_h(x);
		if (cnt == k) {
			rebuild();
		}
	}
	void insert_h(ll x) {
		s++;
		cnt++;
		for (auto& i : arr) {
			if (i.insert(x)) {
				return;
			}
		}
		arr.back().push_back(x);
	}
	ll get(ll l, ll r) {
		ll ans = 0;
		for (auto& i : arr) {
			ans += i.get(l, r);
		}
		return ans;
	}
	void rebuild() {
		vector<ll> a(0, 0);
		for (auto& i : arr) {
			for (ll j = 0; j < i.size(); j++) {
				a.push_back(i[j]);
			}
		}
		arr.resize(0);
		vector<ll> v(0, 0);
		for (auto& i : a) {
			v.push_back(i);
			if (v.size() == k) {
				arr.emplace_back(v);
			}
		}
		if (v.size() != 0) {
			arr.emplace_back(v);
		}
		cnt = 0;
	}
	ll size() {
		return s;
	}
};

int main() {
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	sqrt_d s;
	ll lz = 0;
	bool pz = false;
	for (ll _ = 0; _ < n; _++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll x;
			cin >> x;
			if (pz) {
				x = (x+lz)%1000000000;
			}
			s.insert(x);
			pz = false;
		} else {
			ll l, r;
			cin >> l >> r;
			pz = true;
			lz = s.get(l, r);
			cout << lz << '\n';
		}
	}
}
