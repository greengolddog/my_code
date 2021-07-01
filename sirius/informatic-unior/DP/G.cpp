#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MAXN = 1000000000000;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string arr1, arr2;
	cin >> arr1 >> arr2;
	ll n = arr1.size(), m = arr2.size();
	vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
	for (ll i = 0; i <= m; i++) {
		dp[0][i] = i;
	}
	for (ll i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (arr1[i-1] == arr2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i][j-1] + 1, dp[i-1][j] + 1));
			}
		}
	}
	cout << dp[n][m];
}
