#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll n;
	while (cin >> n) {
		vector<ll> arr(n, 0), prefix(n+1, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			prefix[i+1] = prefix[i] + arr[i];
		}
		vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
		for (ll i = n-2; i >= 0; i--) {
			for (ll j = i+1; j < n; j++) {
				ll sum = prefix[j+1]-prefix[i];
				dp[i][j] = INF;
				for (ll k = i; k <= j; k++) {
					dp[i][j] = min(dp[i][j], (k == 0 ? 0 : dp[i][k-1])+dp[k+1][j]+sum-arr[k]);
				}
			}
		}
		cout << dp[0][n-1] << '\n';
	}
}
