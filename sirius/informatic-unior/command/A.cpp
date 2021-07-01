#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	ll ans = 0;
	for (auto i : arr) {
		m -= i;
		ans++;
		if (m <= 0) {
			break;
		}
	}
	cout << ans;
}
