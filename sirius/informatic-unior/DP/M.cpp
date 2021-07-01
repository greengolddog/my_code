#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, sum = 0;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		dp[i][i] = arr[i];
	}
	for (ll i = 2; i < n; i += 2) {
		for (ll j = 0; j < n-i; j++) {
			dp[j][j+i] = max(arr[j]+min(dp[j+2][j+i], dp[j+1][j+i-1]), arr[j+i]+min(dp[j+1][j+i-1], dp[j][j+i-2]));
		}
	}
	if (n % 2 == 1) {
		cout << dp[0][n-1];
	} else {
		cout << max(sum - dp[1][n-1], sum - dp[0][n-2]);
	}
}
