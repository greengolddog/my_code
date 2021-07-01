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
	ll m;
	cin >> m;
	vector<d> arr;
	ll l, r;
	ll n = 0;
	cin >> l >> r;
	while (l != 0 || r != 0) {
		n++;
		arr.push_back(d(l, r, n));
		cin >> l >> r;
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
			if (i.l > last) {
				cout << "No solution";
				return 0;
			}
			la = i;
		}
	}
	if (last < m) {
		ans.push_back(la);
		last = la.r;
	}
	if (last < m) {
		cout << "No solution";
		return 0;
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) {
		cout << i.l << ' ' << i.r << '\n';
	}
}
