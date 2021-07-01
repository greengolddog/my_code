#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll to_second(ll h, ll m, ll s) {
	return h*3600+m*60+s;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll ans = 0;
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr;
	for (ll i = 0; i < n; i++) {
		ll lc, lm, l, rc, rm, r;
		cin >> lc >> lm >> l >> rc >> rm >> r;
		if (to_second(lc, lm, l) == to_second(rc, rm, r)) {
			arr.push_back({0, 0});
			arr.push_back({to_second(24, 0, 0), 2});
		} else {
			if (to_second(lc, lm, l) > to_second(rc, rm, r)) {
				arr.push_back({0, 0});
				arr.push_back({to_second(24, 0, 0), 2});
			}
			arr.push_back({to_second(lc, lm, l), 0});
			arr.push_back({to_second(rc, rm, r), 2});
		}
	}
	sort(arr.begin(), arr.end());
	ll cnt = 0;
	for (auto&[_, o] : arr) {
		if (o == 0) {
			cnt++;
			if (cnt == n) {
				ans -= _;
			}
		}
		if (o == 2) {
			if (cnt == n) {
				ans += _;
			}
			cnt--;
		}
	}
	cout << ans;
}
