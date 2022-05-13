#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const ll size = 4000000;
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	bitset<size> dp;
	dp[0] = 1;
	for (ll i = 0; i < n; i++) {
		dp = dp | (dp << arr[i]);
	}
	for (ll i = (sum + 1) / 2; i <= sum; i++) {
		if (dp[i]) {
			cout << i;
			return 0;
		}
	}
}
