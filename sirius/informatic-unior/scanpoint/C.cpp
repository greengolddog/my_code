#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll ans = 0;
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr;
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		arr.push_back({l, 0});
		arr.push_back({r, 1});
	}
	sort(arr.begin(), arr.end());
	ll cnt = 0;
	for (auto&[n, o] : arr) {
		if (o == 0) {
			if (cnt == 0) {
				ans -= n;
			}
			cnt++;
		}
		if (o == 1) {
			if (cnt == 1) {
				ans += n;
			}
			cnt--;
		}
	}
	cout << ans;
}
