#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct block {
	vector<ll> arr;
	ll sum = 0;
	block(vector<ll>& arr): arr(arr) {
		for (auto& i : arr) {
			sum += i;
		}
	}
	ll size() {
		return arr.size();
	}
	ll get(ll l, ll r) {
		l = max(l, 0ll);
		r = min(r, size());
		if (l == 0 && r == size()) {
			return sum;
		}
		ll ans = 0;
		for (ll i = l; i < r; i++) {
			ans += arr[i];
		}
		return ans;
	}
	void change(ll x, ll pos) {
		if (pos >= 0 && pos < size()) {
			sum -= arr[pos];
			sum += x;
			arr[pos] = x;
		}
	}
	ll operator[](ll pos) {
		if (pos >= 0 && pos < size()) {
			return arr[pos];
		}
		return 0;
	}
};

struct sqrt_dec {
	vector<block> arr;
	ll s = 0, k = 300;
	sqrt_dec(vector<ll> a) {
		s = a.size();
		vector<ll> v(0, 0);
		for (auto i : a) {
			v.push_back(i);
			if (v.size() == k) {
				arr.emplace_back(v);
				v = vector<ll>(0, 0);
			}
		}
		if (v.size() > 0) {
			arr.emplace_back(v);
		}
	}
	ll get(ll l, ll r) {
		ll ans = 0;
		for (auto& i : arr) {
			ans += i.get(l, r);
			l -= i.size();
			r -= i.size();
		}
		return ans;
	}
	void change(ll x, ll pos) {
		for (auto& i : arr) {
			i.change(x, pos);
			pos -= i.size();
		}
	}
	ll size() {
		return s;
	}
};

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	sqrt_dec s(vector<ll>(n, 0));
	for (ll i = 0; i < k; i++) {
		char c;
		cin >> c;
		ll l, r;
		cin >> l >> r;
		if (c == 'A') {
			s.change(r, l-1);
		} else {
			cout << s.get(l-1, r) << '\n';
		}
	}
}
