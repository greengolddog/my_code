#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct heap {
	vector<ll> h;
	heap(vector<ll> h): h(h) {}
	void ShiftUp(ll num) {
		ll now = num;
		while (now != 1) {
			if (h[now] > h[now / 2]) {
				swap(h[now], h[now / 2]);
				now = now / 2;
			} else {
				break;
			}
		}
		cout << now << endl;
	}
	void add_to_element(ll el, ll add) {
		h[el] += add;
		ShiftUp(el);
	}
	friend ostream& operator<< (ostream& out, heap p);
};

ostream& operator<< (ostream& out, heap p) {
	for (ll i = 1; i < p.h.size(); i++) {
		out << p.h[i] << ' ';
	}
	cout << endl;
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> h(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> h[i];
	}
	heap he(h);
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll c, a;
		cin >> c >> a;
		he.add_to_element(c, a);
	}
	cout << he;
}
