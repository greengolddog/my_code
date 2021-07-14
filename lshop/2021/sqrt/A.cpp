#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1000000000000000;

template<typename T>
void minr(T& a, const T& b) {
	a = min(a, b);
}

template<typename T>
void maxr(T& a, const T& b) {
	a = max(a, b);
}

struct block {
	vector<ll> arr;
	ll size, min;
	block(vector<ll> arr = vector<ll>(0, 0)): arr(arr) {
		size = arr.size();
		min = INF;
		for (auto i : arr) {
			minr(min, i);
		}
	}
	ll get(ll l, ll r) {
		maxr(l, 0ll);
		minr(r, size);
		if (l == 0 && r == size) {
			return min;
		}
		ll now = INF;
		for (ll i = l; i < r; i++) {
			minr(now, arr[i]);
		}
		return now;
	}
	void change(ll n, ll x) {
		if (n < 0 || n >= size) {
			return;
		}
		arr[n] = x;
		min = INF;
		for (auto i : arr) {
			minr(min, i);
		}
	}
};

struct RMQ {
	vector<block> all;
	ll size, k = 700;
	RMQ(vector<ll> arr) {
		size = arr.size();
		for (ll i = 0; i < size; i += k) {
			vector<ll> now;
			for (ll j = i; j < min(size, i+k); j++) {
				now.push_back(arr[j]);
			}
			all.push_back(block(now));
		}
	}
	ll get(ll l, ll r) {
		ll ans = INF;
		for (auto& i : all) {
			minr(ans, i.get(l, r));
			l -= i.size;
			r -= i.size;
		}
		return ans;
	}
	void change(ll n, ll x) {
		for (auto& i : all) {
			i.change(n, x);
			n -= i.size;
		}
	}
};


int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	RMQ s(arr);
	string c;
	while (cin >> c) {
		if (c == "min") {
			ll l, r;
			cin >> l >> r;
			cout << s.get(l-1, r) << '\n';
		} else {
			ll i, j;
			cin >> i >> j;
			s.change(i-1, j);
		}
	}
}
