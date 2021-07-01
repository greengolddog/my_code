#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct d {
	ll l, r, i;
	d(ll l = 0, ll r = 0, ll i = 0): l(l), r(r), i(i) {};
	bool operator< (d dd) {
		return (tie(l, r) < tie(dd.l, dd.r));
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll m = 9999;
		vector<d> arr;
		ll n;
		cin >> n;
		ll p = 0;
		vector<ll> ez(10000, 0);
		for (ll i = 0; i < n; i++) {
			ll l, r;
			cin >> l >> r;
			arr.push_back(d(l, r-1, i+1));
		}
		sort(arr.begin(), arr.end());
		vector<d> ans;
		ll last = 0;
		d la;
		for (auto& i : arr) {
			if (i.l <= last) {
				if (i.r >= la.r) {
					la = i;
				}
			} else {
				ans.push_back(la);
				last = la.r;
				if (last >= m) {
					break;
				}
				if (i.l > last+1) {
					p = 1;
				}
				la = i;
			}
		}
		if (last != m) {
			ans.push_back(la);
			last = la.r;
		}
		if ((last != m) || (ans.size() != n) || p) {
			cout << "Wrong Answer\n";
		} else {
			cout << "Accepted\n";
		}
	}
}
