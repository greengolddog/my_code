#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct Node {
	ll l, r, sum, x;
	Node(ll x): l(-1), r(-1), sum(x), x(x) {}
};

struct segment_tree {
	vector<Node> arr;
	ll la = 0, ra = 1000000001;
	segment_tree() {
		arr.push_back(Node(0));
	}
	ll get(ll l, ll r) {
		return get(0, la, ra, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (v == -1) {
			return 0;
		}
		if (ql >= r || l >= qr) {
			return 0;
		}
		if (ql <= l && r <= qr) {
			return arr[v].sum;
		}
		ll mid = (l+r)/2;
		return get(arr[v].l, l, mid, ql, qr)+get(arr[v].r, mid, r, ql, qr);
	}
	void change(ll v) {
		change(0, la, ra, v);
	}
	void change(ll v, ll l, ll r, ll n) {
		if (n >= r || l > n) {
			return;
		}
		if (r - l == 1) {
			arr[v].x = n;
			arr[v].sum = n;
			return;
		}
		ll mid = (l+r)/2;
		arr[v].sum = arr[v].x;
		if (arr[v].l == -1) {
			if (n < mid && n >= l) {
				arr[v].l = arr.size();
				arr.push_back(Node(0));
				change(arr[v].l, l, mid, n);
				arr[v].sum += arr[arr[v].l].sum;
			}
		} else {
			change(arr[v].l, l, mid, n);
			arr[v].sum += arr[arr[v].l].sum;
		}
		if (arr[v].r == -1) {
			if (n < r && n >= mid) {
				arr[v].r = arr.size();
				arr.push_back(Node(0));
				change(arr[v].r, mid, r, n);
				arr[v].sum += arr[arr[v].r].sum;
			}
		} else {
			change(arr[v].r, mid, r, n);
			arr[v].sum += arr[arr[v].r].sum;
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	segment_tree seg;
	bool f = false;
	ll la = 0;
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll x;
			cin >> x;
			if (f) {
				x = (x+la)%1000000000;
			}
			f = false;
			seg.change(x);
		} else {
			ll l, r;
			cin >> l >> r;
			la = seg.get(l, r+1);
			f = true;
			cout << la << '\n';
		}
	}
}
