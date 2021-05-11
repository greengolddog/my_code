#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct block {
	vector<ll> arr;
	ll minn = 1000000000000, len;
	block(vector<ll> arra = vector<ll>(0, 0)) {
		arr = arra;
		len = arr.size();
		for (ll i = 0; i < len; i++) {
			minn = min(minn, arr[i]);
		}
	}
	ll get_min(ll a, ll b) {
		if ((a == 0) && (b == len - 1)) {
			return minn;
		}
		ll min_now = 1000000000000;
		for (ll i = a; i <= b; i++) {
			min_now = min(min_now, arr[i]);
		}
		return min_now;
	}
	void add(ll a, ll b) {
		arr.insert(arr.begin()+a, b);
		minn = min(minn, b);
		len++;
	}
	ll operator[](ll a) {
		return arr[a];
	}
};

struct sqrt_min {
	vector<block> arr;
	ll len = 0, k = 400, stc = 0;
	sqrt_min(vector<ll> arra = vector<ll>(1, 0)) {
		vector<ll> bl(0, 0);
		for (ll i = 0; i < arra.size(); i++) {
			bl.push_back(arra[i]);
			if (i % k == k-1) {
				len++;
				arr.push_back(block(bl));
				bl = vector<ll>(0, 0);
			}
		}
		if (bl.size() > 0) {
			len++;
			arr.push_back(block(bl));
		}
	}
	void add(ll a, ll b) {
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				arr[i].add(a, b);
			}
			a -= arr[i].len;
		}
		stc++;
		if (stc == k) {
			per();
			stc = 0;
		}
	}
	void per() {
		vector<ll> arra(0, 0);
		for (ll i = 0; i < len; i++) {
			for (ll j = 0; j < arr[i].len; j++) {
				arra.push_back(arr[i][j]);
			}
		}
		len = 0;
		arr = vector<block>(0, block());
		vector<ll> bl(0, 0);
		for (ll i = 0; i < arra.size(); i++) {
			bl.push_back(arra[i]);
			if (i % k == k-1) {
				len++;
				arr.push_back(block(bl));
				bl = vector<ll>(0, 0);
			}
		}
		if (bl.size() > 0) {
			len++;
			arr.push_back(block(bl));
		}
	}
	ll get_min(ll a, ll b) {
		ll ans = 1000000000000, z = 0;
		for (ll i = 0; i < len; i++) {
			ans = min(ans, arr[i].get_min(max(a, z), min(b, arr[i].len - 1)));
			a -= arr[i].len;
			b -= arr[i].len;
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll m;
	cin >> m;
	sqrt_min s(vector<ll>(1, 0));
	for (ll i = 0; i < m; i++) {
		char com;
		cin >> com;
		ll x, y;
		cin >> x >> y;
		if (com == '+') {
			s.add(x, y);
		} else {
			cout << s.get_min(x - 1, y - 1) << "\n";
		}
	}
}
