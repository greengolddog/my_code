#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct heap {
	vector<ll> h;
	heap(vector<ll> h): h(h) {}
	ll ShiftUp(ll num) {
		ll now = num;
		while (now != 1) {
			if (h[now] > h[now / 2]) {
				swap(h[now], h[now / 2]);
				now = now / 2;
			} else {
				break;
			}
		}
		return now;
	}
	ll ShiftDown(ll num) {
		ll now = num;
		while (num*2 <= h.size()-1) {
			if (num*2 == h.size()-1) {
				if (h[num] < h[num*2]) {
					swap(h[num], h[num*2]);
					num = num*2;
				}
				break;
			} else {
				if (h[num] < max(h[num*2], h[num*2+1])) {
					if (h[num*2] >= h[num*2+1]) {
						swap(h[num*2], h[num]);
						num = num*2;
					} else {
						swap(h[num*2 + 1], h[num]);
						num = num*2 + 1;
					}
				} else {
					break;
				}
			}
		}
		return num;
	}
	ll add_to_element(ll el, ll add) {
		h[el] += add;
		return ShiftUp(el);
	}
	ll sub_to_element(ll el, ll add) {
		h[el] -= add;
		return ShiftDown(el);
	}
	pair<ll, ll> extract_max() {
		pair<ll, ll> pa = {h[1], 0};
		h[1] = h[h.size()-1];
		h.pop_back();
		pa.second = ShiftDown(1);
		return pa;
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
	for (ll i = 1; i < n; i++) {
		auto maxx = he.extract_max();
		cout << maxx.second << ' ' << maxx.first << endl;
	}
}
