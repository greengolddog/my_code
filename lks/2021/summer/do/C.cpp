#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll sum(ll a, ll b, ll mod) {
	if (a + b >= mod) {
		return a + b - mod;
	}
	return a + b;
}

ll mul(ll a, ll b, ll mod) {
	return a * b % mod;
}

struct hdo {
	ll p = 57, m = 1'000'000'007;
	vector<ll> tree, pow;
	ll size;
	hdo(vector<ll> arr) {
		ll n = 1;
		while (n < arr.size()) {
			n *= 2;
		}
		arr.resize(n, 0);
		pow.resize(1, 1);
		for (ll i = 0; i < n; i++) {
			pow.push_back(mul(pow.back(), p, m));
		}
		tree.resize(n * 2, 0);
		size = n;
		build(arr, 0, size, 1);
	}
	void build(vector<ll>& arr, ll l, ll r, ll v) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) /2;
		build(arr, l, mid, v * 2);
		build(arr, mid, r, v * 2 + 1);
		tree[v] = sum(mul(tree[v * 2], pow[r - mid], m), tree[v * 2 + 1], m);
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		ll mid = (l + r) / 2;
		return sum(mul(get(v * 2, l, mid, ql, qr), pow[max(0ll, min(r, qr)-mid)], m), get(v * 2 + 1, mid, r, ql, qr), m);
	}
	void change(ll n, ll x) {
		change(1, 0, size, n, x);
	}
	void change(ll v, ll l, ll r, ll n, ll x) {
		if (n < l || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = x;
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, n, x);
		change(v * 2 + 1, mid, r, n, x);
		tree[v] = sum(mul(tree[v * 2], pow[r - mid], m), tree[v * 2 + 1], m);
	}
};

int main() {
	freopen("substring-palindromes.in", "r", stdin);
	freopen("substring-palindromes.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector<ll> arr;
	ll n = s.size();
	for (auto i : s) {
		arr.push_back((ll)i);
	}
	vector<ll> arr2 = arr;
	reverse(arr2.begin(), arr2.end());
	hdo do1(arr), do2(arr2);
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		string c;
		cin >> c;
		if (c == "palindrome?") {
			ll l, r;
			cin >> l >> r;
			l--;
			if (do1.get(l, r) == do2.get(n - r, n - l)) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		} else {
			ll x;
			char c;
			cin >> x >> c;
			x--;
			do1.change(x, (ll)c);
			do2.change(n - x - 1, (ll)c);
		}
	}
}
