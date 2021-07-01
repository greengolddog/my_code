#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, a, ans = 0;
	cin >> n >> a;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	for (auto&[c, p] : arr) {
		if (c <= a) {
			a += p;
		} else {
			break;
		}
		ans++;
	}
	cout << ans;
}
