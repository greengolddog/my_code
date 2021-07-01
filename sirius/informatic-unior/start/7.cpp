#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> dp(n, 0);
	dp[0] = arr[0];
	for (ll i = 1; i < min(n, m+1); i++) {
		dp[i] = max(arr[i], dp[i-1]);
	}
	for (ll i = m+1; i < n; i++) {
		dp[i] = max(arr[i]+dp[i-m-1], dp[i-1]);
	}
	cout << dp[n-1];
}
